#include "a.h" // a.h ��� ������ �����մϴ�.

void printHighScore()
{
    MYSQL sql = { 0 }; // MYSQL ����ü ������ �ʱ�ȭ��.
    MYSQL* conn = NULL; // MYSQL ������ ������ �����ϰ� NULL�� �ʱ�ȭ��.
    MYSQL_RES* result = NULL; // MYSQL ��� ����ü ������ �ʱ�ȭ��.
    MYSQL_ROW row = { 0 }; // MYSQL �� ����ü ������ �ʱ�ȭ��.

    mysql_init(&sql); // MYSQL ����ü�� �ʱ�ȭ�մϴ�.
    conn = mysql_real_connect(&sql, HOST, USER, PASS, NAME, PORT, NULL, 0); // MYSQL ������ ����.

    if (conn == NULL)
    {
        fprintf(stderr, "�������� : %s\n", mysql_error(&sql));
        return;
    }

    char buffer[200] = { 0 }; // ������ ������ ���ڿ� ���۸� �����ϰ� 0���� �ʱ�ȭ��.
    sprintf(buffer, "SELECT id, score FROM login WHERE score > 0 ORDER BY score DESC"); // ������ ����.

    if (mysql_query(conn, buffer) != 0)
    {
        fprintf(stderr, "�������� : %s\n", mysql_error(&sql));
        return;
    }

    result = mysql_store_result(conn); // ���� ����� ������.

    if (result == NULL)
    {
        fprintf(stderr, "�������� : %s\n", mysql_error(&sql));
        return;
    }

    int startY = 10; // ��� ���� ��ġ(y��)

    system("cls"); // ȭ���� �ʱ�ȭ��.

    gotoxy(20, startY++);
    printf("               LEADER BOARD"); // ���� ���� ������ ���.
    gotoxy(20, startY++);
    printf("========================================\n");

    while ((row = mysql_fetch_row(result)) != NULL)
    {
        gotoxy(25, startY++);
        printf("ID: %-10s  |  �ְ� ����: %-10s\n", row[0], row[1]); // ID�� �ְ� ������ ���.
    }

    gotoxy(20, startY++);
    printf("========================================\n"); 
    gotoxy(20, startY++);

    mysql_free_result(result); 
    mysql_close(conn); // DB���� ����.
}
