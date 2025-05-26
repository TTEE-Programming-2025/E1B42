#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 10

// �ǥ͸�Ƶ��c
typedef struct {
    char name[50];
    int id;
    int math;
    int physics;
    int english;
    float average;
} Student;

Student students[MAX_STUDENTS];  // ����}�C�x�s�ǥ͸��
int student_count = 0;

// �M���ù�
void clear_screen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// ���ϥΪ̿�J���Z���禡
void enter_student_grades() {
    clear_screen();
    int n;

    printf("Enter number of students (5 to 10): ");
    scanf("%d", &n);

    // ���ҾǥͤH��
    while (n < 5 || n > 10) {
        printf("Invalid input. Please enter between 5 and 10: ");
        scanf("%d", &n);
    }

    student_count = n;

    // ��J�C��ǥͪ����
    for (int i = 0; i < n; i++) {
        printf("\n[Student %d]\n", i + 1);

        printf("Name: ");
        scanf("%s", students[i].name);

        printf("Student ID (6-digit number): ");
        scanf("%d", &students[i].id);
        while (students[i].id < 100000 || students[i].id > 999999) {
            printf("Invalid ID. Enter a 6-digit number: ");
            scanf("%d", &students[i].id);
        }

        printf("Math score (0~100): ");
        scanf("%d", &students[i].math);
        while (students[i].math < 0 || students[i].math > 100) {
            printf("Invalid score. Re-enter (0~100): ");
            scanf("%d", &students[i].math);
        }

        printf("Physics score (0~100): ");
        scanf("%d", &students[i].physics);
        while (students[i].physics < 0 || students[i].physics > 100) {
            printf("Invalid score. Re-enter (0~100): ");
            scanf("%d", &students[i].physics);
        }

        printf("English score (0~100): ");
        scanf("%d", &students[i].english);
        while (students[i].english < 0 || students[i].english > 100) {
            printf("Invalid score. Re-enter (0~100): ");
            scanf("%d", &students[i].english);
        }

        // �p�⥭�����Z
        students[i].average = (students[i].math + students[i].physics + students[i].english) / 3.0f;
    }

    printf("\nAll student data has been entered. Press Enter to return to menu...\n");
    getchar(); getchar();  // ���ݨϥΪ̫����N��
}



