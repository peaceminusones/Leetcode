#include <iostream>
#include <string>
using namespace std;

string strCircleMove(string s, int k)
{
    int size = s.size();
    for (int i = 0; i < k; i++)
    {
        s = s[size - 1] + s.substr(0, size - 1);
    }
    return s;
}

int main()
{
    string s;
    cin >> s;
    int k;
    cin >> k;
    string res = strCircleMove(s, k);
    cout << res << endl;
    return 0;
}