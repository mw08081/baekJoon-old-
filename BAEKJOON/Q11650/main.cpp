#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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