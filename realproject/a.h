#pragma once // �� ��� ������ �� ���� ���Եǵ��� ��.

#include <stdio.h> // ǥ�� ����� ���̺귯�� ����.
#include <conio.h> // �������� ���� �ܼ� �Է� �� ��� ���̺귯�� ����.
#include <time.h> // ���� ���� �� �ð� ������ ���� �ð� ���̺귯�� ����.
#include <windows.h> // ������ �Լ��� ��ũ�θ� ����ϱ� ���� ������ ���̺귯�� ����.
#include <stdlib.h> // ǥ�� ���̺귯�� �Լ��� ����.
#include <string.h> // ���ڿ� ���� �Լ��� ����.
#include <mysql.h> // MySQL �����ͺ��̽��� ��ȣ �ۿ��ϱ� ���� �Լ� ����.

#define HOST "127.0.0.1" //IP address �ִ°� loopback address ����ǻ�Ϳ��� �Ҷ�
#define NAME "project" //db�̸�
#define USER "root" //������ root
#define PASS "abc123" //��й�ȣ
#define PORT 3307 //��Ʈ ��ȣ
#define MAX_X 40 // ���� ������ �ִ� ���� ��ǥ ���� ����.
#define MAX_Y 20 // ���� ������ �ִ� ���� ��ǥ ���� ����.
#define LETTER_CNT 1024 // �� ���� ���� ���忡 ǥ�õ� �� �ִ� �ִ� ���� ���� ����.

struct Node {
    char ch; // ź���� ���� �� ����.
    int x; // ź���� ���� ��ǥ ���� ����.
    int y; // ź���� ���� ��ǥ ���� ����.
    int flag; // ź���� Ȱ�� �Ǵ� ��Ȱ�� ���������� �����ϴ� ���� ����.
    int life; // ź���� �����ִ� ������ ��Ÿ���� life ���� ����.
    int speed; // ź�� ���� �ӵ��� �����ϴ� speed ���� ����.
};

struct Player {
    char id[20]; // ����� ID ����
    // �ٸ� �ʿ��� ��� �������� �߰��� �� �ֽ��ϴ�.
}player;



void frontMenu(); // ������ ������ �޴�
void mainMenu(); // ������ ���� �޴�
void levelSelectMenu(); // �÷��̾ ���� �ܰ踦 �����ϴ� �޴�
int gameStart(); // ������ �����ϰ� ��� ���� �۾��� ó��
int randx(); // ���� ��ǥ�� �������� �����ϴ� �Լ�
void gotoxy(); // Ŀ���� Ư�� XY ��ǥ ��ġ�� �����ϴ� gotoxy �Լ�
void textcolor(); // �ؽ�Ʈ ������ �����ϴ� textcolor �Լ�
void gameboard(); // ���� ���带 �ֿܼ� �׸��� ������Ʈ�ϴ� �Լ�
void login(); //�α����� �����ϴ� �Լ�
void loginboard(); //�α��� ȭ���� �׸��� �Լ�
void printHighScore(); //�ְ������� ����ϴ� �Լ�