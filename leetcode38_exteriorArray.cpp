#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string countAndSay(int n)
    {
        string pre = "1";
        if (n == 1)
            return pre;

        string cur = "11";
        for (int i = 2; i < n; i++)
        {
            pre = cur;
            cur = "";
            int len = 1;
            int j = 1;
            while (j <= pre.size())
            {
                if (j < pre.size() && pre[j - 1] == pre[j])
                {
                    len++;
                    j++;
                }
                else
                {
                    cur += to_string(len) + pre[j - 1];
                    len = 1;
                    j++;
                }
            }
        }

        return cur;
    }
};

int main()
{
    int n;
    cin >> n;
    Solution s;
    string str = s.countAndSay(n);
    cout << str << endl;
    return 0;
}