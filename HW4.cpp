#include <stdio.h>
#include <stdlib.h>

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

// 排名顯示函式
void show_grade_ranking() {
    clear_screen();

    printf("=== Grade Ranking (by Average) ===\n");

    // 建立學生資料的複製陣列以避免更動原資料
    Student sorted[MAX_STUDENTS];
    for (int i = 0; i < student_count; i++) {
        sorted[i] = students[i];
    }

    // 使用簡單的泡沫排序法根據平均成績排序（降冪）
    for (int i = 0; i < student_count - 1; i++) {
        for (int j = 0; j < student_count - i - 1; j++) {
            if (sorted[j].average < sorted[j + 1].average) {
                Student temp = sorted[j];
                sorted[j] = sorted[j + 1];
                sorted[j + 1] = temp;
            }
        }
    }

    // 顯示排序後的結果
    printf("\n%-10s %-10s %-10s\n", "Name", "ID", "Average");
    for (int i = 0; i < student_count; i++) {
        printf("%-10s %-10d %-10.1f\n",
               sorted[i].name, sorted[i].id, sorted[i].average);
    }

    printf("\nPress Enter to return to the menu...\n");
    getchar(); getchar();
}

