#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clear_screen() {
    system("cls || clear");
}

int main() {
    char input_char;
    char password[5];
    
    
    printf("\n\n\n\n\n******************** WELCOME ********************\n");
    printf("\n�����N���~��...");
    getchar();
    clear_screen();
    
    
    printf("�п�J 4 ��ƱK�X: ");
    scanf("%4s", password);
    getchar(); 
    
    if (strcmp(password, "2024") != 0) {
        printf("\n�K�X���~! �{������...\n");
        return 0;
    }
    
    printf("\n�K�X���T! �w��i�J�t��...\n");
    printf("\n�����N���~��...");
    getchar();
    clear_screen();
    
   
    printf("        *        \n");
    printf("       * *       \n");
    printf("      * A *      \n");
    printf("     * a 0 *     \n");
    printf("    * Other *    \n");
    printf("     * a 0 *     \n");
    printf("      * A *      \n");
    printf("       * *       \n");
    printf("        *        \n");
    
    
    printf("\n�п�J�@�Ӧr��: ");
    scanf(" %c", &input_char);
    
    if (input_char >= 'A' && input_char <= 'Z') {
        printf("\nUppercase\n");
    } else if (input_char >= 'a' && input_char <= 'z') {
        printf("\nLowercase\n");
    } else if (input_char >= '0' && input_char <= '9') {
        printf("\nDigit\n");
    } else {
        printf("\n�Z��: �q��1B �y��: 42 �m�W: �i����\n");
    }
    
    printf("\n�����N�䵲��...");
    getchar();
    clear_screen();
    
    return 0;
}

