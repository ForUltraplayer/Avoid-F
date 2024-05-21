#include "a.h" // a.h ��� ������ ������.

void login() {
    MYSQL sql = { 0 }; // MYSQL ����ü ������ �ʱ�ȭ��.
    MYSQL* conn = NULL; // MYSQL ������ ������ �����ϰ� NULL�� �ʱ�ȭ��.
    MYSQL_RES* result = NULL; // MYSQL ��� ����ü ������ �ʱ�ȭ��.
    MYSQL_ROW row = { 0 }; // MYSQL �� ����ü ������ �ʱ�ȭ��.

    char id[20] = { 0 }; // ���̵� ������ ���ڿ� ������ �����ϰ� 0���� �ʱ�ȭ��.
    char pass[20] = { 0 }; // �н����带 ������ ���ڿ� ������ �����ϰ� 0���� �ʱ�ȭ��.
    char buffer[200] = { 0 }; // ������ ������ ���ڿ� ���۸� �����ϰ� 0���� �ʱ�ȭ��.

    int x = 15; // �޴��� ����� x ��ǥ�� ����.
    int y = 8; // �޴��� ����� y ��ǥ�� ����.

    mysql_init(&sql); // MYSQL ����ü�� �ʱ�ȭ��.
    conn = mysql_real_connect(&sql, HOST, USER, PASS, NAME, PORT, NULL, 0); // MYSQL ������ �����մϴ�.

    if (conn == NULL)
        fprintf(stderr, "�������� : %s\n", mysql_error(&sql));

    int login_success = 0; // �α��� ���� ���θ� ��Ÿ���� ������ 0���� �ʱ�ȭ��.
    int login_failed = 0; // �α��� ���� ���θ� ��Ÿ���� ������ 0���� �ʱ�ȭ��.

    while (!login_success && !login_failed) {
        char answer = { 0 }; // ������� ������ ������ ������ 0���� �ʱ�ȭ��.

        loginboard(); // �α��� ȭ���� ����ϴ� �Լ��� ȣ��.

        answer = getchar(); // ������� �Է��� ����.
        while (getchar() != '\n'); // ���۸� ���.

        if (answer == '1') { // �α����� ������ ���
            system("cls"); // ȭ���� �ʱ�ȭ.
            gotoxy(x + 4, 10);
            printf("���̵� �Է� : ");
            gets(id); // ���̵� �Է¹���.
            gotoxy(x + 4, 12);
            printf("�н����带 �Է� : ");
            gets(pass); // �н����带 �Է¹���.

            sprintf(buffer, "select * from login where id = '%s' and pass ='%s'", id, pass); // ������ �����մϴ�.
            mysql_query(conn, buffer); // ������ �����մϴ�.

            result = mysql_store_result(conn); // ���� ����� ����.
            while ((row = mysql_fetch_row(result)) != NULL) {
                if (strcmp(row[0], id) == 0 && strcmp(row[1], pass) == 0) {
                    login_success = 1; // �α��� ����
                    strcpy(player.id, id); // �÷��̾��� ���̵� ����.
                }
            }

            if (login_success == 1) {
                gotoxy(x + 4, 18);
                printf("�α��� ����! ������ �����Ϸ��� �ƹ�Ű�� �����ʽÿ�.\n");
                getchar();
                while (getchar() != '\n'); // ���۸� ���.
                system("cls");
                frontMenu(); // ���� ���� �޴��� �̵�.
            }
            else { // �α��� ����
                gotoxy(x + 4, 18);
                printf("�α��� ����! �ٽ� �õ��Ͻʽÿ�. �ƹ�Ű�� �����ʽÿ�.\n");
                getchar();
                while (getchar() != '\n'); // ���۸� ���.
                system("cls");
            }
        }
        if (answer == '2') { // ȸ�������� ������ ���
            system("cls"); // ȭ���� �ʱ�ȭ��.
            gotoxy(x + 4, 15);
            printf("���̵� �Է� : ");
            gets(id); // ���̵� �Է¹���.
            gotoxy(x + 4, 16);
            printf("�н����带 �Է� : ");
            gets(pass); // �н����带 �Է¹���.

            sprintf(buffer, "insert into login values('%s','%s',0)", id, pass); // ������ ����.
            int queryResult = mysql_query(conn, buffer); // ������ �����ϰ� ����� ����.

            if (queryResult) { // ���� �߻� ��
                gotoxy(x + 4, 18);
                printf("ȸ������ �� ���� �߻�: %s\n", mysql_error(conn));
                printf("�ƹ�Ű�� �������� ...\n");
                getchar();
                while (getchar() != '\n'); // ���۸� ���.
                system("cls");
            }
            else { // ȸ������ ���� ��
                gotoxy(x + 4, 18);
                printf("ȸ������ ����! �ʱ�ȭ������ ���ư����� �ƹ�Ű�� �����ʽÿ�.\n");
                getchar();
                while (getchar() != '\n'); // ���۸� ���.
                system("cls");
            }
        }
        if (answer == '0') { // ���Ḧ ������ ���
            login_failed = 1;
            break;
        }
    }

    if (login_failed) { // �α��� ���� ��
        system("cls");
        printf("���α׷��� �����մϴ�.\n");
        exit(0);
    }
}
