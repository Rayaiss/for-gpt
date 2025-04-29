#ifndef SCENE_H
#define SCENE_H

#include "logoScene.h"
#include "usermanagementScreen.h"
#include "../Assets/Init/assets.h"

typedef enum GameScene {
    LOGO,            // Écran de logo
    USERMANAGEMENT,  // Gestion des utilisateurs
    MAINMENU,        // Menu principal
    GAMEPLAY         // Jeu en cours
} GameScreen;

extern GameScreen currentScreen;

void switchScreen(GameScreen newScreen);
void switchUpdate();  // Pour mettre à jour l'état de l'écran courant
void switchDraw();    // Pour dessiner l'écran courant

#endif // SCENE_H
