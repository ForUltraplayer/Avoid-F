#pragma once

#include <stdio.h> //ǥ�� ����� ���̺귯��, printf()�� scanf()�� ����ϱ�����
#include <conio.h> //�ܼ� ����� ���̺귯��, kbhit() �Լ��� ����ϱ� ���� ����� 
#include <time.h>  //�ð� ���� ���̺귯��, ���� ������ ���Ǵ� srand()�� time()�Լ��� ����ϱ� ����
#include <windows.h> //������ �ü�� ���� ���̺귯��, Sleep(), gotoxy() ���� �Լ��� ����ϱ� ����

#define MAX_X 40 //�ִ� x��ǥ�� ����
#define MAX_Y 20 //�ִ� y��ǥ�� ����
#define LETTER_CNT 1024 //�ִ� ź�� ���� ����

struct Node {  //ź������ ȿ�������� �����ϱ� ���� ����ü ���
    char ch;   //ź���� ����� ���ڷ� ����ϱ�����
    int x;     //x��ǥ
    int y;     //y��ǥ
    int flag;  //���� Ȱ������ ���� (1 = Ȱ�� , 0 = ��Ȱ��)
    int life;  //���������ð�
    int speed; //�ӵ�
};


void frontMenu(); //���� ����Ÿ��Ʋ�� ����ϴ� �Լ�
void mainMenu(); //������ ���θ޴��� ����ϴ� �Լ�
void levelSelectMenu(); //������ ������ �����ϴ� â�� ����ϴ� �Լ�
int gameStart(); //��ü���� ���� ����
void gotoxy(); //gotoxy�� ����ϰ� ���ִ� �Լ�
void textcolor(); //text�� �÷��� ��� �� �� �ְ� ���ִ� �Լ�
void gameboard(); //�������� ����ϴ� �Լ� 
