#ifndef LOGOSCREEN_H
#define LOGOSCREEN_H

#include "raylib.h"
#include "../Core/config.h"
#include "../Core/graphics.h"
#include "../Assets/Init/assets.h"
#include "Scenes.h"

void InitLogoScreen(Texture2D texture);
void UpdateLogoScreen(void);
void DrawLogoScreen(void);

#endif // LOGOSCREEN_H
