#pragma once

#include <stdio.h> //표준 입출력 라이브러리, printf()나 scanf()를 사용하기위함
#include <conio.h> //콘솔 입출력 라이브러리, kbhit() 함수를 사용하기 위해 사용함 
#include <time.h>  //시간 관련 라이브러리, 난수 생성시 사용되는 srand()와 time()함수를 사용하기 위함
#include <windows.h> //윈도우 운영체제 관련 라이브러리, Sleep(), gotoxy() 등의 함수를 사용하기 위함

#define MAX_X 40 //최대 x좌표값 정의
#define MAX_Y 20 //최대 y좌표값 정의
#define LETTER_CNT 1024 //최대 탄막 개수 지정

struct Node {  //탄막들을 효율적으로 관리하기 위해 구조체 사용
    char ch;   //탄막의 모양을 문자로 사용하기위함
    int x;     //x좌표
    int y;     //y좌표
    int flag;  //문자 활성상태 여부 (1 = 활성 , 0 = 비활성)
    int life;  //낙하유지시간
    int speed; //속도
};


void frontMenu(); //최초 게임타이틀을 출력하는 함수
void mainMenu(); //게임의 메인메뉴를 출력하는 함수
void levelSelectMenu(); //게임의 레벨을 선택하는 창을 출력하는 함수
int gameStart(); //전체적인 게임 로직
void gotoxy(); //gotoxy를 사용하게 해주는 함수
void textcolor(); //text의 컬러를 사용 할 수 있게 해주는 함수
void gameboard(); //게임판을 출력하는 함수 
