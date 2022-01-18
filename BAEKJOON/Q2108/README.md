### 올림과 내림, 그리고 반올림

먼저 올림/내림을 사용하기 앞서 '#include cmath'를 포함해줘야 한다.  
그렇다면 함수 사용은 다음과 같다  
　  
`T ceil<T>(T val)`과 `T floor<T>(T val)`이다

```c++
double val;
double cVal;
double fVal;

cVal = ceil(val);
fVal = floor(val);
```

참고로 반올림은 기존 값에서 0.5f를 더한 뒤 버림을 해주면 된단다.
`floor(val + 0.5f)`
