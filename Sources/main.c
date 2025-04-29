#include "../Headers/main.h"
int main(void)
{

	InitConfig();
	InitAssets();
	ApplyTheme();
	InitLogoScreen(logoTexture);
	InitUserManagementScreen(userManagementTexture);

    while (!WindowShouldClose()) {
		switchUpdate();


        BeginDrawing();
        switchDraw();
        EndDrawing();
    }
    UnloadAssets();
	CloseWindow();
    return 0;
}
