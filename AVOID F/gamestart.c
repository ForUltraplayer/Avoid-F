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

    while (1)
    {
        levelSelectMenu(); //레벨선택메뉴 출력
        fflush(stdin); //입력버퍼 비우기
        scanf("%d", &select); //난이도 선택 입력받음
        system("cls"); //화면을 지움
        gameboard(); //게임판을 그림

        if (select == 1) //초급
        {
            randVar = 20;
            speed1 = 10;
            speed2 = 20;
            break;
        }
        else if (select == 2) //중급
        {
            randVar = 10;
            speed1 = 5;
            speed2 = 10;
            break;
        }
        else if (select == 3) //고급
        {
            randVar = 5;
            speed1 = 2;
            speed2 = 5;
            break;
        }
        else if (select == 0) return 0; //돌아가기
        else     continue;
    }

    //선택한 난이도를 보여주는 함수
    gotoxy(45, 1);
    printf("▤ 난이도 : ");
    if (select == 1) printf("초급");
    else if (select == 2) printf("중급");
    else if (select == 3) printf("고급");

    //총알생성함수, 난수생성함수, 총알낙하함수, 점수휙득함수 등등 구현 예정

    while (1)
    {
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

}
