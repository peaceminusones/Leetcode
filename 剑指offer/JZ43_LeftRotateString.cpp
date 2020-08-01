#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string LeftRotateString(string str, int n)
    {
        string res = "";
        if (str.empty())
            return res;
        int k = n % str.size();
        for (int i = k; i < str.size(); i++)
            res += str[i];
        for (int i = 0; i < k; i++)
            res += str[i];

        return res;
    }

    string LeftRotateString_1(string str, int n)
    {
        string res = "";
        if (str.empty())
            return res;
        reverse(str.begin(), str.end());
        reverse(str.begin(), str.begin() + str.size() - n);
        reverse(str.begin() + str.size() - n, str.end());
        return str;
    }
};

int main()
{
    string str;
    cin >> str;
    int n;
    cin >> n;
    Solution s;
    string res = s.LeftRotateString_1(str, n);
    cout << res << endl;
    return 0;
}