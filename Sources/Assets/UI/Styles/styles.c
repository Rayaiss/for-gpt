#include "../../../../Headers/Assets/Styles/styles.h"

// Fonction pour appliquer un style arrondi et moderne

void ApplyTheme(void) {
    GuiSetStyle(DEFAULT, TEXT_SIZE, 20);
    GuiSetStyle(DEFAULT, TEXT_SPACING, 4);
    GuiSetStyle(DEFAULT, TEXT_LINE_SPACING, 20);
    GuiSetStyle(DEFAULT, BASE_COLOR_NORMAL, 0x8EC0E4FF);
    GuiSetStyle(DEFAULT, BORDER_WIDTH, 2);

    // Boutons
    GuiSetStyle(BUTTON, BORDER_WIDTH, 2);
    GuiSetStyle(BUTTON, BORDER_COLOR_NORMAL, 0x5B5F97FF);
    GuiSetStyle(BUTTON, BASE_COLOR_NORMAL, 0x8EC0E4FF);
    GuiSetStyle(BUTTON, BASE_COLOR_FOCUSED, 0x7EA9CEFF);
    GuiSetStyle(BUTTON, BASE_COLOR_PRESSED, 0x6C94BFFF);
    GuiSetStyle(BUTTON, TEXT_COLOR_NORMAL, 0xFFFFFFFF);

    // TextBox
    GuiSetStyle(TEXTBOX, BORDER_WIDTH, 2);
    GuiSetStyle(TEXTBOX, BORDER_COLOR_NORMAL, 0x5B5F97FF);
    GuiSetStyle(TEXTBOX, BASE_COLOR_NORMAL, 0xFFFFFFFF);
    GuiSetStyle(TEXTBOX, TEXT_COLOR_NORMAL, 0x333333FF);

    // Font
    GuiSetFont(mainFont);
}
