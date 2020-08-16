#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    string PerfectStr(int n, int m, string str)
    {
    }

    int maxLength(string str)
    {
        int res = 0;
        int i = 0, j = 1;
        while (j < str.size())
        {
            if (str[i] == str[j])
                j++;
            else
            {
                res = max(res, j - i);
                i = j;
                j++;
            }
        }
        res = max(res, j - i);
        return res;
    }
};

int main()
{
    string str;
    cin >> str;
    Solution s;
    cout << s.maxLength(str) << endl;
    return 0;
}