#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxLenNumber(string str)
    {
        int maxLen = 0;
        int i = 0, j = 0;
        while (i <= j && j < str.size())
        {
            while (isalpha(str[i]))
                i++;
            if (i == str.size())
                return 0;

            j = i;
            while (isdigit(str[j]))
                j++;

            maxLen = max(maxLen, j - i);
            i = j;
        }
        return maxLen;
    }
};

int main()
{
    // string str;
    // cin >> str;
    // Solution s;
    // cout << s.maxLenNumber(str) << endl;

    cout << sizeof(int) << endl;
    return 0;
}