## CPP 소수점 표현  
소수점 관련 함수  
- cout.precision(); (... overloading cout.precision(streamsize _tmp);)  
- setprecision();  
- cout << fixed;  

### cout.precision()  
해당 함수를 처음에 소수점을 고정해주는 함수로 착각했다  
이유는 단순했다  
　  
```C++
double dNum = 3.14;

cout.precision(6);
cout << dNum << endl;
```
을 실행한다면 결과는 `3.14000`이 나온다  
소수점 6자리로 설정했는데, 5자리까지만 나온 이유가 내가 착각한 이유와 동일하다  
　  
위의 함수는 출력할 숫자의 자리수를 설정해주는 함수이다(소수점의 자리수를 고정해주는 것이 아니다)  
그렇기에 일의자리 숫자를 제외한 5자리의 소수가 출력된 것이다  
　  
소수점의 자리수를 고정하려면 `cout << fixed;`를 이용하면 된다(뒤에서 설명)  
　  
cout.precision()을 좀 더 설명하자면 다음과 같다  
```c++
std::streamsize precision() const  
+ overload std::streamsize std::ios_base::precision(std::streamsize _Newprecision)  

streamsize __CLR_OR_THIS_CALL precision(streamsize _Newprecision) { // set precision to argument
        const streamsize _Oldprecision = _Prec;
        _Prec                          = _Newprecision;
        return _Oldprecision;
}
```
cout.precision()은 입출력 계산에서 사용되는 stream의 자릿수를 결정해주는 것이다  
자릿수는 `streamsize`라는 type으로써(long long) 사용된다  
　  
cout.precision()은 기본적으로 기존 streamsize를 반환한다  
따라서 특정 정밀한 작업이 끝난 후에는 기존의 streamsize로 돌려주는 것이 필요한데 아래와 같이 할 수 있다  
```c++
double dNum = 1 / 3;
streamsize originSize = cout.precision();

cout.precision(16);         //set decimal places to 16
cout << dNum << endl;

cout.precision(originSize);
```
　  
+++ streamsize 라는 type은 iosfwd에 정의되어있고, 
