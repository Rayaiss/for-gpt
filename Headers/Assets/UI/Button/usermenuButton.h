#ifndef USERMENUBUTTON_H
#define USERMENUBUTTON_H

#include "raylib.h"
#include "button.h"
#include "string.h"
#include "../../Init/assets.h"
#include "../Box/box.h"
#include "../Box/box_logic.h"

typedef struct {
    ButtonManager manager;
    Button buttons[MAX_BUTTONS];
} UserMenuButton;

extern UserMenuButton usermenu;

void InitUserMenuButton(UserMenuButton *menu);
void UpdateUserMenuButton(UserMenuButton *menu);
void DrawUserMenuButton(UserMenuButton *menu);

#endif // USERMENUBUTTON_H
