#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 假設學生資料結構與陣列來自其他檔案
extern Student students[];
extern int student_count;

// 清除螢幕函式
void clear_screen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// 搜尋學生成績的函式
void search_student_grades() {
    clear_screen();

    char search_name[50];
    int found = 0;

    printf("=== Search Student Grades ===\n");
    printf("Enter student name: ");
    scanf("%s", search_name); // 讀入欲搜尋的姓名

    for (int i = 0; i < student_count; i++) {
        if (strcmp(students[i].name, search_name) == 0) {
            // 找到學生，顯示資料
            printf("\nStudent Found:\n");
            printf("Name   : %s\n", students[i].name);
            printf("ID     : %d\n", students[i].id);
            printf("Math   : %d\n", students[i].math);
            printf("Physics: %d\n", students[i].physics);
            printf("English: %d\n", students[i].english);
            printf("Average: %.1f\n", students[i].average);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nNo student found with the name \"%s\".\n", search_name);
    }

    printf("\nPress Enter to return to the menu...\n");
    getchar(); getchar(); // 暫停等待
}

