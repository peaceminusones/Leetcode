#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // 最多删除一个字符，判断是否是回文串
    bool validPalindrome(string s)
    {
        if (s.size() <= 1)
            return true;

        int i = 0, j = s.size() - 1;
        while (i < j)
        {
            if (s[i] != s[j])
            {
                return isValid(s, i, j - 1) || isValid(s, i + 1, j);
            }
            i++;
            j--;
        }
        return true;
    }

    bool isValid(string s, int i, int j)
    {
        while (i < j)
        {
            if (s[i++] != s[j--])
                return false;
        }
        return true;
    }
};

int main()
{
    string str;
    cin >> str;
    Solution s;
    cout << s.validPalindrome(str) << endl;
    return 0;
}