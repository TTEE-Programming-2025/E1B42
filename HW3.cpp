#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define PASSWORD "2025"
#define ROWS 9
#define COLS 9

char seats[ROWS][COLS];

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void pauseAndReturn() {
    printf("Press Enter to return to menu...");
    getchar();
    clearScreen();
}

void initSeats() {
    memset(seats, '-', sizeof(seats));
    srand(time(NULL));
    int count = 0;
    while (count < 10) {
        int r = rand() % ROWS;
        int c = rand() % COLS;
        if (seats[r][c] == '-') {
            seats[r][c] = '*';
            count++;
        }
    }
}

void displaySeats() {
    printf(" \\123456789\n");
    for (int i = ROWS - 1; i >= 0; i--) {
        printf("%d", i + 1);
        for (int j = 0; j < COLS; j++) {
            printf("%c", seats[i][j]);
        }
        printf("\n");
    }
}

int isValid(int r, int c) {
    return r >= 0 && r < ROWS && c >= 0 && c < COLS && seats[r][c] == '-';
}

void showStyledScreen() {
    printf("========================================\n");
    printf("*                                      *\n");
    printf("*          WELCOME TO THE APP          *\n");
    printf("*                                      *\n");
    printf("*        Developed by [DO DO]          *\n");
    printf("*                                      *\n");
    printf("*        Secure Access Required        *\n");
    printf("*                                      *\n");
    printf("========================================\n");
    for (int i = 0; i < 12; i++) {
        printf("*        Personal Style Line %2d        *\n", i + 1);
    }
    printf("========================================\n");
}

void showMainMenu() {
    printf("----------[Booking System]----------\n");
    printf("| a. Available seats                |\n");
    printf("| b. Arrange for you                |\n");
    printf("| c. Choose by yourself             |\n");
    printf("| d. Exit                           |\n");
    printf("------------------------------------\n");
}

void handleOptionA() {
    displaySeats();
    pauseAndReturn();
}

void suggestSeats(int n) {
    int found = 0;
    for (int i = 0; i < ROWS && !found; i++) {
        for (int j = 0; j <= COLS - n; j++) {
            int ok = 1;
            for (int k = 0; k < n; k++) {
                if (seats[i][j + k] != '-') {
                    ok = 0;
                    break;
                }
            }
            if (ok) {
                for (int k = 0; k < n; k++) seats[i][j + k] = '@';
                found = 1;
                break;
            }
        }
    }
    if (!found && n == 4) {
        for (int i = 0; i < ROWS - 1 && !found; i++) {
            for (int j = 0; j < COLS; j++) {
                if (isValid(i, j) && isValid(i + 1, j) && isValid(i, j + 1) && isValid(i + 1, j + 1)) {
                    seats[i][j] = seats[i + 1][j] = seats[i][j + 1] = seats[i + 1][j + 1] = '@';
                    found = 1;
                    break;
                }
            }
        }
    }
    if (found) {
        displaySeats();
        printf("Do you accept these seats? (y/n): ");
        char ch;
        scanf(" %c", &ch); getchar();
        if (tolower(ch) == 'y') {
            for (int i = 0; i < ROWS; i++)
                for (int j = 0; j < COLS; j++)
                    if (seats[i][j] == '@') seats[i][j] = '*';
        } else {
            for (int i = 0; i < ROWS; i++)
                for (int j = 0; j < COLS; j++)
                    if (seats[i][j] == '@') seats[i][j] = '-';
        }
    } else {
        printf("No available suggestion.\n");
    }
    pauseAndReturn();
}

void handleOptionB() {
    int n;
    printf("How many seats (1-4) do you need? ");
    scanf("%d", &n); getchar();
    if (n < 1 || n > 4) {
        printf("Invalid number.\n");
        pauseAndReturn();
        return;
    }
    suggestSeats(n);
}

void handleOptionC() {
    char input[20];
    int r, c;
    while (1) {
        printf("Enter seat (row-col) or 'done': ");
        fgets(input, sizeof(input), stdin);
        if (strncmp(input, "done", 4) == 0) break;
        if (sscanf(input, "%d-%d", &r, &c) == 2 && r >= 1 && r <= 9 && c >= 1 && c <= 9) {
            if (seats[r - 1][c - 1] == '-') {
                seats[r - 1][c - 1] = '@';
            } else {
                printf("Seat already booked.\n");
            }
        } else {
            printf("Invalid input.\n");
        }
    }
    displaySeats();
    pauseAndReturn();
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            if (seats[i][j] == '@') seats[i][j] = '*';
}

void handleOptionD() {
    char ch;
    printf("Continue? (y/n): ");
    scanf(" %c", &ch); getchar();
    if (tolower(ch) == 'y') {
        clearScreen();
    } else if (tolower(ch) == 'n') {
        printf("Exiting program.\n");
        exit(0);
    } else {
        printf("Invalid input.\n");
        handleOptionD();
    }
}

int main() {
    char input[100];
    int attempts = 0;

    initSeats();
    showStyledScreen();

    while (attempts < 3) {
        printf("Enter 4-digit password: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, PASSWORD) == 0) {
            printf("\nAccess granted. Welcome!\n");
            clearScreen();
            while (1) {
                showMainMenu();
                printf("Choose option: ");
                fgets(input, sizeof(input), stdin);
                switch (tolower(input[0])) {
                    case 'a': handleOptionA(); break;
                    case 'b': handleOptionB(); break;
                    case 'c': handleOptionC(); break;
                    case 'd': handleOptionD(); break;
                    default: printf("Invalid option.\n");
                }
            }
        } else {
            attempts++;
            printf("Incorrect password! You have %d attempt(s) left.\n", 3 - attempts);
        }
    }

    printf("\nWARNING: Too many incorrect attempts. Exiting system.\n");
    return 1;
}
// 心得：
// 透過這次座位預約系統的設計，讓我更加熟悉C語言中的陣列、流程控制與使用者互動，
// 並學會如何結合邏輯與隨機性來模擬實際應用情境，是一次非常實用的練習。
// 加上用英文註解又更難了 



