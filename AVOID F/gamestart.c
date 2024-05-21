#include "a.h"


int gameStart() //���� ������ �����Ǵ� �Լ�
{
    int select;     //����ڰ� ������ ���̵��� �����ϴ� ����
    struct Node letter[LETTER_CNT]; //�������� ź������ ������ ��� ����ü LETTER_CNT�� �迭�� ũ��
    int i; //�ݺ����� ����� �ε��� ����
    int randVar, speed1, speed2; //���̵��� ���� ������ �������� ������ ���� ź���� �ӵ��� �����ϱ� ���� ����

    //randVar : ���� ���� Ȯ���� �����ϴµ� ����ϴ� ����
    //speed1 : �������� ���ڼӵ� ������ �ּҰ�
    //speed2 : �������� ���ڼӵ� ������ �ִ밪

    char ch; //Ű������ �Է��� ������ ����� ����
    int playerX = 20, playerY = MAX_Y; //�÷��̾� ĳ������ ������ġ�� ��Ÿ���� ����
    int score = 0; //������ ������ ������ ���� 

    while (1)
    {
        levelSelectMenu(); //�������ø޴� ���
        fflush(stdin); //�Է¹��� ����
        scanf("%d", &select); //���̵� ���� �Է¹���
        system("cls"); //ȭ���� ����
        gameboard(); //�������� �׸�

        if (select == 1) //�ʱ�
        {
            randVar = 20;
            speed1 = 10;
            speed2 = 20;
            break;
        }
        else if (select == 2) //�߱�
        {
            randVar = 10;
            speed1 = 5;
            speed2 = 10;
            break;
        }
        else if (select == 3) //���
        {
            randVar = 5;
            speed1 = 2;
            speed2 = 5;
            break;
        }
        else if (select == 0) return 0; //���ư���
        else     continue;
    }

    //������ ���̵��� �����ִ� �Լ�
    gotoxy(45, 1);
    printf("�� ���̵� : ");
    if (select == 1) printf("�ʱ�");
    else if (select == 2) printf("�߱�");
    else if (select == 3) printf("���");

    //�Ѿ˻����Լ�, ���������Լ�, �Ѿ˳����Լ�, �����׵��Լ� ��� ���� ����

    while (1)
    {
        gotoxy(playerX, playerY); //���� �÷��̾� ��ġ ����
        printf("��"); //�÷��̾� ĳ���� ���

        if (kbhit()) //Ű���� ����Ű ���� �Լ� Ű�� �������� 1�� ��ȯ, �׷��� ������ 0�� ��ȯ�Ѵ�.
        {
            ch = getch(); //Ű���忡�� �Էµ� Ű ���� ���� ch�� ����
            switch (ch)
            {
            case 75: //ASCII�ڵ� 75 : ���ʹ���Ű  == �������� �̵���
                if (playerX > 2) //�ִ� �̵��Ÿ� ����
                {
                    printf(" "); //ĳ���Ͱ� ������ �ִ� ��ġ�� ����� ���� ���
                    playerX--; //x���� 1��ŭ���� == �������� �̵�
                    gotoxy(playerX, playerY); // ���ο� ��ġ�� Ŀ�� �̵�
                    printf("��"); // ���ο� ��ġ�� ĳ���� ���
                }
                break;
            case 77: //ASCII�ڵ� 77 : ������ ����Ű == ���������� �̵�
                if (playerX < 39) //�ִ� �̵��Ÿ� ����
                {
                    printf(" "); //ĳ���Ͱ� ������ �ִ� ��ġ�� ����� ���� ���
                    playerX++; //x���� 1��ŭ ���� == ���������� �̵�
                    gotoxy(playerX, playerY); // ���ο� ��ġ�� Ŀ�� �̵�
                    printf("��"); // ���ο� ��ġ�� ĳ���� ���
                }
                break;
            default:
                break;
            }
        }
    }

}
