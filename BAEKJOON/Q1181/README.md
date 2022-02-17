# string compare mechanism

string type의 데이터를 사전순으로 정렬할때, 두 string을 비교해야한다  
오늘 알아볼 비교방법은 두가지이다  

## string class operator overloading '<'
첫번째 방법은 string class에 구현된 연산자 오버로딩을 사용하는 것이다  

string class에는 다음과 같은 연산자 오버로딩이 포함되어있다고 한다  
```c++
String& String::operator< (const String & s)
{
    ...
}
```
단순하게 크기 비교를 통해 결과를 도출하므로 결과는 true/false로 반환된다

## string Header compare method 'string.compare()'
해당 방법은 string Header에 있는 compare() 함수를 이용하는 것이다  
　  
```c++
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str1 = "a";
    string str2 = "b";
    string str3 = "c";
   
    //A.compare(B);
    cout << "res(a vs b) : " << str1.compare(str2) << '\n';             //-1
    cout << "res(c vs b) : " << str3.compare(str2) << '\n';             // 1
    cout << "res(b vs b) : " << str2.compare(str2) << '\n';             // 0
    
    return 0;
}
```
이 방법은 비교기준 문자열(A)을 기준으로 비교기준 문자열(A)이 비교대상 문자열(B)보다 더 작은지, 더 큰지, 같은지 -1, 0, 1 값으로 나타낸다
