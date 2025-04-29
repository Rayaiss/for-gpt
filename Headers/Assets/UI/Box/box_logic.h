#ifndef BOX_LOGIC_H
#define BOX_LOGIC_H

#include "../../../User/user.h"
#include "raylib.h"
#include "box.h"
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void ProcessValidatedUser(Box *box, const char *savePath);
void DrawBoxMessage(void);

#endif // BOX_LOGIC_H
