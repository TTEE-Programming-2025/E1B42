#include <stdio.h>    // �ޤJ�зǿ�J��X�禡�w
#include <stdlib.h>   // �ޤJ�t�Υ\��禡�w
#include <conio.h>    // �ޤJ�Y����L��J�禡

#define PASSWORD 2025 // �w�q���T�K�X�`��

// ��ܭӤH���檺�w��e��
void showWelcome() {
    printf("========================================\n");
    printf("||                                       ||\n");
    printf("||    �w��U�ШϥΥ��{�� (By ����)       ||\n");
    printf("||                                       ||\n");
    printf("||    a. ��X�����T����                  ||\n");
    printf("||    b. ��ܭ��k��                      ||\n");
    printf("||    c. ����                            ||\n");
    printf("||                                       ||\n");
    printf("========================================\n");
    for (int i = 0; i < 15; i++) {
        printf("== �w����{ ==\n");
    }
}

// ��ܿ��ѨϥΪ̿�ܥ\��
void showMenu() {
    printf("\n---------�D���---------\n");
    printf("a. ��X�����T����\n");
    printf("b. ��ܭ��k��\n");
    printf("c. ����\n");
    printf("------------------------\n");
}

// ���̦ͨr���ƦC�������T����
void triangle() {
    char ch;
    printf("�п�J�@�� a �� n ���r���G");
    scanf(" %c", &ch);

    // �P�_��J�r���O�_�b�d�� 
    if (ch >= 'a' && ch <= 'n') {
        // �̿�J�r���v��L�X�T����
        for (char i = 'a'; i <= ch; i++) {
            for (char j = 'a'; j <= i; j++) {
                printf("%c", j);
            }
            printf("\n");
        }
    } else {
        // �Y��J���~�h���ܨí��s��J
        printf("��J���~�A�Э��s��J�C\n");
        triangle();
    }
}

// ���ͫ��w�j�p�����k��
void multiplicationTable() {
    int n;
    printf("�п�J�@��1��9����ơG");
    scanf("%d", &n);

    // �P�_�Ʀr�O�_�b�d�� 
    if (n >= 1 && n <= 9) {
        // �إ� n x n �����k��
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                printf("%2d ", i * j);
            }
            printf("\n");
        }
    } else {
        // ��J���~�h���ܨí��s��J
        printf("��J���~�A�Э��s��J�C\n");
        multiplicationTable();
    }
}

int main() {
    int password;
    int attempts = 0; // ���տ�J�K�X����
    char choice;      // �D���ﶵ
    char again;       // �O�_�����{��

    showWelcome();    // �I�s����w��e��

    // ���ұK�X�A�̦h�T�����|
    do {
        printf("�п�J4��ƱK�X�G");
        scanf("%d", &password);

        if (password == PASSWORD) {
            // �K�X���T�h���X�j��
            break;
        } else {
            attempts++;
            printf("�K�X���~�I\n");
        }
    } while (attempts < 3);

    // �W�L�T����J���~�h����
    if (attempts >= 3) {
        printf("�K�X���~�T���A�t�ε����C\n");
        return 0;
    }

    // �D�\��j��A������ܿ��
    do {
        system("cls"); // �M���e��
        showMenu();    // ��ܥD���

        printf("�п�ܤ@�ӿﶵ(a/b/c)�G");
        scanf(" %c", &choice);

        // �ھڨϥΪ̿�ܰ���\��
        switch (choice) {
            case 'a':
            case 'A':
                system("cls"); // �M���e��
                triangle();    // �I�s�T���Υ\��
                printf("\n�Ы����N���^�D���...");
                getch();       // ���ݫ���
                break;
            case 'b':
            case 'B':
                system("cls"); // �M���e��
                multiplicationTable(); // �I�s���k��\��
                printf("\n�Ы����N���^�D���...");
                getch();       // ���ݫ���
                break;
            case 'c':
            case 'C':
                // ��ܵ����ɶi��T�{
                printf("�T�w�n�����ܡH(y/n)�G");
                scanf(" %c", &again);
                if (again == 'y' || again == 'Y') {
                    printf("�{�������A�P�¨ϥΡI\n");
                    exit(0); // �T�{�ᵲ���{��
                }
                break;
            default:
                // �ﶵ��J���~����
                printf("�L�Ŀﶵ�A�Э��s��J�I\n");
                getch();
                break;
        }
    } while (1); // �L������^�D���
    return 0;
}

//�o�����{�����ھǲߨ�ܦh�F��A�@�}�l�ڪ��{������A�s��²�檺��J��X�����|�A��Ӹg�L���_���m�ߡA���e�Ψ�Fdo while,if else
//case for�j�鵥���A�ǥH�P�Ϊ��Pı�ܦn�A����ı�o���e�ǲߪ��V�O���ܭȱo 
 

