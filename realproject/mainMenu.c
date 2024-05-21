#include "a.h"

void mainMenu() //메인메뉴를 출력하는 함수
{
    int x = 15; // 메뉴를 출력할 x 좌표
    int y = 8; // 메뉴를 출력할 y 좌표
    textcolor(14);
    gotoxy(x, y++);
    puts("┏━━━━━━━━━━━━━━━━━━━━━━━━┓");
    gotoxy(x, y++);
    puts("┃           ▤▤ 탄막 피하기 게임 ▤▤           ┃");
    gotoxy(x, y++);
    puts("┃                                                ┃");
    gotoxy(x, y++);
    puts("┃                 1. 게임 시작                   ┃");
    gotoxy(x, y++);
    puts("┃                                                ┃");
    gotoxy(x, y++);
    puts("┃                 2. 최고 점수                   ┃");
    gotoxy(x, y++);
    puts("┃                                                ┃");
    gotoxy(x, y++);
    puts("┃                 0. 종     료                   ┃");
    gotoxy(x, y++);
    puts("┃                                                ┃");
    gotoxy(x, y++);
    puts("┗━━━━━━━━━━━━━━━━━━━━━━━━┛");
    gotoxy(x + 11, y + 2);
    printf(" Select > ");
}


