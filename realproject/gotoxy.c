#include "a.h"


void gotoxy(int x, int y) //gotoxy를 사용하기 위한 함수

{
    COORD pos = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}