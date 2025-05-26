#include <stdio.h>
#include <stdlib.h>

// 假設結構與全域陣列已在其他檔案中定義
extern Student students[];
extern int student_count;

// 清除螢幕（和其他檔案共用）
void clear_screen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// 顯示所有學生成績的函式
void display_student_grades() {
    clear_screen();

    printf("Student Grades\n");
    printf("-----------------------------------------------------\n");
    printf("Name\tID\t  Math\tPhysics\tEnglish\tAverage\n");
    printf("-----------------------------------------------------\n");

    for (int i = 0; i < student_count; i++) {
        printf("%s\t%d\t  %3d\t  %3d\t  %3d\t  %.1f\n",
            students[i].name,
            students[i].id,
            students[i].math,
            students[i].physics,
            students[i].english,
            students[i].average);
    }

    printf("-----------------------------------------------------\n");
    printf("Press Enter to return to the menu...\n");
    getchar(); getchar(); // 確保輸入可見
}



