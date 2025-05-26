#include <stdio.h>
#include <stdlib.h>

#define PASSWORD 2025
#define MAX_TRIES 3

// �M���ù��禡
void clear_screen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// ��ܭӤH����e��
void show_intro_screen() {
    clear_screen();
    printf("=============================================\n");
    for (int i = 0; i < 20; i++) {
        printf("*    Welcome to [Your Name]'s Grade System   *\n");
    }
    printf("=============================================\n");
}

// �K�X���Ҩ禡
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

// ��ܥD���
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

// �D�{��
int main() {
    show_intro_screen();

    if (!verify_password()) {
        return 0;
    }

    show_menu();

    char choice;
    printf("Select an option: ");
    scanf(" %c", &choice);  // ���ݨϥΪ̿�J�ﶵ

    printf("You selected option: %c\n", choice);
    // ���U�ӥi�H�ھڿﶵ�i�J�U�@�D���\��

    return 0;
}



