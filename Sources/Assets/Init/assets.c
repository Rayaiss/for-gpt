#include "../../../Headers/Assets/Init/assets.h"

// === Définition des variables ===
Font mainFont;

Music userMenuMusic;
Music menuMusic;
Music gameMusic;

Sound clickSound;
Sound successSound;
Sound errorSound;

Texture2D logoTexture;
Texture2D userManagementTexture;
Texture2D backgroundTexture;

void InitAssets(void)
{
    // === Audio ===
    InitAudioDevice();

    // === Fonts ===
    mainFont = LoadFontEx(FONT_PATH, 24, NULL, 0);
    // === Musiques ===
	userMenuMusic = LoadMusicStream(MUSIC_USERMENU_PATH);
	menuMusic = LoadMusicStream(MUSIC_MAINMENU_PATH);
	gameMusic = LoadMusicStream(MUSIC_LEVEL_PATH);

    // === Sons ===
    clickSound = LoadSound(SOUND_CLICK_PATH);
    successSound = LoadSound(SOUND_SUCCESS_PATH);
    errorSound = LoadSound(SOUND_ERROR_PATH);

    // ===Textures ===
    Image logoImage = LoadImage(LOGO_PATH);
    logoTexture = LoadTextureFromImage(logoImage);
    UnloadImage(logoImage);

    Image backgroundImage = LoadImage(BACKGROUND_PATH);
    backgroundTexture = LoadTextureFromImage(backgroundImage);
    UnloadImage(backgroundImage);

    Image userManagementImage = LoadImage(USERMANAGEMENT_PATH);
    userManagementTexture= LoadTextureFromImage(userManagementImage);
    UnloadImage(userManagementImage);
}

void UnloadAssets(void)
{
    // === Décharger Fonts ===
    UnloadFont(mainFont);

    // === Décharger Musiques ===
    UnloadMusicStream(userMenuMusic);
    UnloadMusicStream(menuMusic);
    UnloadMusicStream(gameMusic);

    // === Décharger Sons ===
    UnloadSound(clickSound);
    UnloadSound(successSound);
    UnloadSound(errorSound);

    // === Décharger Images ===
    UnloadTexture(logoTexture);
    UnloadTexture(userManagementTexture);
    UnloadTexture(backgroundTexture);

    // === Fermer l'audio ===
    CloseAudioDevice();
}

