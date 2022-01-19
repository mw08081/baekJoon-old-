#include <iostream>
#include <vector>

using namespace std;

void Swap(int * n1, int * n2)
{
    int tmp = *n1;
    *n1 = *n2;
    *n2 = tmp;
}
void HeapSort(vector<int> * tree)
{
    int len = tree->size() - 1;
    
    //MaxHeapify
    for (int i = len / 2; i > 0; i--)
    {
        int p = i, c = p * 2;
        while(len >= c)
        {
            if(len >= c + 1 && tree->at(c + 1) > tree->at(c)) c++;
            if(tree->at(p) >= tree->at(c)) break;

            Swap(&tree->at(p), &tree->at(c));

            p = c;
            c = p * 2;
        }
    }
    
    vector<int> res;
    while(tree->size() > 1)
    {
        int p = 1, c = p * 2;
        Swap(&tree->at(1), &tree->at(tree->size() - 1));
        res.push_back(tree->back());
        tree->pop_back();

        while(tree->size() - 1 >= p * 2)
        {
            if(tree->size() - 1 >= c + 1 && tree->at(c + 1) > tree->at(c)) c++;
            if(tree->at(p) >= tree->at(c)) break;

            Swap(&tree->at(p), &tree->at(c));

            p = c;
            c = p * 2;
        }
    }

    for (int i = 0; i < res.size(); i++)
        cout << res.at(i);
    cout << endl;
}

int main()
{
    vector<int> tree {0};
    int n;
    cin >> n;

    while(n >= 1)
    {
        tree.push_back(n % 10);
        n /= 10;
    }

    HeapSort(&tree);

    return 0;
}