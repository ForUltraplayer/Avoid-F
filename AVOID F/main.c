#include "a.h"

void main() //메인함수
{
    system("mode con cols=80 lines=30"); //콘솔크기 설정

    int select; //메뉴선택을 위한 변수 
    int tmpScore = 0; //인게임점수를 저장하는 변수
    int maxScore = 0; //최고점수를 저장하는 변수

    frontMenu(); //타이틀 출력

    while (1)
    {
        system("cls"); //화면초기화
        mainMenu();   //메인메뉴 출력
        fflush(stdin); //입력버퍼 초기화
        scanf("%d", &select); //난이도 입력받기
        system("cls"); //화면초기화
        
        switch (select)
        {
        case 1: //게임시작
            tmpScore = gameStart();
            break;
        case 2: //최고점수 출력
            if (maxScore < tmpScore) //기존의 최고점수(maxScore)가 인게임 점수(tmpScore)보다 낮으면 최고점수를 갱신
                maxScore = tmpScore; 

            gotoxy(26, 12);
            printf("▤ 현재 최고 점수는 %d 입니다 \n", maxScore); //최고점수 출력
            gotoxy(26, 17);
            printf("되돌아 가려면 아무 키나 누르세요.");
            system("pause>nul"); // 아무 키나 눌러도 바로 넘어가도록 설정
            break;
        case 0: //초기 메인메뉴로 돌아가기
            return;
        default:
            break;
        }
        
    }
}












