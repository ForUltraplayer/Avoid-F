#include "a.h"

void textcolor(int color_number) //텍스트에 색상을 사용 할 수 있게 해주는 함수
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
}