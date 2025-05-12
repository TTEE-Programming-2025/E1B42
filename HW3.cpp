#define SIZE 9
#define PASSWORD "2025"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PASSWORD "2025"  // Default 4-digit password

// Function to display a personalized styled screen (at least 20 lines)
void showStyledScreen() {
    printf("========================================\n");
    printf("*                                      *\n");
    printf("*          WELCOME TO THE APP          *\n");
    printf("*                                      *\n");
    printf("*        Developed by [DO DO ]      *\n");
    printf("*                                      *\n");
    printf("*        Secure Access Required        *\n");
    printf("*                                      *\n");
    printf("========================================\n");
    
    // Print 12 additional custom lines to make total lines at least 20
    for (int i = 0; i < 12; i++) {
        printf("*        Personal Style Line %2d        *\n", i + 1);
    }

    printf("========================================\n");
}

int main() {
    char input[100];     // Buffer to store user input
    int attempts = 0;    // Counter for wrong attempts

    // Show styled welcome screen
    showStyledScreen();

    // Allow up to 3 attempts for correct password
    while (attempts < 3) {
        printf("Enter 4-digit password: ");
        fgets(input, sizeof(input), stdin);                  // Read input from user
        input[strcspn(input, "\n")] = '\0';                  // Remove newline character

        // Check if password is correct
        if (strcmp(input, PASSWORD) == 0) {
            printf("\nAccess granted. Welcome!\n");
            // Proceed to the next step here
            printf(">>> Proceeding to the next step...\n");
            return 0;  // Exit successfully
        } else {
            attempts++;
            printf("Incorrect password! You have %d attempt(s) left.\n", 3 - attempts);
        }
    }

    // If 3 incorrect attempts, show warning and exit
    printf("\nWARNING: Too many incorrect attempts. Exiting system.\n");
    return 1;  // Exit with error
}




