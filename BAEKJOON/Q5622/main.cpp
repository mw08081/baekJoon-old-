//5622
#include <iostream>
using namespace std;

int main(int argc, const char* argv[]) {
    string str;
    int time = 0;

    cin >> str;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= 87)
            time += 10;
        else if (str[i] >= 84)
            time += 9;
        else if (str[i] >= 80)
            time += 8;
        else if (str[i] >= 77)
            time += 7;
        else if (str[i] >= 74)
            time += 6;
        else if (str[i] >= 71)
            time += 5;
        else if (str[i] >= 68)
            time += 4;
        else
            time += 3;
    }

    cout << time << endl;

    return 0;
}