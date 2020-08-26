#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int l = 0, r = s.size() - 1;
        while (l < r)
        {
            // 如果不是字母或者数字就跳过
            while (l < r && !isalnum(s[l]))
                l++;
            // 如果不是字母或者数字就跳过
            while (l < r && !isalnum(s[r]))
                r--;

            if (l < r)
            {
                // 都变成小写字母再比较
                if (tolower(s[l]) != tolower(s[r]))
                    return false;
                l++, r--;
            }
        }
        return true;
    }
};

int main()
{
    string str;
    cin >> str;
    Solution s;
    cout << s.isPalindrome(str) << endl;
    return 0;
}