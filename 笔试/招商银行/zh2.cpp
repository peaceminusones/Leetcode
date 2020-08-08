#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
    // vector<string> dict = {"a", "b", "c", "d", "e", 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

public:
    // 长度为n，小写字母为k种
    string sequence(int n, int k)
    {
        if (k > n)
            return "-1";
        if (k == 1 && n > 1)
            return "-1";
        if (k == 1 && n == 1)
            return "a";

        // int remind = k - 2;
        int length = n - (k - 2);
        string str1 = "", str2 = "";
        int flag = 0;
        for (int i = 0; i < length; i++)
        {
            if (flag == 0)
            {
                str1 += "a";
                flag = 1;
            }
            else
            {
                str1 += "b";
                flag = 0;
            }
        }

        for (int i = 2; i < k; i++)
        {
            str2 += ('a' + i);
        }

        // cout << str1 << " " << str2 << endl;
        return (str1 + str2);
    }
};

int main()
{
    int n, k;
    cin >> n >> k;
    Solution s;
    string res = s.sequence(n, k);
    cout << res << endl;
    return 0;
}