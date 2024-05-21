#include "a.h"

void loginboard() {

    int x = 15; // 메뉴를 출력할 x 좌표
    int y = 8; // 메뉴를 출력할 y 좌표

    textcolor(14);
    gotoxy(x, y++);
    puts("┏━━━━━━━━━━━━━━━━━━━━━━━━┓");
    gotoxy(x, y++);
    puts("┃                                                ┃");
    gotoxy(x, y++);
    puts("┃                 1. 로 그 인                    ┃");
    gotoxy(x, y++);
    puts("┃                                                ┃");
    gotoxy(x, y++);
    puts("┃                 2. 회원 가입                   ┃");
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