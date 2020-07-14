#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string strReverse(string s)
{
    reverse(s.begin(), s.end());
    int begin = 0, end = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            end = i - 1;
            while (begin <= end)
            {
                swap(s[begin++], s[end--]);
            }
            begin = i + 1;
            end = i + 1;
        }
    }
    return s;
}

int main()
{
    string s;
    getline(cin, s);
    string res = strReverse(s);
    cout << res << endl;
    return 0;
}