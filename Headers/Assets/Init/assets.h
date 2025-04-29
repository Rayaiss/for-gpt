#ifndef ASSETS_H
#define ASSETS_H

#include "raylib.h"
#include "stddef.h"

//Font
#define FONT_PATH "Assets/Fonts/Mydnite-R9Lde.otf"

//Music
#define MUSIC_USERMENU_PATH "Assets/Musics/userSceneOST.ogg"
#define MUSIC_MAINMENU_PATH "Assets/Musics/menuOST.ogg"
#define MUSIC_LEVEL_PATH "Assets/Musics/levelOST.ogg"

//Sound
#define SOUND_CLICK_PATH "Assets/Sounds/click.wav"
#define SOUND_SUCCESS_PATH "Assets/Sounds/success.wav"
#define SOUND_ERROR_PATH "Assets/Sounds/error.wav"

//Logo
#define LOGO_PATH "Assets/Images/WordsGameLogo.png"

//Background
#define BACKGROUND_PATH "Assets/Images/Background.png"
#define USERMANAGEMENT_PATH "Assets/Images/userManagement.png"

// === Fonts ===
extern Font mainFont;

// === Musiques ===
extern Music userMenuMusic;
extern Music menuMusic;
extern Music gameMusic;

// === Sons ===
extern Sound clickSound;
extern Sound successSound;
extern Sound errorSound;

// === Images ===
extern Texture2D logoTexture;
extern Texture2D userManagementTexture;
extern Texture2D backgroundTexture;

// === Fonctions ===
void InitAssets(void);
void UnloadAssets(void);

#endif
