#include "../../../../Headers/Assets/UI/Box/box.h"

static bool isDragging = false;
static Vector2 dragOffset = { 0 };

bool DrawRoundedButtonUser(Rectangle bounds, const char *text, float roundness, int segments, Color color) {
    DrawRectangleRounded(bounds, roundness, segments, color);
    DrawText(text, bounds.x + 10, bounds.y + 5, 20, WHITE);

    if (CheckCollisionPointRec(GetMousePosition(), bounds) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        PlaySound(clickSound);
        return true;
    }
    return false;
}



void InitBox(Box *box, BoxType type)
{
    box->type = type;
    box->active = true;
    memset(box->firstname, 0, sizeof(box->firstname));
    memset(box->lastname, 0, sizeof(box->lastname));
    memset(box->age, 0, sizeof(box->age));
    box->bounds = (Rectangle){ GetScreenWidth() / 2 - 200, GetScreenHeight() / 2 - 150, 400, 300 };
    box->validateClicked = false;
	box->cancelClicked = false;
}

void UpdateBox(Box *box)
{
	// Barre supérieure draggable
    Rectangle topBar = (Rectangle){ box->bounds.x, box->bounds.y, box->bounds.width, 40 };

    if (CheckCollisionPointRec(GetMousePosition(), topBar)) {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            isDragging = true;
            Vector2 mouse = GetMousePosition();
			dragOffset = (Vector2){ mouse.x - box->bounds.x, mouse.y - box->bounds.y };
        }
    }

    if (isDragging) {
        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
            Vector2 mouse = GetMousePosition();
            box->bounds.x = mouse.x - dragOffset.x;
            box->bounds.y = mouse.y - dragOffset.y;
        } else {
            isDragging = false;
        }
    }

	// Boutons en bas
	Rectangle btnCancel = { box->bounds.x + 20, box->bounds.y + box->bounds.height - 50, 120, 30 };
	Rectangle btnValidate = { box->bounds.x + box->bounds.width - 140, box->bounds.y + box->bounds.height - 50, 120, 30 };

	if (DrawRoundedButtonUser(btnCancel, "Cancel", 0.5f, 20, DARKGRAY)) {
		box->active = false;
		box->cancelClicked = true;
	}
	if (DrawRoundedButtonUser(btnValidate, "Validate", 0.5f, 20, DARKGREEN)) {
		box->validateClicked = true;
	}

    if (!box->active) return;

    int fieldY = box->bounds.y + 50;

    // Firstname
    GuiLabel((Rectangle){ box->bounds.x + 20, fieldY, 100, 30 }, "Lastname:");
    GuiTextBox((Rectangle){ box->bounds.x + 130, fieldY, 200, 30 }, box->firstname, sizeof(box->firstname), true);
    fieldY += 40;

    if (box->type == BOX_CREATE) {
        // Lastname
        GuiLabel((Rectangle){ box->bounds.x + 20, fieldY, 100, 30 }, "Firstname:");
        GuiTextBox((Rectangle){ box->bounds.x + 130, fieldY, 200, 30 }, box->lastname, sizeof(box->lastname), true);
        fieldY += 40;

        // Age
        GuiLabel((Rectangle){ box->bounds.x + 20, fieldY, 100, 30 }, "Age:");
        GuiTextBox((Rectangle){ box->bounds.x + 130, fieldY, 200, 30 }, box->age, sizeof(box->age), true);
    }
}

void DrawBox(Box *box)
{
    if (!box->active) return;
	 // Dessine la boîte avec fond arrondi
    DrawRectangleRounded(box->bounds, 0.2f, 20, GREEN);

    // Dessine la barre de titre
    DrawRectangleRec((Rectangle){ box->bounds.x, box->bounds.y, box->bounds.width, 40 }, DARKGREEN);
    DrawText("USER BOX", box->bounds.x + 20, box->bounds.y + 10, 20, WHITE);

	UpdateBox(box);
}
