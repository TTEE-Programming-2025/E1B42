#include <stdio.h>
#include <stdlib.h>

// ���]�ǥ͸�Ƶ��c�P�}�C�Ӧۨ�L�ɮ�
extern Student students[];
extern int student_count;

// �M���ù��禡
void clear_screen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// �ƦW��ܨ禡
void show_grade_ranking() {
    clear_screen();

    printf("=== Grade Ranking (by Average) ===\n");

    // �إ߾ǥ͸�ƪ��ƻs�}�C�H�קK��ʭ���
    Student sorted[MAX_STUDENTS];
    for (int i = 0; i < student_count; i++) {
        sorted[i] = students[i];
    }

    // �ϥ�²�檺�w�j�ƧǪk�ھڥ������Z�Ƨǡ]�����^
    for (int i = 0; i < student_count - 1; i++) {
        for (int j = 0; j < student_count - i - 1; j++) {
            if (sorted[j].average < sorted[j + 1].average) {
                Student temp = sorted[j];
                sorted[j] = sorted[j + 1];
                sorted[j + 1] = temp;
            }
        }
    }

    // ��ܱƧǫ᪺���G
    printf("\n%-10s %-10s %-10s\n", "Name", "ID", "Average");
    for (int i = 0; i < student_count; i++) {
        printf("%-10s %-10d %-10.1f\n",
               sorted[i].name, sorted[i].id, sorted[i].average);
    }

    printf("\nPress Enter to return to the menu...\n");
    getchar(); getchar();
}

