#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        unordered_map<char, int> tnum; // T中所有字符的个数
        for (auto ti : t)
            tnum[ti]++;

        unordered_map<char, int> count; // 滑动窗口内包含T的字符出现的次数
        int left = 0, right = 0;
        int len = s.size();
        string res = "";
        for (right = 0; right < s.size(); right++)
        {
            // 如果s[right]为T中的元素，则count[s[right]]++
            if (tnum.find(s[right]) != tnum.end())
                count[s[right]]++;

            // 如果count包含了tnum
            while (contain(tnum, count))
            {
                // 如果长度更小，则更新结果
                if (right - left + 1 < len)
                {
                    res = s.substr(left, right - left + 1);
                    len = right - left + 1;
                }
                // 向右移动窗口，如果left刚好指的是T中的元素，则相应count中减一
                if (tnum.find(s[left]) != tnum.end())
                    count[s[left]]--;
                left++;
            }
        }
        return res;
    }

    // S要想包含T，则T中所有元素的数量需要小于对应S中所有元素的数量
    bool contain(unordered_map<char, int> &tnum, unordered_map<char, int> &count)
    {
        for (auto it = tnum.begin(); it != tnum.end(); it++)
        {
            if (it->second > count[it->first]) // 如果数量大了，说明不符合
                return false;
        }

        return true;
    }
};

int main()
{
    string S, T;
    cin >> S >> T;
    Solution s;
    cout << s.minWindow(S, T) << endl;
    return 0;
}