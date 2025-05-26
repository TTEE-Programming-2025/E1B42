/*
 * ²�����Z�t��
 * �ت�: �m�� C �y�������c(struct)�P���Ъ����ΡA�÷f�t����y�{�B�}�C�B�r��ާ@���C
 * �\��]�t: �n�J���ҡB�D���B���Z��J�B�d�ߡB�ƦW�P���}�T�{���C
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 10
#define PASSWORD 2025

// ���c�w�q: �ǥ͸�ƫ��O
typedef struct {
    char name[50];     // �m�W
    int id;            // �Ǹ� (6 ���)
    int math;          // �ƾǦ��Z
    int physics;       // ���z���Z
    int english;       // �^�妨�Z
    float average;     // �������Z
} Student;

Student students[MAX_STUDENTS]; // �x�s�ǥ͸�ƪ��}�C
int student_count = 0;          // ��ڿ�J���ǥͤH��

// �M���ù� (�䴩 Windows �P Unix-like �t��)
void clear_screen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// ��ܶ}���e�� (20 ��)
void show_start_screen() {
    printf("============================================\n");
    for (int i = 0; i < 20; i++) {
        printf("*        Welcome to the Grade System        *\n");
    }
    printf("============================================\n");
}

// ���ұK�X (�̦h�T�����|)
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

// ��ܥD���
void show_menu() {
    printf("------------[Grade System]-------------\n");
    printf("| a. Enter student grades             |\n");
    printf("| b. Display student grades           |\n");
    printf("| c. Search for student grades        |\n");
    printf("| d. Grade ranking                    |\n");
    printf("| e. Exit system                      |\n");
    printf("---------------------------------------\n");
}

// �ﶵ a: ��J�ǥͦ��Z
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
    getchar(); getchar(); // ���ݿ�J
}

// �ﶵ b: ��ܩҦ��ǥͦ��Z
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

// �ﶵ c: �j�M�S�w�ǥ͸��
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

// �ﶵ d: ���Z�Ѱ���C�ƧǨæC�X
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

// �ﶵ e: ���}�e���T�{
int confirm_exit() {
    char choice;
    while (1) {
        printf("�T�w���}�H(y/n): ");
        scanf(" %c", &choice);
        if (choice == 'y' || choice == 'Y') return 1;
        else if (choice == 'n' || choice == 'N') return 0;
        else printf("�п�J 'y' �� 'n'�C\n");
    }
}

// �D�{���i�J�I
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
//�o���]�p²�����Z�t�Ϊ��L�{�A���ڲ`�J�F�� C �y�������c�P���Ъ�������ΡC
//�q��J��ơB���ҡB�ƧǨ�j�M���\�઺��@�A���ȱj�ƤF�ڹ��Ƶ��c�P�y�{����x���A�]���i�F�ѨM��Ȱ��D����O�C
//�z�L���Ъ����ջP�����A��[��|��{���]�p�ݭn�Ӥ߻P�޿��ҡA�O�@���D�`����ì���ǲ߸g��C
 
