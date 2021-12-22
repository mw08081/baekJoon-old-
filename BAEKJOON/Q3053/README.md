## M_PI 사용
`#include <cmath>`에서 M_PI 값(3.141592...)를 사용하려면 어떠한 include보다 먼저 해당 정의를 선언해줘야 한다 

`#define _USE_MATH_DEFINES`  
  
M_PI말고도 M_E값 등등 있다  
![mathDefines](https://user-images.githubusercontent.com/58582985/146742884-c43e42f9-a72b-469d-82f2-2c7b5162e79e.PNG)  
　  
　  
## Pow() vs Powl()
`pow()`는 오버로딩 함수가 4가지 정도 존재하며, r 값과 제곱값은 다양한 데이터 타입이 가능하다
마지막 오버로딩함수는 템플릿 함수이므로 다양한 데이터를 활용할 수 있었다  
  
반면 powl()함수는 long double형을 반환하고, 매개변수도 모두 long double 전용이였다
　  
　  
　  
　  
+++ https://github.com/mw08081/baekJoon/blob/main/BAEKJOON/Q3053/main.cpp  
