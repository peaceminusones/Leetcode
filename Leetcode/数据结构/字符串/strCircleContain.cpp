#include <iostream>
#include <string>
using namespace std;

bool iscircle(string s1, string s2)
{
    for (int i = 0; i < s1.size(); i++)
    {
        s1 = s1.substr(1) + s1[0];
        auto it = s1.find(s2);
        if (it != string::npos)
            return true;
    }
    return false;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    bool res = iscircle(s1, s2);
    cout << res << endl;
    return 0;
}