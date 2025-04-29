#include "../../Headers/User/user.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

User user[MAX_USERS];
int userCount = 0;

// createUsers
void createUsers(const char* filename) {
    FILE* file = fopen(filename, "wb");
    if (file == NULL) return;

    for (int i = 0; i < userCount; i++) {
        fwrite(&user[i], sizeof(User), 1, file);
    }
    fclose(file);
}

void loadUsers(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) return;

    userCount = 0;
    while (fread(&user[userCount], sizeof(User), 1, file) == 1 && userCount < MAX_USERS) {
        userCount++;
    }
    fclose(file);
}
