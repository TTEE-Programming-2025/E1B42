#include <stdio.h>
#include <stdlib.h>

// ���]���c�P����}�C�w�b��L�ɮפ��w�q
extern Student students[];
extern int student_count;

// �M���ù��]�M��L�ɮצ@�Ρ^
void clear_screen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// ��ܩҦ��ǥͦ��Z���禡
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
    getchar(); getchar(); // �T�O��J�i��
}



