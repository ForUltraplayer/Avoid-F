#include "a.h"

void loginboard() {

    int x = 15; // �޴��� ����� x ��ǥ
    int y = 8; // �޴��� ����� y ��ǥ

    textcolor(14);
    gotoxy(x, y++);
    puts("����������������������������������������������������");
    gotoxy(x, y++);
    puts("��                                                ��");
    gotoxy(x, y++);
    puts("��                 1. �� �� ��                    ��");
    gotoxy(x, y++);
    puts("��                                                ��");
    gotoxy(x, y++);
    puts("��                 2. ȸ�� ����                   ��");
    gotoxy(x, y++);
    puts("��                                                ��");
    gotoxy(x, y++);
    puts("��                 0. ��     ��                   ��");
    gotoxy(x, y++);
    puts("��                                                ��");
    gotoxy(x, y++);
    puts("����������������������������������������������������");
    gotoxy(x + 11, y + 2);
    printf(" Select > ");

}