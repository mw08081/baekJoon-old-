## 정렬과 시간복잡도
시간복잡도가 O(N^2), O(N ln N)인 sort방식들에 대해 알아봤다  
O(N^2)인 정렬방식은 bubbleSort, SelectSort가 있으며 O(N ln N)의 정렬방식은 HeapSort, MergeSort가 있었다
이때 QuickSort는 평균적으로 O(N ln N)의 성능이지만 최악의 경우 시간복잡도는 O(N^2)에 해당했다  
　    
## `#include <algorithm>`의 sort()함수
시간복잡도가 O(N ln N)인 HeapSort를 매번 구현하여 프로그래밍에 사용하는 것은 시간낭비였고, 실제로 기존에 O(N ln N)에 해당하는 정렬방식을 구현하여 미리 만들어논 함수가 존재했다  
해당 함수를 이용하기위해서는 `#include <algorithm>`을 불러온 후 `sort()`함수를 통해 구현할 수 있었다  
  
sort()함수의 사용방법은 다음과 같다  
```c++
template <class RandomAccessIterator> 
void sort (RandomAccessIterator first, RandomAccessIterator last);
```
```c++
//배열로 sort()진행하기
int main()
{
    int arr[] = { 5, 3, 2, 6, 8, 0, 10, 43 };
    
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
sort()함수의 매겨변수는 `주소` 또는 `vector<T>::iterator`값을 넣어주면 된다  
그러므로 `arr` 또는 `arr.begin()`값을 이용할 수 있다  
　   
  
하지만 단순히 iterator값만 써줄 경우 자동적으로 오름차순 정렬이 되는데, 내림차순 정렬은 `Compare _comp`를 매개변수로 추가하면된다  
```c++
template <class RandomAccessIterator, class Compare>
void sort (RandomAccessIterator first, RandomAccessIterator last, Compare _comp);
```
  
```c++
//CompareFunc()를 이용한 array 내림차순 정렬
bool CompareFunc(int n1, int n2)
{
    return n1 > n2;
}

int main()
{
    int arr[] = { 5, 3, 2, 6, 8, 0, 10, 43 };
    
    sort(arr, arr + 8, CompareFunc);
    for (int i = 0; i < 8; i++)
        cout << arr[i] << " ";
    cout << '\n';

    return 0;
}
```
물론 만약 CompareFunc()함수의 return을 `return n1 > n2`가 아닌 `return n1 < n2`로 변경한다면 오름차순 정렬도 가능하다
```c++
//CompareFunc()를 이용한 vector<int> 내림차순 정렬
bool CompareFunc(int n1, int n2)
{
    return n1 > n2;
}

int main()
{
    vector<int> arr = { 5, 2, 19, 6, 12, 16};

    sort(arr.begin(), arr.end(), CompareFunc);

    for (int i = 0; i < arr.size(); i++)
        cout << arr.at(i) << " ";
    
    return 0;
}
```
　  
## 문제해결  
그래서 11650문제를 sort()함수를 이용해서 문제를 해결할 수 있다고 하니 활용해볼 참이다 다음과 같다  
```c++
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    vector<pair<int, int>> arr;
    
    for(int i = 0; i < n; i++)
    {
        int n1, n2;
        cin >> n1 >> n2;
        
        arr.push_back(pair<int, int>(n1, n2));
    }
    
    sort(arr.begin(),arr.end());

    for(int i = 0; i < arr.size(); i++)
        cout << arr[i].first << " " << arr[i].second << '\n';
    
    return 0;
}

```
sort()함수가 자동적으로 vector내의 pair.first와 pair.second를 비교하여 오름차순으로 정리해줘서 쉽게 해결할 수 있다  
그렇다면 내림차순은 어떻게 만들까? 생각을 해보면 Compare _comp 함수를 이용하여 내림차순으로 정렬해볼 수 있다는 생각이 들었다  

```c++
bool CompareFunc(pair<int, int> p1, pair<int, int> p2)
{
    if(p1.first < p2.first)
        return true;
    else if(p1.first == p2.first)
    {
        if(p1.second < p2.second)
            return true;
        else
            return false;
    }
    else
        return false;
}

int main()
{
    
    vector< pair<int, int> > arr;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int n1, n2;
        cin >> n1 >> n2;

        arr.push_back(pair<int, int>(n1, n2));
    }
    sort(arr.begin(), arr.end(), CompareFunc);

    for (int i = 0; i < n; i++)
        cout << arr.at(i).first << " " << arr.at(i).second << '\n';
    
    return 0;
}
```
Compare _comp 함수는 원하는 정렬 조건에 따라 if-else, return을 활용하여 작성할 수 있었다  
　  
  
## 심화학습  
이제껏 본 _comp 함수는 굉장히 단순해서 if-else, return을 활용해서 복잡한 정렬이 가능할지 몰랐으나,  
스스로 문제를 해결해보면서 가능하다는 것을 알았다  

그렇다면 좀 더 _comp함수를 다양하게 활용하여 class도 정렬을 해볼 수 있겠다는 생각이 들었다  

```c++
class Student {
public :
    string name;
    int sc;

    Student(string name, int sc)
    {
        this->name = name;
        this->sc = sc;
    }
};
```
과 같은 class가 있다고 가정했을 때, Student class를 성적의 오름차순으로 정렬하고 싶다면 _comp 함수를  다음과 같이 활용 수 있다  
```c++
bool CompFunc(Student s1, Student s2)
{
    return s1.sc < s2.sc;
}

int main()
{
    Student students[] = {
        Student("A", 90),
        Student("B", 97),
        Student("C", 89),
        Student("D", 69)
    };

    sort(students, students + 4, CompFunc);

    for (int i = 0; i < 4; i++)
        cout << students[i].name << " ";
    
    return 0;
}
```

하지만 좀 더 쉽게 하는 방법이 있었다 그것은 연산자의 오버로딩을 이용하는 것이다  
아래의 코드를 Student class에 추가한다  
```c++
bool operator <(Student &student)
{
    return this->sc < student.sc;
}
```
  
그리고 나서 `sort(students, students + 4, CompFunc);`를 `sort(students, students + 4);`로 변경만 한다면 간단히 해결된다 

```c++
class Student {
public :
    string name;
    int sc;

    Student(string name, int sc)
    {
        this->name = name;
        this->sc = sc;
    }

    bool operator <(Student &student)
    {
        return this->sc < student.sc;
    }
};

int main()
{
    Student students[] = {
        Student("a", 90),
        Student("b", 97),
        Student("c", 89),
        Student("d", 69)
    };

    sort(students, students + 4);
    //sort(students, students + 4, CompFunc);

    for (int i = 0; i < 4; i++)
        cout << students[i].name << " ";
    
    return 0;
}
```
