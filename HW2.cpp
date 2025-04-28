#include <stdio.h>    // 引入標準輸入輸出函式庫
#include <stdlib.h>   // 引入系統功能函式庫
#include <conio.h>    // 引入即時鍵盤輸入函式

#define PASSWORD 2025 // 定義正確密碼常數

// 顯示個人風格的歡迎畫面
void showWelcome() {
    printf("========================================\n");
    printf("||                                       ||\n");
    printf("||    歡迎助教使用本程式 (By 竣翔)       ||\n");
    printf("||                                       ||\n");
    printf("||    a. 輸出直角三角形                  ||\n");
    printf("||    b. 顯示乘法表                      ||\n");
    printf("||    c. 結束                            ||\n");
    printf("||                                       ||\n");
    printf("========================================\n");
    for (int i = 0; i < 15; i++) {
        printf("== 歡迎光臨 ==\n");
    }
}

// 顯示選單供使用者選擇功能
void showMenu() {
    printf("\n---------主選單---------\n");
    printf("a. 輸出直角三角形\n");
    printf("b. 顯示乘法表\n");
    printf("c. 結束\n");
    printf("------------------------\n");
}

// 產生依字母排列的直角三角形
void triangle() {
    char ch;
    printf("請輸入一個 a 到 n 的字元：");
    scanf(" %c", &ch);

    // 判斷輸入字元是否在範圍內 
    if (ch >= 'a' && ch <= 'n') {
        // 依輸入字元逐行印出三角形
        for (char i = 'a'; i <= ch; i++) {
            for (char j = 'a'; j <= i; j++) {
                printf("%c", j);
            }
            printf("\n");
        }
    } else {
        // 若輸入錯誤則提示並重新輸入
        printf("輸入錯誤，請重新輸入。\n");
        triangle();
    }
}

// 產生指定大小的乘法表
void multiplicationTable() {
    int n;
    printf("請輸入一個1到9的整數：");
    scanf("%d", &n);

    // 判斷數字是否在範圍內 
    if (n >= 1 && n <= 9) {
        // 建立 n x n 的乘法表
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                printf("%2d ", i * j);
            }
            printf("\n");
        }
    } else {
        // 輸入錯誤則提示並重新輸入
        printf("輸入錯誤，請重新輸入。\n");
        multiplicationTable();
    }
}

int main() {
    int password;
    int attempts = 0; // 嘗試輸入密碼次數
    char choice;      // 主選單選項
    char again;       // 是否結束程式

    showWelcome();    // 呼叫顯示歡迎畫面

    // 驗證密碼，最多三次機會
    do {
        printf("請輸入4位數密碼：");
        scanf("%d", &password);

        if (password == PASSWORD) {
            // 密碼正確則跳出迴圈
            break;
        } else {
            attempts++;
            printf("密碼錯誤！\n");
        }
    } while (attempts < 3);

    // 超過三次輸入錯誤則結束
    if (attempts >= 3) {
        printf("密碼錯誤三次，系統結束。\n");
        return 0;
    }

    // 主功能迴圈，反覆顯示選單
    do {
        system("cls"); // 清除畫面
        showMenu();    // 顯示主選單

        printf("請選擇一個選項(a/b/c)：");
        scanf(" %c", &choice);

        // 根據使用者選擇執行功能
        switch (choice) {
            case 'a':
            case 'A':
                system("cls"); // 清除畫面
                triangle();    // 呼叫三角形功能
                printf("\n請按任意鍵返回主選單...");
                getch();       // 等待按鍵
                break;
            case 'b':
            case 'B':
                system("cls"); // 清除畫面
                multiplicationTable(); // 呼叫乘法表功能
                printf("\n請按任意鍵返回主選單...");
                getch();       // 等待按鍵
                break;
            case 'c':
            case 'C':
                // 選擇結束時進行確認
                printf("確定要結束嗎？(y/n)：");
                scanf(" %c", &again);
                if (again == 'y' || again == 'Y') {
                    printf("程式結束，感謝使用！\n");
                    exit(0); // 確認後結束程式
                }
                break;
            default:
                // 選項輸入錯誤提示
                printf("無效選項，請重新輸入！\n");
                getch();
                break;
        }
    } while (1); // 無限次返回主選單
    return 0;
}

//這次的程式讓我學習到很多東西，一開始我的程式很爛，連最簡單的輸入輸出都不會，後來經過不斷的練習，內容用到了do while,if else
//case for迴圈等等，學以致用的感覺很好，讓我覺得之前學習的努力都很值得 
 

