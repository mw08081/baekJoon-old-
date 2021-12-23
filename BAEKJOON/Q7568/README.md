## Pair<T, T>

Dictionary<T, T> 와 같은 것이 cpp에서는 pair이라는 구조체가 있다  
이는 pair<T, T>로 사용하며 기본적인으로 first, second의 멤버변수를 가지고 있다  

```c++
pair<int, int> data;

data.frist = 10;
data.second = 20;

cout << data.frist << " " << data.second << '\n';
//10 20 출력


//pair Arr
pair<int, int> datas[10];
for(int i = 0; i < 10; i++)
{
    datas[i].frist = i;
    datas[i].second = i + 1; 
}
```

```c++
#include <vector>

vector<pair<int, int>> pairVec;

pairVec.push_back ...
```
