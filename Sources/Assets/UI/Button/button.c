#include "../../../../Headers/Assets/UI/Button/button.h"

void LayoutButtons(ButtonManager *manager)
{
    int availableSpace = (manager->layout == LAYOUT_VERTICAL) ? manager->area.height : manager->area.width;
    availableSpace -= (manager->buttonCount - 1) * manager->spacing;
    int buttonSize = availableSpace / manager->buttonCount;

    for (int i = 0; i < manager->buttonCount; i++) {
        if (manager->layout == LAYOUT_VERTICAL) {
            manager->buttons[i].bounds.x = manager->area.x;
            manager->buttons[i].bounds.y = manager->area.y + i * (buttonSize + manager->spacing);
            manager->buttons[i].bounds.width = manager->area.width;
            manager->buttons[i].bounds.height = buttonSize;
        } else {
            manager->buttons[i].bounds.x = manager->area.x + i * (buttonSize + manager->spacing);
            manager->buttons[i].bounds.y = manager->area.y;
            manager->buttons[i].bounds.width = buttonSize;
            manager->buttons[i].bounds.height = manager->area.height;
        }
    }
}

void UpdateButtonManager(ButtonManager *manager)
{
    for (int i = 0; i < manager->buttonCount; i++) {
        UpdateButton(&manager->buttons[i]);
    }
}

void AddButton(ButtonManager *manager, const char *textEnabled, const char *textDisabled,
               Texture2D icon, Color color, bool showMessageBox,
               Vector2 buttonSize , Sound clickSound)
{
    if (manager->buttonCount >= MAX_BUTTONS) return;

    Button *btn = &manager->buttons[manager->buttonCount];

    btn->bounds = (Rectangle){ manager->startPos.x, manager->startPos.y, buttonSize .x, buttonSize .y };
    btn->textEnabled = textEnabled;
    btn->textDisabled = textDisabled;
    btn->icon = icon;
    btn->baseColor = color;
    btn->enabled = true;
    btn->showMessageBox = showMessageBox;
    btn->disabledAlpha = 255.0f;
    btn->disabledAlphaSpeed = 2.0f;
    btn->pulseScale = 1.05f;
    btn->clickSound = clickSound;

    if (manager->layout == LAYOUT_VERTICAL)
        manager->startPos.y += buttonSize .y + manager->spacing;
    else
        manager->startPos.x += buttonSize .x + manager->spacing;

    manager->buttonCount++;
}

bool UpdateButton(Button *btn)
{
    static bool showMsgBox = false;
    static int msgBoxResult = -1;

    // Alpha animation
    if (!btn->enabled) {
        btn->disabledAlpha -= btn->disabledAlphaSpeed * GetFrameTime() * 255;
        if (btn->disabledAlpha < 100.0f) btn->disabledAlpha = 100.0f;
    } else {
        btn->disabledAlpha += btn->disabledAlphaSpeed * GetFrameTime() * 255;
        if (btn->disabledAlpha > 255.0f) btn->disabledAlpha = 255.0f;
    }

    Color currentColor = btn->baseColor;
    if (!btn->enabled) currentColor.a = (unsigned char)btn->disabledAlpha;

    // Pulse effect
    Rectangle drawBounds = btn->bounds;
    if (CheckCollisionPointRec(GetMousePosition(), btn->bounds) && btn->enabled) {
        drawBounds.x -= (drawBounds.width * (btn->pulseScale - 1.0f)) / 2;
        drawBounds.y -= (drawBounds.height * (btn->pulseScale - 1.0f)) / 2;
        drawBounds.width *= btn->pulseScale;
        drawBounds.height *= btn->pulseScale;
    }

    bool clicked = false;

    // On dessine manuellement notre bouton arrondi
    float roundness = 0.5f; // 50% arrondi (bulle)
    int segments = 20;      // douceur des arrondis
    DrawRectangleRounded(drawBounds, roundness, segments, currentColor);

    // Vérifie clic souris
    if (CheckCollisionPointRec(GetMousePosition(), btn->bounds) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && btn->enabled ) {
        clicked = true;
        PlaySound(btn->clickSound);
        if (btn->showMessageBox)
            showMsgBox = true;
    }

    // Dessine l'icône et le texte par-dessus
    DrawButtonIconAndText(btn, drawBounds);



    return clicked;
}

void DrawButtonIconAndText(Button *btn, Rectangle drawBounds)
{
    const char *text = btn->enabled ? btn->textEnabled : btn->textDisabled;

    int iconSize = (int)(drawBounds.height * 0.6f);
    int padding = 8;
    Vector2 iconPos = {
        drawBounds.x + padding,
        drawBounds.y + (drawBounds.height - iconSize) / 2
    };
    Vector2 textPos = {
        iconPos.x + iconSize + padding,
        drawBounds.y + (drawBounds.height - mainFont.baseSize) / 2
    };

    // Dessine icône
    DrawTexturePro(btn->icon,
        (Rectangle){ 0, 0, (float)btn->icon.width, (float)btn->icon.height },
        (Rectangle){ iconPos.x, iconPos.y, iconSize, iconSize },
        (Vector2){ 0, 0 }, 0.0f, WHITE);

    // Dessine texte
    DrawTextEx(mainFont, text, textPos, mainFont.baseSize, 2, WHITE);
}
