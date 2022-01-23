### 정렬과 시간복잡도
시간복잡도가 O(N^2), O(N ln N)인 sort방식들에 대해 알아봤다  
O(N^2)인 정렬방식은 bubbleSort, SelectSort가 있으며 O(N ln N)의 정렬방식은 HeapSort, MergeSort가 있었다
이때 QuickSort는 평균적으로 O(N ln N)의 성능이지만 최악의 경우 시간복잡도는 O(N^2)에 해당했다
  
### #include <algorithm>의 sort()함수
시간복잡도가 O(N ln N)인 HeapSort를 매번 구현하여 프로그래밍에 사용하는 것은 시간낭비였고, 실제로 기존에 O(N ln N)에 해당하는 정렬방식을 구현하여 미리 만들어논 함수가 존재했다  
해당 함수를 이용하기위해서는 `#include <algorithm>`을 불러온 후 `sort()`함수를 통해 구현할 수 있었다  
  
sort()함수의 사용방법은 다음과 같다  
```c++
//배열로 sort()진행하기
int main()
{
    int arr[] = { 5,3,2,6,8,0,10,43};
    
    sort(arr, arr + 8);
    for (int i = 0; i < 8; i++)
        cout << arr[i] << " ";
    cout << '\n';

    return 0;
}
```
```c++
//vector로 sort()진행하기
int main()
{
    vector<int> arr = { 5, 2, 19, 6, 12, 16};

    sort(arr.begin(), arr.end());

    for (int i = 0; i < arr.size(); i++)
        cout << arr.at(i) << " ";
    
    return 0;
}
```
sort()함수의 매겨변수는 `주소` 또는 `vector<T>::iterator`값을 넣어주면 된다 그러므로 `arr` 또는 `arr.begin()`값을 이용할 수 있다  
　   
  
하지만 단순히 iterator값만 써줄 경우 자동적으로 오름차순 정렬만 가능한데, 내림차순 정렬은 `Compare _comp`매개변수가 추가된 함수의 오버로딩을 사용하면 된다  
```c++
  
  
```
