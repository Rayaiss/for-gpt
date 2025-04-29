#include "../../Headers/Core/config.h"

int screenWidth = 0;
int screenHeight = 0;

void InitConfig(void)
{
    screenWidth = GetMonitorWidth(0);
    screenHeight = GetMonitorHeight(0);
    SetConfigFlags(FLAG_FULLSCREEN_MODE | FLAG_VSYNC_HINT); //pas sure
    InitWindow(screenWidth, screenHeight, "Words Game");
    SetTargetFPS(60);
}


