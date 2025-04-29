#include "../../Headers/Scenes/logoScene.h"

static Vector2 textureSize = {0};
static Rectangle destRec = {0};
static float elapsedTime = 0.0f;
static float displayTime = 3.0f;
static bool skipRequested = false;
static float progress = 0.0f;

static void UpdateLogoScaling()
{
    destRec = GetScaledCenteredRect(textureSize);
}

void InitLogoScreen(Texture2D texture)
{
    logoTexture = texture;
    textureSize = (Vector2){texture.width, texture.height};
    UpdateLogoScaling();
    skipRequested = false;
    elapsedTime = -2.0f;
}

void UpdateLogoScreen()
{
    if (IsWindowResized()) {
        UpdateLogoScaling();
    }
    elapsedTime += GetFrameTime();
    progress = elapsedTime / displayTime;

    // V�rifier si la touche ENTER est press�e ou si le logo a �t� affich� pendant le temps sp�cifi�
    if ((IsKeyPressed(KEY_ENTER) && elapsedTime > 1.0f) || progress >= 1.0f) {
        skipRequested = true;
        currentScreen = USERMANAGEMENT;  // Changer d'�cran
        PlayMusicStream(userMenuMusic);
        elapsedTime = 0.0f;  // R�initialiser le temps pour la prochaine sc�ne
    }
}

void DrawLogoScreen()
{
    ClearBackground(BLACK);

    // Dessiner le logo redimensionn� et centr�

    DrawTexturePro(logoTexture,
        (Rectangle){0, 0, textureSize.x, textureSize.y},
        destRec,
        (Vector2){0, 0},
        0.0f,
        WHITE);

   // Barre de progression (optionnelle)
    if (elapsedTime < displayTime) {
        progress = elapsedTime / displayTime;
        DrawRectangle(0, GetScreenHeight() - 5,
                     (int)(GetScreenWidth() * progress), 5, BLUE);
    }

    // Message "Press ENTER to continue" (optionnel)
    if (elapsedTime > 1.0f && !skipRequested) {  // Apr�s 1 seconde
        const char *continueMessage = "Press ENTER to continue";
        Vector2 vec = {GetScreenWidth()/2 - MeasureText(continueMessage, 20)/2,
        GetScreenHeight() - 40};
        DrawTextEx(mainFont, continueMessage, vec, 30, 0, LIGHTGRAY);
    }
}
