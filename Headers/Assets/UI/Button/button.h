#ifndef BUTTON_H
#define BUTTON_H

#define MAX_BUTTONS 10

#include "raygui.h"
#include "raylib.h"
#include "../../Init/assets.h"

// Structure de bouton
typedef struct Button {
    Rectangle bounds;
    const char *textEnabled;
    const char *textDisabled;
    Texture2D icon;
    Color baseColor;
    bool enabled;
    bool showMessageBox;
    float disabledAlpha;
    float disabledAlphaSpeed;
    float pulseScale;
    Sound clickSound;
} Button;

// Orientation des boutons
typedef enum {
    LAYOUT_VERTICAL,
    LAYOUT_HORIZONTAL
} ButtonLayout;

// Manager de plusieurs boutons
typedef struct {
    Button buttons[MAX_BUTTONS];
    int buttonCount;
    Rectangle area;
    float spacing;
    ButtonLayout layout;
    Vector2 startPos; // Important pour la disposition automatique
} ButtonManager;

// Fonctions
void LayoutButtons(ButtonManager *manager);
void UpdateButtonManager(ButtonManager *manager);

bool UpdateButton(Button *btn);

void AddButton(ButtonManager *manager, const char *textEnabled, const char *textDisabled,
               Texture2D icon, Color color, bool showMessageBox,
               Vector2 sizeofbutton, Sound clickSound);

void DrawButtonIconAndText(Button *btn, Rectangle drawBounds);

#endif // BUTTON_H

