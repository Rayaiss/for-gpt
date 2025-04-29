#ifndef BOX_H
#define BOX_H

#include "raylib.h"
#include "raygui.h"
#include <string.h>
#include "../../Init/assets.h"
#include "../../Styles/styles.h"
typedef enum {
    BOX_NONE,
    BOX_CREATE,
    BOX_DELETE,
    BOX_LOGIN
} BoxType;

typedef struct {
    BoxType type;
    bool active;

    char firstname[32];
    char lastname[32];
    char age[3];
	bool cancelClicked;
	bool validateClicked;

    Rectangle bounds;
} Box;

bool DrawRoundedButtonUser(Rectangle bounds, const char *text, float roundness, int segments, Color color);
void InitBox(Box *box, BoxType type);
void UpdateBox(Box *box);
void DrawBox(Box *box);

#endif // BOX_H



