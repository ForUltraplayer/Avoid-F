#include "a.h"


void saveScore(int score) {
    MYSQL sql = { 0 };
    MYSQL* conn = NULL;
    char buffer[200] = { 0 };

    mysql_init(&sql);
    conn = mysql_real_connect(&sql, HOST, USER, PASS, NAME, PORT, NULL, 0);

    if (conn == NULL)
        fprintf(stderr, "에러정보 : %s\n", mysql_error(&sql));

    sprintf(buffer, "UPDATE login SET score = %d WHERE id = '%s'", score);
    mysql_query(conn, buffer);
    mysql_close(conn);
}
