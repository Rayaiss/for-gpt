#include "../../../Headers/Assets/List/userList.h"

void DrawUsersList()
{
    float screenWidth = GetScreenWidth();
    float screenHeight = GetScreenHeight();

    float marginTop = 400;
    float marginBottom = 100; // Espace réservé aux boutons
    float availableHeight = screenHeight - marginTop - marginBottom;

    int spacing = 10;
    int visibleUsers = userCount;

    // Ajuste la hauteur des boîtes en fonction du nombre d'utilisateurs
    float boxHeight = 80;
    float totalRequiredHeight = userCount * boxHeight + (userCount - 1) * spacing;

    // Si ça dépasse, réduit la hauteur des boîtes
    if (totalRequiredHeight > availableHeight) {
        boxHeight = (availableHeight - (userCount - 1) * spacing) / userCount;
    }

    float boxWidth = 400;
    float x = (screenWidth - boxWidth) / 2;
    float y = marginTop;

	if (userCount == 0) {
    DrawText("No users found.", x + 20, marginTop + 20, 20, RED);
    return;
	}
    for (int i = 0; i < userCount; i++) {
        Color boxColor = user[i].highscore >= 100 ? GREEN : DARKGRAY;
		DrawRectangleRounded((Rectangle){x, y, boxWidth, boxHeight}, 0.2f, 10, boxColor);


        DrawText(TextFormat("Firstname: %s", user[i].firstname), x + 10, y + 10, 18, WHITE);
        DrawText(TextFormat("Age: %d", user[i].age), x + 10, y + 30, 18, LIGHTGRAY);
        DrawText(TextFormat("High Score: %d", user[i].highscore), x + 10, y + 50, 18, GOLD);

        y += boxHeight + spacing;
    }
}
