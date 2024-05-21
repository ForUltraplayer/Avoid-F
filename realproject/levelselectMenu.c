#include "a.h"

void levelSelectMenu() //난이도를 선택하는 창을 출력하는 함수
{
	int x = 15; // 메뉴를 출력할 x 좌표
	int y = 8; // 메뉴를 출력할 y 좌표
	textcolor(11);
	gotoxy(x, y++);
	puts("┏━━━━━━━━━━━━━━━━━━━━━━━━┓");
	gotoxy(x, y++);
	puts("┃               ▤▤ 난이도 선택 ▤▤            ┃");
	gotoxy(x, y++);
	puts("┃                                                ┃");
	gotoxy(x, y++);
	puts("┃                  1. 초 급                      ┃");
	gotoxy(x, y++);
	puts("┃                                                ┃");
	gotoxy(x, y++);
	puts("┃                  2. 중 급                      ┃");
	gotoxy(x, y++);
	puts("┃                                                ┃");
	gotoxy(x, y++);
	puts("┃                  3. 고 급                      ┃");
	gotoxy(x, y++);
	puts("┃                                                ┃");
	gotoxy(x, y++);
	puts("┃                  0. 메인 메뉴                  ┃");
	gotoxy(x, y++);
	puts("┃                                                ┃");
	gotoxy(x, y);
	puts("┗━━━━━━━━━━━━━━━━━━━━━━━━┛");
	gotoxy(x + 11, y + 2);
	printf(" Select > ");
}