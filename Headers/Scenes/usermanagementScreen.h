#ifndef USERMANAGEMENT_H
#define USERMANAGEMENT_H

#include "raygui.h"
#include "raylib.h"
#include "../Assets/Init/assets.h"
#include "../Assets/UI/Button/usermenuButton.h"
#include "../Assets/List/userList.h"
#include "Scenes.h"
#include "../Core/config.h"
#include "../User/user.h"
#include "string.h"

void InitUserManagementScreen();
void UpdateUserManagementScreen();
void DrawUserManagementScreen();

#endif // USERMANAGEMENT_H
