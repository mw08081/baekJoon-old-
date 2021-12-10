## CPP 소수점 표현  
소수점 관련 함수  
- cout.precision(); (... overloading cout.precision(streamsize _tmp);)  
- cout << fixed;  
- setprecision();  

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
그렇기에 일의자리 숫자 한자리를 제외한 5자리의 소수가 출력된 것이고 만약 dNum이 153.65이었다면 153.650으로 출력됬을 것이다  
　  
따라서 소수점의 자리수를 고정하려면 `cout << fixed;`를 이용하면 된다(뒤에서 설명)  
　  
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
streamsize는 ![streamsizePath](https://user-images.githubusercontent.com/58582985/145427782-c608cf17-de1b-4538-adcf-09301bbe6b34.PNG)에 정의되어있고  
cout.precision()은 ![precisionPath](https://user-images.githubusercontent.com/58582985/145427773-b5f1f418-f979-4f40-aee1-816716d128c3.PNG)에 정의되어있다  
  
### cout << fixed;
결국 소수점의 자리수를 고정하려면 위의 내용을 입력해줘야한다  
아래는 cout << fixed 유뮤에 따른 결과이다
```c++
double dNum = 156.34;

cout.precision(6);

cout << dNum << endl;                   //156.340

cout << fixed;
cout << dNum << endl;                   //156.340000
```

### setprecision(streamsize)
사실 setprecision()과 cout.precision()의 차이를 잘 모르겠다  
또 setprecision()의 사용법도 잘 모르겠다 아래의 코드를 살펴보자  
　  
#상황1
```c++
setprecision(16);
cout << 1 / 3 << endl;          //0.333333
```
설정이 되지 않는다  
　  
#상황2  
```c++
cout << fixed << setprecision(16);
cout << 1 / 3 << endl;                  //0.3333333333333333
```
설정이 된다 이렇게 보면 setprecision(streamsize)는 fixed와 함께 사용을 해야지 설정이 되는 것처럼 볼 수 있다  
그러나 다음 상황을 보자  
　  
#상황3
```c++
cout << setw(20) << right << setfill(' ') 
     << setprecision(16) << a / b << endl;       //0.3333333333333333
```
이렇게 하면 또 소수점 자리수가 설정이 된다  
여기에 사용된 setw(20), setfill(' ')은 setprecision(16)과 동일하게 iomanip Header에 정의된 내용인데  
그렇다면 iomanip Header에 정의된 내용과 함께 써줘야 소수점 설정이 가능하다는 것일까?  
　  
아니다.... setw(20)과 setfill(' ')을 제외한 right만 남겨두고 실행해도 소수점 설정이 된다  
모르겠다   
　  
　  
여튼 정리를 하자면 setprecision(streamsize)또한 cout << fixed과 함께 자리수를 정해주는 함수이다  
　  
+++ setw(streamsize)는 출력할때 너비를 의미하고 setfill(char)는 남는 공간을 char로 채우는 함수이며, 일회성으로 보여진다  
