#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string findLongestWord(string s, vector<string> &d)
    {
        // int max = 0;
        string maxstr;
        for (int i = 0; i < d.size(); i++)
        {
            // 如果字典里的字符串d[i]长度小于当前最大的字符串，或者，长度相等但是d[i]的字典序大于maxstr
            // 则直接比较字典中的下一个字符
            if (maxstr.size() > d[i].size() || (maxstr.size() == d[i].size() && d[i] > maxstr)) //d[i] > maxstr ---> maxstr.compare(d[i]) < 0
                continue;

            if (isSubstr(s, d[i]))
                maxstr = d[i];
        }
        return maxstr;
    }

    bool isSubstr(string s, string target)
    {
        // 双指针判断target是否在s中
        int i = 0, j = 0;
        while (i < s.size() && j < target.size())
        {
            if (s[i] == target[j])
                j++;
            i++;
        }
        return j == target.size();
    }
};

int main()
{
    string s;
    cin >> s;
    vector<string> d;
    string item;
    cin >> item;
    while (item != "#")
    {
        d.push_back(item);
        cin >> item;
    }

    Solution sol;
    string res = sol.findLongestWord(s, d);
    cout << res << endl;

    return 0;
}