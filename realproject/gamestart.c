#include "a.h"


int gameStart() //실제 게임이 구동되는 함수
{
        int select;     //사용자가 선택한 난이도를 저장하는 변수
        struct Node letter[LETTER_CNT]; //떨어지는 탄막들의 정보를 담는 구조체 LETTER_CNT는 배열의 크기
        int i; //반복문에 사용할 인덱스 변수
        int randVar, speed1, speed2; //난이도에 따라 설정될 떨어지는 문자의 수와 탄막의 속도를 조절하기 위한 변수

        //randVar : 문자 생성 확률을 결정하는데 사용하는 변수
        //speed1 : 떨어지는 문자속도 범위의 최소값
        //speed2 : 떨어지는 문자속도 범위의 최대값

        char ch; //키보드의 입력을 받을때 사용할 변수
        int playerX = 20, playerY = MAX_Y; //플레이어 캐릭터의 현재위치를 나타내는 변수
        int score = 0; //게임의 점수를 저장할 변수 

        MYSQL sql = { 0 }; //MYSQL 구조체 변수를 초기화
        MYSQL* conn = NULL; //MYSQL 포인터 변수를 선언하고 NULL로 초기화
        mysql_init(&sql); //MYSQL구조체를 초기화
        conn = mysql_real_connect(&sql, HOST, USER, PASS, NAME, PORT, NULL, 0); // MYSQL 서버에 연결



    // 메인 게임 루프
    while (1)
    {
        levelSelectMenu(); // 난이도 선택 메뉴 출력 함수 호출
        fflush(stdin); // 입력 버퍼 초기화
        scanf("%d", &select); // 사용자의 선택 값을 변수에 저장
        system("cls"); // 화면 초기화
        gameboard(); // 게임 보드를 만드는 함수 호출
        gotoxy(45, 6);
        printf("현재 플레이어 ID: %s\n", player.id);  // 현재 플레이어의 ID를 출력.
        gotoxy(45, 5);
        printf("▤ 점수 : %d ", score); // 현재 점수를 출력.
        


        // 각 난이도에 따른 설정
        if (select == 1) //초급을 선택한 경우
        {
            randVar = 20;
            speed1 = 10;
            speed2 = 20;
            break;
        }
        else if (select == 2) //중급을 선택한 경우
        {
            randVar = 10;
            speed1 = 5;
            speed2 = 10;
            break;
        }
        else if (select == 3) //고급을 선택한 경우
        {
            randVar = 5;
            speed1 = 2;
            speed2 = 5;
            break;
        }
        else if (select == 0) return 0; //돌아가기를 선택한 경우
        else     continue; //잘못된 입력이 들어왔다면 반복문을 재실행함
    }

    // 탄막 구조체 배열의 초기 설정
    for (i = 0; i < LETTER_CNT; i++) letter[i].flag = 0;

   //선택한 난이도를 보여주는 함수
    gotoxy(45, 1);
    printf("▤ 난이도 : ");
    if (select == 1) printf("초급");
    else if (select == 2) printf("중급");
    else if (select == 3) printf("고급");

    // 게임 실행 중 루프
    while (1)
    {
        // 새로운 탄막 생성되는 조건 (난수 발생)
        if (randx(0, randVar) == 0)
            
        {
            // 탄막 구조체 배열에서 사용 가능한 요소 찾기
            for (i = 0; i < LETTER_CNT; i++)
            {
                // 플래그가 설정되어 있지 않으면 해당 위치에 새로운 탄막 설정
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

        // 탄막 상태 업데이트
        for (i = 0; i < LETTER_CNT; i++)
        {
            if (letter[i].flag == 1)
            {
                
                if (--letter[i].life == 0)
                {
                    letter[i].life = letter[i].speed;

                    // 탄막 제거
                    gotoxy(letter[i].x, letter[i].y);
                    printf("%c", letter[i].ch);
                    printf("\b ");

                    // 탄막 한 칸 내리고 새로운 위치에 재출력
                    gotoxy(letter[i].x, ++letter[i].y);
                    printf("%c", letter[i].ch);

                    // 탄막이 게임보드 바닥에 도달
                    if (letter[i].y == 20) {
                        printf("\b ");
                        letter[i].flag = 0;

                        // 플레이어와 탄막 충돌시
                        if (letter[i].x == playerX || letter[i].x == playerX + 1) {
                            // 기존 점수를 불러옴
                            MYSQL_RES* result;
                            MYSQL_ROW row;
                            char query[100];

                            sprintf(query, "SELECT score FROM login WHERE id = '%s'", player.id);
                            mysql_query(conn, query);
                            result = mysql_store_result(conn);

                            if (result != NULL) {
                                row = mysql_fetch_row(result);
                                int previousScore = atoi(row[0]); // 기존 점수를 정수형으로 변환
                                mysql_free_result(result);

                                if (score > previousScore) {
                                    // 점수 업데이트
                                    sprintf(query, "UPDATE login SET score = %d WHERE id = '%s'", score, player.id);
                                    mysql_query(conn, query);
                                }
                            }

                            gotoxy(45, 10);
                            printf("게임 오버! \n ");
                            gotoxy(45, 12);
                            printf("아무 키나 누르세요.");
                            system("pause>nul"); // 아무 키나 눌러도 바로 넘어가도록 설정
                            return score;
                        }
                        else {
                            // 점수 증가
                            score++;
                            gotoxy(45, 5);
                            printf("▤ 점수 : %d ", score);
                        }
                    }

                }
            }
        }
        // 지연 시간
        Sleep(5);

        gotoxy(playerX, playerY); //최초 플레이어 위치 정의
        printf("△"); //플레이어 캐릭터 출력

        if (kbhit()) //키보드 방향키 조작 함수 키가 눌러지면 1을 반환, 그렇지 않으면 0을 반환한다.
        {
            ch = getch(); //키보드에서 입력된 키 값을 변수 ch에 저장
            switch (ch)
            {
            case 75: //ASCII코드 75 : 왼쪽방향키  == 왼쪽으로 이동시
                if (playerX > 2) //최대 이동거리 제한
                {
                    printf(" "); //캐릭터가 이전에 있던 위치를 지우기 위해 사용
                    playerX--; //x값을 1만큼감소 == 왼쪽으로 이동
                    gotoxy(playerX, playerY); // 새로운 위치로 커서 이동
                    printf("Δ"); // 새로운 위치에 캐릭터 출력
                }
                break;
            case 77: //ASCII코드 77 : 오른쪽 방향키 == 오른쪽으로 이동
                if (playerX < 39) //최대 이동거리 제한
                {
                    printf(" "); //캐릭터가 이전에 있던 위치를 지우기 위해 사용
                    playerX++; //x값을 1만큼 증가 == 오른쪽으로 이동
                    gotoxy(playerX, playerY); // 새로운 위치로 커서 이동
                    printf("Δ"); // 새로운 위치에 캐릭터 출력
                }
                break;
            default:
                break;
            }
        }

    }
    mysql_close(conn);

}
