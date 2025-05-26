#include <stdio.h>
#include <stdlib.h>

#define PASSWORD 2025
#define MAX_TRIES 3

// 清除螢幕函式
void clear_screen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// 顯示個人風格畫面
void show_intro_screen() {
    clear_screen();
    printf("=============================================\n");
    for (int i = 0; i < 20; i++) {
        printf("*    Welcome to [Your Name]'s Grade System   *\n");
    }
    printf("=============================================\n");
}

// 密碼驗證函式
int verify_password() {
    int input, tries = 0;

    while (tries < MAX_TRIES) {
        printf("Please enter the 4-digit password: ");
        scanf("%d", &input);

        if (input == PASSWORD) {
            printf("Correct password! Access granted.\n");
            return 1;
        } else {
            printf("Incorrect password. Please try again.\n");
            tries++;
        }
    }

    printf("Too many failed attempts. System locked.\n");
    return 0;
}

// 顯示主選單
void show_menu() {
    clear_screen();
    printf("------------[Grade System]-------------\n");
    printf("| a. Enter student grades             |\n");
    printf("| b. Display student grades           |\n");
    printf("| c. Search for student grades        |\n");
    printf("| d. Grade ranking                    |\n");
    printf("| e. Exit system                      |\n");
    printf("---------------------------------------\n");
}

// 主程式
int main() {
    show_intro_screen();

    if (!verify_password()) {
        return 0;
    }

    show_menu();

    char choice;
    printf("Select an option: ");
    scanf(" %c", &choice);  // 等待使用者輸入選項

    printf("You selected option: %c\n", choice);
    // 接下來可以根據選項進入下一題的功能

    return 0;
}



