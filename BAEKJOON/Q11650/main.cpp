#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
void InsertData(vector<pair<int, int>> * tree)
{
    int n;
    cin >> n;

    for (int i = 1; i < n + 1; i++)
    {
        int x, y;
        cin >> x >> y;    

        tree->push_back(pair<int, int>(x, y));
    }
}

void Swap(pair<int, int> * n1, pair<int, int> * n2)
{
    pair<int, int> tmp = *n1;
    *n1 = *n2;
    *n2 = tmp;
}

void HeapSort(vector<pair<int, int>> * tree)
{
    for (int i = (tree->size() - 1) / 2; i > 0; i--)
    {
        int p = i, c = p * 2;

        while((tree->size() - 1) >= c)
        {
            if(((tree->size() - 1) >= c + 1) &&
            ((tree->at(c + 1).first > tree->at(c).first) 
            || (tree->at(c + 1).first == tree->at(c).first && tree->at(c + 1).second > tree->at(c).second))) c++;
            if(tree->at(p).first > tree->at(c).first 
            || tree->at(p).first == tree->at(c).first && tree->at(p).second > tree->at(c).second) break;

            Swap(&tree->at(p), &tree->at(c));

            p = c;
            c = p * 2;
        }
    }
    
    vector<pair<int, int>> res;
    while(tree->size() > 1)
    {
        Swap(&tree->at(1), &tree->at(tree->size() - 1));
        res.push_back(tree->at(tree->size() - 1));
        tree->pop_back();

        int p = 1, c = p * 2;
        while(tree->size() - 1 >= p * 2)
        {
            if((tree->size() - 1 >= c + 1) &&
            (tree->at(c + 1).first > tree->at(c).first
            || (tree->at(c + 1).first == tree->at(c).first && tree->at(c + 1).second > tree->at(c).second))) c++;

            if(tree->at(p).first > tree->at(c).first 
            || tree->at(p).first == tree->at(c).first && tree->at(p).second > tree->at(c).second) break;

            Swap(&tree->at(p), &tree->at(c));

            p = c;
            c = p * 2;
        }
        
    }

    for (int i = res.size() - 1; i >= 0; i--)
        cout << res.at(i).first << " " << res.at(i).second << endl;
}

int main()
{
    vector<pair<int, int>> tree {pair<int, int>(0, 0)};
    
    InsertData(&tree);
    sort(i, i)
    HeapSort(&tree);

    return 0;
}
*/

#include <iostream>
#include <algorithm>

using namespace std;

class Student {
public:
	string name;
	int score;
	Student(string name, int score) {
		this->name = name;
		this->score = score;
	}
	// 정렬 기준은 '점수가 작은 순서' 
	bool operator <(Student &student) {
		return this->score < student.score;
	}
};

bool compare(int a, int b) {
	return a > b;
} 

// bool CompFunc(Student s1, Student s2)
// {
//     return s1.sc < s2.sc;
// }

int main(void) {
	Student students[] = {
		Student("나동빈", 90),
		Student("이상욱", 93),
		Student("박한울", 97),
		Student("강종구", 87),
		Student("이태일", 92)
	};
	sort(students, students + 5);
	for(int i = 0; i < 5; i++) {
		cout << students[i].name << ' ';
	}
}




/*
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
*/

/* 
//int Type sort 

//Defalut sort Asc
bool CompareFunc(int n1, int n2)
{
    return n1 < n2;
    //sort Desc
    //return n1 > n2;
}

int main()
{
    int arr[] = { 5,3,2,6,8,0,10,43};
    
    sort(arr, arr + 8, CompareFunc);
    for (int i = 0; i < 8; i++)
        cout << arr[i] << " ";
    cout << '\n';

    return 0;
}

*/