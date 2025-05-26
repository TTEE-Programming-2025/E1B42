#include <stdio.h>
#include <stdlib.h>

#define PASSWORD 2025

void show_start_screen() {
    printf("=============================================\n");
    for (int i = 0; i < 20; i++) {
        printf("*        Welcome to the Grade System        *\n");
    }
    printf("=============================================\n");
}

int main() {
    int input, attempts = 0;

    show_start_screen();

    while (attempts < 3) {
        printf("Enter 4-digit password: ");
        scanf("%d", &input);
        if (input == PASSWORD) {
            printf("Access granted! Welcome!\n");
            return 0;
        } else {
            printf("Incorrect password. Try again.\n");
            attempts++;
        }
    }

    printf("Too many failed attempts. Exiting system.\n");
    return 0;
}


