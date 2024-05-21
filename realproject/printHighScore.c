#include "a.h" // a.h 헤더 파일을 포함합니다.

void printHighScore()
{
    MYSQL sql = { 0 }; // MYSQL 구조체 변수를 초기화함.
    MYSQL* conn = NULL; // MYSQL 포인터 변수를 선언하고 NULL로 초기화함.
    MYSQL_RES* result = NULL; // MYSQL 결과 구조체 변수를 초기화함.
    MYSQL_ROW row = { 0 }; // MYSQL 행 구조체 변수를 초기화함.

    mysql_init(&sql); // MYSQL 구조체를 초기화합니다.
    conn = mysql_real_connect(&sql, HOST, USER, PASS, NAME, PORT, NULL, 0); // MYSQL 서버에 연결.

    if (conn == NULL)
    {
        fprintf(stderr, "에러정보 : %s\n", mysql_error(&sql));
        return;
    }

    char buffer[200] = { 0 }; // 쿼리를 저장할 문자열 버퍼를 선언하고 0으로 초기화함.
    sprintf(buffer, "SELECT id, score FROM login WHERE score > 0 ORDER BY score DESC"); // 쿼리를 생성.

    if (mysql_query(conn, buffer) != 0)
    {
        fprintf(stderr, "에러정보 : %s\n", mysql_error(&sql));
        return;
    }

    result = mysql_store_result(conn); // 실행 결과를 저장함.

    if (result == NULL)
    {
        fprintf(stderr, "에러정보 : %s\n", mysql_error(&sql));
        return;
    }

    int startY = 10; // 출력 시작 위치(y값)

    system("cls"); // 화면을 초기화함.

    gotoxy(20, startY++);
    printf("               LEADER BOARD"); // 리더 보드 제목을 출력.
    gotoxy(20, startY++);
    printf("========================================\n");

    while ((row = mysql_fetch_row(result)) != NULL)
    {
        gotoxy(25, startY++);
        printf("ID: %-10s  |  최고 점수: %-10s\n", row[0], row[1]); // ID와 최고 점수를 출력.
    }

    gotoxy(20, startY++);
    printf("========================================\n"); 
    gotoxy(20, startY++);

    mysql_free_result(result); 
    mysql_close(conn); // DB연결 종료.
}
