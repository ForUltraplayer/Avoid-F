#include "a.h"


void gotoxy(int x, int y) //gotoxy�� ����ϱ� ���� �Լ�

{
    COORD pos = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}