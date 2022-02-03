# string compare mechanism

string type의 데이터를 사전순으로 정렬할때, 두 string을 비교해야한다  
오늘 알아볼 비교방법은 두가지이다  

## string class operator overloading '<'
첫번째 방법은 string class에 구현된 연산자 오버로딩을 사용하는 것이다  

string class에는 다음과 같은 연산자 오버로딩이 포함되어있다고 한다  
```c++
#include <cstring>
...

String& String::operator== (const String & s)
{
    return strcmp(str, s.str) ? false : true;
}
```
이 코드를 분석하면 단순하게 같은지 
