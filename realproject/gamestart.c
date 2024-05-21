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

        MYSQL sql = { 0 }; //MYSQL ����ü ������ �ʱ�ȭ
        MYSQL* conn = NULL; //MYSQL ������ ������ �����ϰ� NULL�� �ʱ�ȭ
        mysql_init(&sql); //MYSQL����ü�� �ʱ�ȭ
        conn = mysql_real_connect(&sql, HOST, USER, PASS, NAME, PORT, NULL, 0); // MYSQL ������ ����



    // ���� ���� ����
    while (1)
    {
        levelSelectMenu(); // ���̵� ���� �޴� ��� �Լ� ȣ��
        fflush(stdin); // �Է� ���� �ʱ�ȭ
        scanf("%d", &select); // ������� ���� ���� ������ ����
        system("cls"); // ȭ�� �ʱ�ȭ
        gameboard(); // ���� ���带 ����� �Լ� ȣ��
        gotoxy(45, 6);
        printf("���� �÷��̾� ID: %s\n", player.id);  // ���� �÷��̾��� ID�� ���.
        gotoxy(45, 5);
        printf("�� ���� : %d ", score); // ���� ������ ���.
        


        // �� ���̵��� ���� ����
        if (select == 1) //�ʱ��� ������ ���
        {
            randVar = 20;
            speed1 = 10;
            speed2 = 20;
            break;
        }
        else if (select == 2) //�߱��� ������ ���
        {
            randVar = 10;
            speed1 = 5;
            speed2 = 10;
            break;
        }
        else if (select == 3) //����� ������ ���
        {
            randVar = 5;
            speed1 = 2;
            speed2 = 5;
            break;
        }
        else if (select == 0) return 0; //���ư��⸦ ������ ���
        else     continue; //�߸��� �Է��� ���Դٸ� �ݺ����� �������
    }

    // ź�� ����ü �迭�� �ʱ� ����
    for (i = 0; i < LETTER_CNT; i++) letter[i].flag = 0;

   //������ ���̵��� �����ִ� �Լ�
    gotoxy(45, 1);
    printf("�� ���̵� : ");
    if (select == 1) printf("�ʱ�");
    else if (select == 2) printf("�߱�");
    else if (select == 3) printf("���");

    // ���� ���� �� ����
    while (1)
    {
        // ���ο� ź�� �����Ǵ� ���� (���� �߻�)
        if (randx(0, randVar) == 0)
            
        {
            // ź�� ����ü �迭���� ��� ������ ��� ã��
            for (i = 0; i < LETTER_CNT; i++)
            {
                // �÷��װ� �����Ǿ� ���� ������ �ش� ��ġ�� ���ο� ź�� ����
                if (letter[i].flag == 0)
                {
                    letter[i].ch = 'F';
                    letter[i].flag = 1;
                    letter[i].x = randx(2, MAX_X);
                    letter[i].y = -1;
                    letter[i].life = randx(50, 200);
                    letter[i].speed = randx(speed1, speed2);
                    break;
                }
            }
        }

        // ź�� ���� ������Ʈ
        for (i = 0; i < LETTER_CNT; i++)
        {
            if (letter[i].flag == 1)
            {
                
                if (--letter[i].life == 0)
                {
                    letter[i].life = letter[i].speed;

                    // ź�� ����
                    gotoxy(letter[i].x, letter[i].y);
                    printf("%c", letter[i].ch);
                    printf("\b ");

                    // ź�� �� ĭ ������ ���ο� ��ġ�� �����
                    gotoxy(letter[i].x, ++letter[i].y);
                    printf("%c", letter[i].ch);

                    // ź���� ���Ӻ��� �ٴڿ� ����
                    if (letter[i].y == 20) {
                        printf("\b ");
                        letter[i].flag = 0;

                        // �÷��̾�� ź�� �浹��
                        if (letter[i].x == playerX || letter[i].x == playerX + 1) {
                            // ���� ������ �ҷ���
                            MYSQL_RES* result;
                            MYSQL_ROW row;
                            char query[100];

                            sprintf(query, "SELECT score FROM login WHERE id = '%s'", player.id);
                            mysql_query(conn, query);
                            result = mysql_store_result(conn);

                            if (result != NULL) {
                                row = mysql_fetch_row(result);
                                int previousScore = atoi(row[0]); // ���� ������ ���������� ��ȯ
                                mysql_free_result(result);

                                if (score > previousScore) {
                                    // ���� ������Ʈ
                                    sprintf(query, "UPDATE login SET score = %d WHERE id = '%s'", score, player.id);
                                    mysql_query(conn, query);
                                }
                            }

                            gotoxy(45, 10);
                            printf("���� ����! \n ");
                            gotoxy(45, 12);
                            printf("�ƹ� Ű�� ��������.");
                            system("pause>nul"); // �ƹ� Ű�� ������ �ٷ� �Ѿ���� ����
                            return score;
                        }
                        else {
                            // ���� ����
                            score++;
                            gotoxy(45, 5);
                            printf("�� ���� : %d ", score);
                        }
                    }

                }
            }
        }
        // ���� �ð�
        Sleep(5);

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
    mysql_close(conn);

}
