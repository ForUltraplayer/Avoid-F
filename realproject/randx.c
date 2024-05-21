#include "a.h"


int randx(int x, int y)
{
    static int flag = 0;
    int retVal;
    // 초기 난수 시드를 설정하지 않았다면 시드 설정 과정 수행
    if (flag == 0)
    {
     srand(time(NULL)); // 현재 시간을 기반으로 난수 시드 설정
     rand(); rand(); rand(); rand(); // 처음 생성되는 난수 값을 넘어가기 위한 rand() 함수 호출
     srand(rand()); // 새로운 난수 시드 설정
     flag = 1; // 플래그를 1로 변경하여 초기 난수 시드 설정 표시
    }
    retVal = rand() % (y - x + 1) + x; // x와 y 사이의 난수 생성
    return retVal; // 생성된 난수 반환
}
