#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
    // offer 33 ======================================
    int GetUglyNumber_Solution(int index)
    {
        // 1-6的丑数都是自己
        if (index <= 6)
            return index;

        int p2 = 0, p3 = 0, p5 = 0;
        int newuglynum = 1;
        vector<int> res;
        res.push_back(newuglynum);
        while (res.size() < index)
        {
            newuglynum = min(min(res[p2] * 2, res[p3] * 3), res[p5] * 5);
            if (res[p2] * 2 == newuglynum)
                p2++;
            if (res[p3] * 3 == newuglynum)
                p3++;
            if (res[p5] * 5 == newuglynum)
                p5++;
            res.push_back(newuglynum);
        }

        return newuglynum;
    }

    // offer 34 =======================================
    int FirstNotRepeatingChar(string str)
    {
        map<char, int> m;
        for (int i = 0; i < str.size(); i++)
            m[str[i]] += 1; // 竟然不需要初始化？？？？！！
        for (int i = 0; i < str.size(); i++)
            if (m[str[i]] == 1)
                return i;
        return -1;
    }
};

int main()
{
    // int n;
    // cin >> n;
    // Solution s;
    // int res = s.GetUglyNumber_Solution(n);
    // cout << res << endl;

    string str;
    cin >> str;
    Solution s;
    int res = s.FirstNotRepeatingChar(str);
    cout << res << endl;
    return 0;
}