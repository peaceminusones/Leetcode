#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string palindrome(string str)
    {
        if (str.size() == 1)
            return str;

        int i = 0, j = str.size() - 1;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == str[j])
                j--;
        }
        if (j == -1)
            return str;

        string res = str.substr(0, j + 1);
        reverse(res.begin(), res.end());
        return str.substr(0, j + 1) + palindrome(str.substr(j + 1)) + res;
    }
};

int main()
{
    string str;
    cin >> str;

    Solution s;
    string res = s.palindrome(str);
    cout << res << endl;

    return 0;
}