#include "../../../../Headers/Assets/UI/Box/box_logic.h"


static float messageTimer = 0.0f;
static char message[64] = {0};
static Color messageColor = GREEN;

bool IsAlphaOnly(const char *str) {
    for (int i = 0; str[i]; i++) {
        if (!isalpha(str[i])) return false;
    }
    return true;
}

bool IsDigitsOnly(const char *str) {
    for (int i = 0; str[i]; i++) {
        if (!isdigit(str[i])) return false;
    }
    return true;
}

void ShowMessage(const char *text, Color color) {
    strncpy(message, text, sizeof(message));
    messageColor = color;
    messageTimer = 2.5f; // affiché pendant 2.5 secondes
}

void DrawBoxMessage(void) {
    if (messageTimer > 0.0f) {
        messageTimer -= GetFrameTime();
        int textWidth = MeasureText(message, 20);
        DrawText(message, GetScreenWidth()/2 - textWidth/2, GetScreenHeight() - 80, 20, messageColor);
    }
}

void ProcessValidatedUser(Box *box, const char *savePath)
{
    if (!box || !box->validateClicked) return;
    box->validateClicked = false;

    // --- Validation ---
    if (box->type == BOX_CREATE) {
        if (userCount >= MAX_USERS) { ShowMessage("User list full!", RED); return; }

        if (!IsAlphaOnly(box->firstname) || strlen(box->firstname) < 2) { ShowMessage("Invalid Firstname", RED); return; }
        if (!IsAlphaOnly(box->lastname) || strlen(box->lastname) < 2) { ShowMessage("Invalid Lastname", RED); return; }
        if (!IsDigitsOnly(box->age)) { ShowMessage("Age must be numeric", RED); return; }

        int age = atoi(box->age);
        if (age <= 0 || age > 120) { ShowMessage("Invalid Age", RED); return; }

        User newUser = {0};
        strncpy(newUser.firstname, box->firstname, MAX_NAME_LENGTH);
        strncpy(newUser.lastname, box->lastname, MAX_NAME_LENGTH);
        newUser.age = age;
        newUser.highscore = 0;
        newUser.isActive = true;

        user[userCount++] = newUser;
        createUsers(savePath);

        ShowMessage("User created successfully!", GREEN);
    }

    else if (box->type == BOX_DELETE) {
        bool found = false;
        for (int i = 0; i < userCount; i++) {
            if (strcmp(user[i].lastname, box->lastname) == 0) {
                for (int j = i; j < userCount - 1; j++) {
                    user[j] = user[j + 1];
                }
                userCount--;
                found = true;
                break;
            }
        }

        if (found) {
            createUsers(savePath);
            ShowMessage("User deleted.", ORANGE);
        } else {
            ShowMessage("User not found.", RED);
        }
    }

    else if (box->type == BOX_LOGIN) {
        bool found = false;
        for (int i = 0; i < userCount; i++) {
            if (strcmp(user[i].lastname, box->lastname) == 0) {
                found = true;
                break;
            }
        }

        if (found) {
            ShowMessage("Login successful!", GREEN);
        } else {
            ShowMessage("User not found.", RED);
        }
    }

    box->active = false;
}
