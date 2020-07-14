#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;
        string s = to_string(x);
        int i = 0;
        while (i < s.size() / 2)
        {
            if (s[i] != s[s.size() - 1 - i])
                return false;
            i++;
        }
        return true;
    }

    // 不转换为string，翻转一半数字
    bool isPalindrome1(int x)
    {
        if (x < 0 || (x % 10 == 0 && x != 0))
            return false;

        long res = 0;
        while (x > res)
        {
            res = res * 10 + x % 10;
            x /= 10;
        }

        return x == res || x == res / 10;
    }
};

int main()
{
    int x;
    cin >> x;

    Solution s;
    bool res = s.isPalindrome1(x);
    cout << res << endl;
    return 0;
}