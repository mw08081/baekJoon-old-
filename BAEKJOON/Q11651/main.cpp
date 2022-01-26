#include <iostream>
#include <vector>

using namespace std;

/*
void Swap(pair<int, int> * n1, pair<int, int> * n2)
{
    pair<int, int> tmp = *n1;
    *n1 = *n2;
    *n2 = tmp;
}

int main()
{
    vector< pair<int, int> > tree;
    tree.push_back(pair<int, int>(0, 0));
    int n;
    cin >> n;

    //Insert Data
    for (int i = 1; i <= n; i++)
    {
        int n1, n2;
        cin >> n1 >> n2;

        tree.push_back(pair<int, int>(n1, n2));
    }

    //MaxHeapify
    for (int i = (tree.size() - 1) / 2; i > 0; i--)
    {
        int p = i, c = p * 2;
        while(tree.size() - 1 >= c)
        {
            if(tree.size() - 1 >= c + 1 && (tree.at(c + 1).second > tree.at(c).second || tree.at(c + 1).second == tree.at(c).second && tree.at(c + 1).first > tree.at(c).first)) c++;
            if(tree.at(p).second > tree.at(c).second || tree.at(p).second == tree.at(c).second && tree.at(p).first > tree.at(c).first) break;

            Swap(&tree.at(p), &tree.at(c));

            p = c;
            c = p * 2;
        }
    }
    
    //Make New vector
    vector< pair<int, int> > res;
    while(tree.size() > 1)
    {
        int p = 1, c = p * 2;
        Swap(&tree.at(p), &tree.at(tree.size() - 1));
        res.push_back(tree.at(tree.size() - 1));
        tree.pop_back();

        while(tree.size() - 1 >= c)
        {
            if(tree.size() - 1 >= c + 1 && (tree.at(c + 1).second > tree.at(c).second || tree.at(c + 1).second == tree.at(c).second && tree.at(c + 1).first > tree.at(c).first)) c++;
            if(tree.at(p).second > tree.at(c).second || tree.at(p).second == tree.at(c).second && tree.at(p).first > tree.at(c).first) break;

            Swap(&tree.at(p), &tree.at(c));

            p = c;
            c = p * 2;
        }
    }

    for (int i = res.size() - 1;i >= 0 ;i--)
        cout << res.at(i).first << " " << res.at(i).second << '\n';
    
    return 0;
}
*/