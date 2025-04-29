#include "../../Headers/Scenes/Scenes.h"

GameScreen currentScreen = LOGO; // Initialisation à l'écran LOGO

//change screen
void switchScreen(GameScreen newScreen)
{
    currentScreen = newScreen;
}

// Fonction pour mettre à jour l'état de l'écran courant
void switchUpdate()
{
    switch (currentScreen)
    {
        case LOGO:
            UpdateLogoScreen();// Mettre à jour l'écran du logo
            break;
        case USERMANAGEMENT:
            UpdateUserManagementScreen();  // Mettre à jour la gestion des utilisateurs
            break;/*
        case MAINMENU:
            UpdateMainMenu();  // Mettre à jour le menu principal
            break;
        case GAMEPLAY:
            UpdateGameplay();  // Mettre à jour le gameplay
            break;*/
        default:
            break;
    }
}

// Fonction pour dessiner l'écran courant
void switchDraw()
{
    switch (currentScreen)
    {
        case LOGO:
            DrawLogoScreen();  // Dessiner l'écran du logo
            break;
        case USERMANAGEMENT:
            DrawUserManagementScreen();  // Dessiner la gestion des utilisateurs
            break;/*
        case MAINMENU:
            DrawMainMenu();  // Dessiner le menu principal
            break;
        case GAMEPLAY:
            DrawGameplay();  // Dessiner le gameplay
            break;
       */default:
            break;
    }
}
