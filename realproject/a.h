#pragma once // 이 헤더 파일이 한 번만 포함되도록 함.

#include <stdio.h> // 표준 입출력 라이브러리 포함.
#include <conio.h> // 윈도우즈 상의 콘솔 입력 및 출력 라이브러리 포함.
#include <time.h> // 난수 생성 및 시간 측정을 위한 시간 라이브러리 포함.
#include <windows.h> // 윈도우 함수와 매크로를 사용하기 위한 윈도우 라이브러리 포함.
#include <stdlib.h> // 표준 라이브러리 함수를 포함.
#include <string.h> // 문자열 관련 함수를 포함.
#include <mysql.h> // MySQL 데이터베이스와 상호 작용하기 위한 함수 포함.

#define HOST "127.0.0.1" //IP address 주는것 loopback address 내컴퓨터에서 할때
#define NAME "project" //db이름
#define USER "root" //관리자 root
#define PASS "abc123" //비밀번호
#define PORT 3307 //포트 번호
#define MAX_X 40 // 게임 보드의 최대 가로 좌표 값을 정의.
#define MAX_Y 20 // 게임 보드의 최대 세로 좌표 값을 정의.
#define LETTER_CNT 1024 // 한 번에 게임 보드에 표시될 수 있는 최대 글자 수를 정의.

struct Node {
    char ch; // 탄막의 문자 값 저장.
    int x; // 탄막의 가로 좌표 값을 저장.
    int y; // 탄막의 세로 좌표 값을 저장.
    int flag; // 탄막이 활성 또는 비활성 상태인지를 결정하는 값을 저장.
    int life; // 탄막의 남아있는 수명을 나타내는 life 값을 저장.
    int speed; // 탄막 낙하 속도를 제어하는 speed 값을 저장.
};

struct Player {
    char id[20]; // 사용자 ID 저장
    // 다른 필요한 멤버 변수들을 추가할 수 있습니다.
}player;



void frontMenu(); // 게임의 오프닝 메뉴
void mainMenu(); // 게임의 메인 메뉴
void levelSelectMenu(); // 플레이어가 게임 단계를 선택하는 메뉴
int gameStart(); // 게임을 시작하고 모든 게임 작업을 처리
int randx(); // 가로 좌표를 무작위로 생성하는 함수
void gotoxy(); // 커서를 특정 XY 좌표 위치로 설정하는 gotoxy 함수
void textcolor(); // 텍스트 색상을 설정하는 textcolor 함수
void gameboard(); // 게임 보드를 콘솔에 그리고 업데이트하는 함수
void login(); //로그인을 수행하는 함수
void loginboard(); //로그인 화면을 그리는 함수
void printHighScore(); //최고점수를 출력하는 함수