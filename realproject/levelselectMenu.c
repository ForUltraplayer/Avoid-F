#include "a.h"

void levelSelectMenu() //���̵��� �����ϴ� â�� ����ϴ� �Լ�
{
	int x = 15; // �޴��� ����� x ��ǥ
	int y = 8; // �޴��� ����� y ��ǥ
	textcolor(11);
	gotoxy(x, y++);
	puts("����������������������������������������������������");
	gotoxy(x, y++);
	puts("��               �Ǣ� ���̵� ���� �Ǣ�            ��");
	gotoxy(x, y++);
	puts("��                                                ��");
	gotoxy(x, y++);
	puts("��                  1. �� ��                      ��");
	gotoxy(x, y++);
	puts("��                                                ��");
	gotoxy(x, y++);
	puts("��                  2. �� ��                      ��");
	gotoxy(x, y++);
	puts("��                                                ��");
	gotoxy(x, y++);
	puts("��                  3. �� ��                      ��");
	gotoxy(x, y++);
	puts("��                                                ��");
	gotoxy(x, y++);
	puts("��                  0. ���� �޴�                  ��");
	gotoxy(x, y++);
	puts("��                                                ��");
	gotoxy(x, y);
	puts("����������������������������������������������������");
	gotoxy(x + 11, y + 2);
	printf(" Select > ");
}