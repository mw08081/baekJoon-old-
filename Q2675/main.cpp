//    2675
#include <iostream>
using namespace std;

int main(int argc, const char* argv[]) {

    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        int rp;
        string str;

        cin >> rp >> str;

        for (int j = 0; j < str.length(); j++)
            for (int k = 0; k < rp; k++)
                cout << str[j];
        cout << endl;
    }

    return 0;
}