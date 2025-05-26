/*
 * 簡易成績系統
 * 目的: 練習 C 語言中結構(struct)與指標的應用，並搭配控制流程、陣列、字串操作等。
 * 功能包含: 登入驗證、主選單、成績輸入、查詢、排名與離開確認等。
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 10
#define PASSWORD 2025

// 結構定義: 學生資料型別
typedef struct {
    char name[50];     // 姓名
    int id;            // 學號 (6 位數)
    int math;          // 數學成績
    int physics;       // 物理成績
    int english;       // 英文成績
    float average;     // 平均成績
} Student;

Student students[MAX_STUDENTS]; // 儲存學生資料的陣列
int student_count = 0;          // 實際輸入的學生人數

// 清除螢幕 (支援 Windows 與 Unix-like 系統)
void clear_screen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// 顯示開場畫面 (20 行)
void show_start_screen() {
    printf("============================================\n");
    for (int i = 0; i < 20; i++) {
        printf("*        Welcome to the Grade System        *\n");
    }
    printf("============================================\n");
}

// 驗證密碼 (最多三次機會)
int password_check() {
    int input, attempts = 0;
    while (attempts < 3) {
        printf("Enter 4-digit password: ");
        scanf("%d", &input);
        if (input == PASSWORD) {
            printf("Access granted! Welcome!\n");
            return 1;
        } else {
            printf("Incorrect password. Try again.\n");
            attempts++;
        }
    }
    printf("Too many failed attempts. Exiting system.\n");
    return 0;
}

// 顯示主選單
void show_menu() {
    printf("------------[Grade System]-------------\n");
    printf("| a. Enter student grades             |\n");
    printf("| b. Display student grades           |\n");
    printf("| c. Search for student grades        |\n");
    printf("| d. Grade ranking                    |\n");
    printf("| e. Exit system                      |\n");
    printf("---------------------------------------\n");
}

// 選項 a: 輸入學生成績
void enter_grades() {
    clear_screen();
    int n;
    printf("Enter number of students (5~10): ");
    scanf("%d", &n);
    while (n < 5 || n > 10) {
        printf("Invalid number. Please enter between 5 and 10: ");
        scanf("%d", &n);
    }
    student_count = n;
    for (int i = 0; i < n; i++) {
        printf("\n-- Enter data for student %d --\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Student ID (6-digit): ");
        scanf("%d", &students[i].id);
        while (students[i].id < 100000 || students[i].id > 999999) {
            printf("Invalid ID. Enter 6-digit number: ");
            scanf("%d", &students[i].id);
        }
        printf("Math score (0-100): ");
        scanf("%d", &students[i].math);
        while (students[i].math < 0 || students[i].math > 100) {
            printf("Invalid score. Enter between 0-100: ");
            scanf("%d", &students[i].math);
        }
        printf("Physics score (0-100): ");
        scanf("%d", &students[i].physics);
        while (students[i].physics < 0 || students[i].physics > 100) {
            printf("Invalid score. Enter between 0-100: ");
            scanf("%d", &students[i].physics);
        }
        printf("English score (0-100): ");
        scanf("%d", &students[i].english);
        while (students[i].english < 0 || students[i].english > 100) {
            printf("Invalid score. Enter between 0-100: ");
            scanf("%d", &students[i].english);
        }
        students[i].average = (students[i].math + students[i].physics + students[i].english) / 3.0f;
    }
    printf("Data entry completed. Returning to menu...\n");
    getchar(); getchar(); // 等待輸入
}

// 選項 b: 顯示所有學生成績
void display_grades() {
    clear_screen();
    printf("Name\tID\tMath\tPhysics\tEnglish\tAverage\n");
    for (int i = 0; i < student_count; i++) {
        printf("%s\t%d\t%d\t%d\t%d\t%.1f\n",
               students[i].name, students[i].id,
               students[i].math, students[i].physics, students[i].english,
               students[i].average);
    }
    printf("Press Enter to return to menu...\n");
    getchar(); getchar();
}

// 選項 c: 搜尋特定學生資料
void search_grades() {
    clear_screen();
    char search_name[50];
    int found = 0;
    printf("Enter name to search: ");
    scanf("%s", search_name);
    for (int i = 0; i < student_count; i++) {
        if (strcmp(students[i].name, search_name) == 0) {
            printf("Found: %s %d %d %d %d %.1f\n",
                   students[i].name, students[i].id,
                   students[i].math, students[i].physics, students[i].english,
                   students[i].average);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Student not found.\n");
    }
    printf("Press Enter to return to menu...\n");
    getchar(); getchar();
}

// 選項 d: 成績由高到低排序並列出
void grade_ranking() {
    clear_screen();
    for (int i = 0; i < student_count - 1; i++) {
        for (int j = i + 1; j < student_count; j++) {
            if (students[j].average > students[i].average) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
    printf("Ranked by average:\n");
    printf("Name\tID\tAverage\n");
    for (int i = 0; i < student_count; i++) {
        printf("%s\t%d\t%.1f\n", students[i].name, students[i].id, students[i].average);
    }
    printf("Press Enter to return to menu...\n");
    getchar(); getchar();
}

// 選項 e: 離開前的確認
int confirm_exit() {
    char choice;
    while (1) {
        printf("確定離開？(y/n): ");
        scanf(" %c", &choice);
        if (choice == 'y' || choice == 'Y') return 1;
        else if (choice == 'n' || choice == 'N') return 0;
        else printf("請輸入 'y' 或 'n'。\n");
    }
}

// 主程式進入點
int main() {
    show_start_screen();
    if (!password_check()) return 0;
    char choice;
    while (1) {
        clear_screen();
        show_menu();
        printf("Select option: ");
        scanf(" %c", &choice);
        switch (choice) {
            case 'a': enter_grades(); break;
            case 'b': display_grades(); break;
            case 'c': search_grades(); break;
            case 'd': grade_ranking(); break;
            case 'e':
                if (confirm_exit()) {
                    printf("System exiting... Goodbye!\n");
                    return 0;
                }
                break;
            default:
                printf("Invalid option. Try again.\n");
                getchar(); getchar();
        }
    }
    return 0;
}
//這次設計簡易成績系統的過程，讓我深入了解 C 語言中結構與指標的實際應用。
//從輸入資料、驗證、排序到搜尋等功能的實作，不僅強化了我對資料結構與流程控制的掌握，也培養了解決實務問題的能力。
//透過反覆的測試與除錯，更加體會到程式設計需要細心與邏輯思考，是一次非常有收穫的學習經驗。
 
