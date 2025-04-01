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
    printf("\n按任意鍵繼續...");
    getchar();
    clear_screen();
    
    
    printf("請輸入 4 位數密碼: ");
    scanf("%4s", password);
    getchar(); 
    
    if (strcmp(password, "2024") != 0) {
        printf("\n密碼錯誤! 程式結束...\n");
        return 0;
    }
    
    printf("\n密碼正確! 歡迎進入系統...\n");
    printf("\n按任意鍵繼續...");
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
    
    
    printf("\n請輸入一個字元: ");
    scanf(" %c", &input_char);
    
    if (input_char >= 'A' && input_char <= 'Z') {
        printf("\nUppercase\n");
    } else if (input_char >= 'a' && input_char <= 'z') {
        printf("\nLowercase\n");
    } else if (input_char >= '0' && input_char <= '9') {
        printf("\nDigit\n");
    } else {
        printf("\n班級: 電機1B 座號: 42 姓名: 張竣翔\n");
    }
    
    printf("\n按任意鍵結束...");
    getchar();
    clear_screen();
    
    return 0;
}
Git 是一個強大的版本控制工具，能幫助開發者有效管理代碼、記錄歷史、協作開發。
通過創建分支、提交、合併等功能，Git 讓團隊開發變得高效且有序。
使用清晰的提交信息、保持分支整潔，並定期推送和拉取代碼，是良好的 Git 使用習慣。
