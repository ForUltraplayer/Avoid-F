#include "a.h"

void mainMenu() //���θ޴��� ����ϴ� �Լ�
{
    int x = 15; // �޴��� ����� x ��ǥ
    int y = 8; // �޴��� ����� y ��ǥ
    textcolor(14);
    gotoxy(x, y++);
    puts("����������������������������������������������������");
    gotoxy(x, y++);
    puts("��           �Ǣ� ź�� ���ϱ� ���� �Ǣ�           ��");
    gotoxy(x, y++);
    puts("��                                                ��");
    gotoxy(x, y++);
    puts("��                 1. ���� ����                   ��");
    gotoxy(x, y++);
    puts("��                                                ��");
    gotoxy(x, y++);
    puts("��                 2. �ְ� ����                   ��");
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


