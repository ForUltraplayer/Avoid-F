#include "a.h" // a.h 헤더 파일을 포함함.

void login() {
    MYSQL sql = { 0 }; // MYSQL 구조체 변수를 초기화함.
    MYSQL* conn = NULL; // MYSQL 포인터 변수를 선언하고 NULL로 초기화함.
    MYSQL_RES* result = NULL; // MYSQL 결과 구조체 변수를 초기화함.
    MYSQL_ROW row = { 0 }; // MYSQL 행 구조체 변수를 초기화함.

    char id[20] = { 0 }; // 아이디를 저장할 문자열 변수를 선언하고 0으로 초기화함.
    char pass[20] = { 0 }; // 패스워드를 저장할 문자열 변수를 선언하고 0으로 초기화함.
    char buffer[200] = { 0 }; // 쿼리를 저장할 문자열 버퍼를 선언하고 0으로 초기화함.

    int x = 15; // 메뉴를 출력할 x 좌표를 설정.
    int y = 8; // 메뉴를 출력할 y 좌표를 설정.

    mysql_init(&sql); // MYSQL 구조체를 초기화함.
    conn = mysql_real_connect(&sql, HOST, USER, PASS, NAME, PORT, NULL, 0); // MYSQL 서버에 연결합니다.

    if (conn == NULL)
        fprintf(stderr, "에러정보 : %s\n", mysql_error(&sql));

    int login_success = 0; // 로그인 성공 여부를 나타내는 변수를 0으로 초기화함.
    int login_failed = 0; // 로그인 실패 여부를 나타내는 변수를 0으로 초기화함.

    while (!login_success && !login_failed) {
        char answer = { 0 }; // 사용자의 선택을 저장할 변수를 0으로 초기화함.

        loginboard(); // 로그인 화면을 출력하는 함수를 호출.

        answer = getchar(); // 사용자의 입력을 받음.
        while (getchar() != '\n'); // 버퍼를 비움.

        if (answer == '1') { // 로그인을 선택한 경우
            system("cls"); // 화면을 초기화.
            gotoxy(x + 4, 10);
            printf("아이디를 입력 : ");
            gets(id); // 아이디를 입력받음.
            gotoxy(x + 4, 12);
            printf("패스워드를 입력 : ");
            gets(pass); // 패스워드를 입력받음.

            sprintf(buffer, "select * from login where id = '%s' and pass ='%s'", id, pass); // 쿼리를 생성합니다.
            mysql_query(conn, buffer); // 쿼리를 실행합니다.

            result = mysql_store_result(conn); // 실행 결과를 저장.
            while ((row = mysql_fetch_row(result)) != NULL) {
                if (strcmp(row[0], id) == 0 && strcmp(row[1], pass) == 0) {
                    login_success = 1; // 로그인 성공
                    strcpy(player.id, id); // 플레이어의 아이디를 저장.
                }
            }

            if (login_success == 1) {
                gotoxy(x + 4, 18);
                printf("로그인 성공! 게임을 시작하려면 아무키나 누르십시오.\n");
                getchar();
                while (getchar() != '\n'); // 버퍼를 비움.
                system("cls");
                frontMenu(); // 게임 시작 메뉴로 이동.
            }
            else { // 로그인 실패
                gotoxy(x + 4, 18);
                printf("로그인 실패! 다시 시도하십시오. 아무키나 누르십시오.\n");
                getchar();
                while (getchar() != '\n'); // 버퍼를 비움.
                system("cls");
            }
        }
        if (answer == '2') { // 회원가입을 선택한 경우
            system("cls"); // 화면을 초기화함.
            gotoxy(x + 4, 15);
            printf("아이디를 입력 : ");
            gets(id); // 아이디를 입력받음.
            gotoxy(x + 4, 16);
            printf("패스워드를 입력 : ");
            gets(pass); // 패스워드를 입력받음.

            sprintf(buffer, "insert into login values('%s','%s',0)", id, pass); // 쿼리를 생성.
            int queryResult = mysql_query(conn, buffer); // 쿼리를 실행하고 결과를 저장.

            if (queryResult) { // 오류 발생 시
                gotoxy(x + 4, 18);
                printf("회원가입 중 오류 발생: %s\n", mysql_error(conn));
                printf("아무키나 누르세요 ...\n");
                getchar();
                while (getchar() != '\n'); // 버퍼를 비움.
                system("cls");
            }
            else { // 회원가입 성공 시
                gotoxy(x + 4, 18);
                printf("회원가입 성공! 초기화면으로 돌아가려면 아무키나 누르십시오.\n");
                getchar();
                while (getchar() != '\n'); // 버퍼를 비움.
                system("cls");
            }
        }
        if (answer == '0') { // 종료를 선택한 경우
            login_failed = 1;
            break;
        }
    }

    if (login_failed) { // 로그인 실패 시
        system("cls");
        printf("프로그램을 종료합니다.\n");
        exit(0);
    }
}
