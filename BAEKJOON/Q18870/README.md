## 참고자료

문제를 풀고나서 다른 사람들의 코드를 살펴보았다  
그 중 나보다 100ms정도 빠른 코드도 있었지만 나보다 속도가 약 두배정도 느린 코드도 존재했다  
  
그런데 그 코드는 생각보다 독특한 방식으로 작성되었다  
해당 코드는 unique(), vector<T>.erase()함수를 이용하고있었다  
  
코드는 다음과 같다  
```c++
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    vector<int> v, back;
    int N, input;
    
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        cin >> input;
        v.push_back(input);
        back.push_back(input);
    }
    
    
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    
    for(int i = 0; i < N; i++) {
        printf("%d ", lower_bound(v.begin(), v.end(), back[i]) - v.begin());
    }
    
}
```
그렇다면 해당 함수에 대해 알아보자
                         
### unique()
`unique()`함수는 배열또는 벡터와 같은 데이터에서 중복된 값들을 뒤로 옮기고 첫번째 중복값의 index값을 return한다
`{1 ,2, 2, 3, 3, 4}`의 배열에서 unique를 적용하면 다음과 같이 배열이 변경되고 `{1, 2, 3, 4, 2, 3}` 4의 index값을 return한다  
                         
### vector<T>.erase()
vector<T>.erase()함수는 단순하게 특정 위치부터 특정위치의 값을 지워내는 역할을 한다  
따라서 ` v.erase(unique(v.begin(), v.end()), v.end());`는 중복된 값이 있는 인덱스부터 끝까지 모두 지워내는 작업을 수행한다

  
+++ 해당 코드 블로그 - https://hevton.tistory.com/437
