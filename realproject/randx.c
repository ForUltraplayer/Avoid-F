#include "a.h"


int randx(int x, int y)
{
    static int flag = 0;
    int retVal;
    // �ʱ� ���� �õ带 �������� �ʾҴٸ� �õ� ���� ���� ����
    if (flag == 0)
    {
     srand(time(NULL)); // ���� �ð��� ������� ���� �õ� ����
     rand(); rand(); rand(); rand(); // ó�� �����Ǵ� ���� ���� �Ѿ�� ���� rand() �Լ� ȣ��
     srand(rand()); // ���ο� ���� �õ� ����
     flag = 1; // �÷��׸� 1�� �����Ͽ� �ʱ� ���� �õ� ���� ǥ��
    }
    retVal = rand() % (y - x + 1) + x; // x�� y ������ ���� ����
    return retVal; // ������ ���� ��ȯ
}
