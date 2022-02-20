#include <stdio.h>

int main()
{
    int num1 = 10;
    int num2 = 12;
    int result1, result2, result3;
                                  //대 입  연산자

    //참, true - 그렇다, 0 이 아닌 수 (1)  거짓, false - 아니다, 0                    //관계/비교연산자
    result1 = (num1 == 10 && num2 == 12);     
    result2 = !(num1 < 12 || num2 > 12);       
    result3 = (!num1);                


    printf("result 1 : %d\n", result1);
    printf("result 2 : %d\n", result2);
    printf("result 3 : %d\n", result3);

    printf("%d %d \n", num1, num2);                     // 12 12


    return 0;
}
