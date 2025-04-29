#include "../../Headers/Scenes/usermanagementScreen.h"

static bool userActionRequested = false;
static Vector2 textureSize = {0};
static Rectangle destRec = {0};
Box box;

static void UpdateUserManagementScaling()
{
    destRec = GetScaledCenteredRect(textureSize);
}



void InitUserManagementScreen(Texture2D texture) {
	backgroundTexture = texture;
    textureSize = (Vector2){texture.width, texture.height};
    destRec = GetScaledCenteredRect(textureSize);
    InitUserMenuButton (&usermenu);
    userActionRequested = false;
    memset(&box, 0, sizeof(Box));
    loadUsers(USER_PATH);
}


void UpdateUserManagementScreen() {
    UpdateMusicStream(userMenuMusic);

	if (IsWindowResized()) {
        UpdateUserManagementScaling();
    }
    UpdateUserMenuButton(&usermenu);
    ProcessValidatedUser(&box, USER_PATH);
    /*if (IsKeyPressed(KEY_ENTER)) {
        userActionRequested = true;

        currentScreen = MAINMENU;
    }*/
}


void DrawUserManagementScreen() {
    ClearBackground(BLACK);

    DrawTexturePro(backgroundTexture,
        (Rectangle){0, 0, textureSize.x, textureSize.y},
        destRec,
        (Vector2){0, 0},
        0.0f,
        WHITE);
    DrawUserMenuButton(&usermenu);
    DrawUsersList();
    DrawBox(&box);
    DrawBoxMessage();
}


