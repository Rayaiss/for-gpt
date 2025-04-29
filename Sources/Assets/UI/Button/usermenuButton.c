#include "../../../../Headers/Assets/UI/Button/usermenuButton.h"
Box userBox;
UserMenuButton usermenu;

void InitUserMenuButton(UserMenuButton *menu)
{
	//Copie des éléments de menu->buttons dans menu->manager.buttons
    memcpy(menu->manager.buttons, menu->buttons, sizeof(menu->buttons));
    menu->manager.buttonCount = 0;
    menu->manager.area = (Rectangle){ (GetScreenWidth() - 800) / 2.0f, GetScreenHeight() - 120, 800, 100 }; // Horizontal
    menu->manager.spacing = 15;
    menu->manager.layout = LAYOUT_HORIZONTAL;

    AddButton(&menu->manager, "Create User", "Disabled", (Texture2D){0}, BLUE, true, (Vector2){140, 60}, clickSound);
    AddButton(&menu->manager, "Delete User", "Disabled", (Texture2D){0}, CLITERAL(Color){ 135, 60, 190, 255 }, true, (Vector2){140, 60}, clickSound);
    AddButton(&menu->manager, "Login", "Disabled", (Texture2D){0}, GREEN, true, (Vector2){140, 60}, clickSound);
    AddButton(&menu->manager, "Exit", "Disabled", (Texture2D){0}, RED, true, (Vector2){140, 60}, clickSound);
    LayoutButtons(&menu->manager);
}

void UpdateUserMenuButton(UserMenuButton *menu)
{
    UpdateButtonManager(&menu->manager);
    for (int i = 0; i < menu->manager.buttonCount; i++) {
        if (UpdateButton(&menu->manager.buttons[i])) {
            if (i == 0) InitBox(&userBox, BOX_CREATE);
            else if (i == 1) InitBox(&userBox, BOX_DELETE);
            else if (i == 2) InitBox(&userBox, BOX_LOGIN);
            else if (i == 3) CloseWindow();
            }
    }
}

void DrawUserMenuButton(UserMenuButton *menu)
{
    for (int i = 0; i < menu->manager.buttonCount; i++) {
        UpdateButton(&menu->manager.buttons[i]);
    }
    DrawBox(&userBox);
}

