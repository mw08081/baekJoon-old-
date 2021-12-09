대당 순이익이 고정비용을 넘기는 순간이 손익분기점이다.
```c++
while(staticPrice + valuablePrice * x > salePrice * x)
  x++;
  
cout << x << endl;
```
이 아닌 
```c++
cout << staticPrice / (salePrice - valuablePrice) + 1 << endl;
```
