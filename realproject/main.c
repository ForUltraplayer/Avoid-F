#include "a.h" // a.h 헤더 파일 포함

void main()
{
    system("mode con cols=80 lines=30"); // 콘솔 크기 설정

    int select; // 메뉴 선택을 위한 변수
    int tmpScore = 0; // 인게임 점수를 저장하는 변수
    int maxScore = 0; // 최고 점수를 저장하는 변수

    login();
    frontMenu(); // 타이틀 출력
    system("cls"); // 화면 초기화

    MYSQL sql = { 0 }; // SQL 관련 변수
    MYSQL* conn = NULL;
    MYSQL_RES* result = NULL;
    MYSQL_ROW row = { 0 };

    mysql_init(&sql);
    conn = mysql_real_connect(&sql, HOST, USER, PASS, NAME, PORT, NULL, 0);

    if (conn == NULL)
    {
        fprintf(stderr, "에러정보 : %s\n", mysql_error(&sql));
        return;
    }

    while (1)
    {
        system("cls"); // 화면 초기화
        mainMenu();   // 메인 메뉴 출력
        fflush(stdin); // 입력 버퍼 초기화
        scanf("%d", &select); // 난이도 입력 받기
        system("cls"); // 화면 초기화

        switch (select)
        {
        case 1:
            // 게임 시작 (selected 1)
            tmpScore = gameStart();
            // 게임을 시작하고 점수를 얻어옴
            break;
        case 2:
        {
            printHighScore(); // 최고 점수 조회 및 출력
            system("pause");
            // 사용자의 키 입력을 대기
            break;
        }
        case 0:
            // 종료 (selected 0)
            return;
            // 프로그램을 종료
        default:
            
            // 잘못된 입력 시
            break;
        }
    }
}
