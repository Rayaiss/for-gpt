#include "../../Headers/Scenes/Scenes.h"

GameScreen currentScreen = LOGO; // Initialisation � l'�cran LOGO

//change screen
void switchScreen(GameScreen newScreen)
{
    currentScreen = newScreen;
}

// Fonction pour mettre � jour l'�tat de l'�cran courant
void switchUpdate()
{
    switch (currentScreen)
    {
        case LOGO:
            UpdateLogoScreen();// Mettre � jour l'�cran du logo
            break;
        case USERMANAGEMENT:
            UpdateUserManagementScreen();  // Mettre � jour la gestion des utilisateurs
            break;/*
        case MAINMENU:
            UpdateMainMenu();  // Mettre � jour le menu principal
            break;
        case GAMEPLAY:
            UpdateGameplay();  // Mettre � jour le gameplay
            break;*/
        default:
            break;
    }
}

// Fonction pour dessiner l'�cran courant
void switchDraw()
{
    switch (currentScreen)
    {
        case LOGO:
            DrawLogoScreen();  // Dessiner l'�cran du logo
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
