#include "a.h"

void textcolor(int color_number) //�ؽ�Ʈ�� ������ ��� �� �� �ְ� ���ִ� �Լ�
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
}