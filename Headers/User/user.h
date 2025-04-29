#ifndef USER_H
#define USER_H

#include <stdbool.h>


#define MAX_NAME_LENGTH 64
#define MAX_AGE_LENGTH 4
#define MAX_USERS 4
#define USER_PATH "Assets/Databses/users.txt"

typedef struct {
    char firstname[MAX_NAME_LENGTH];
    char lastname[MAX_NAME_LENGTH];
	int highscore;
    int age;
    bool isActive;
} User;

extern User user[MAX_USERS];
extern int userCount;


void createUsers(const char* filename);
void loadUsers(const char* filename);

#endif // USER_H
