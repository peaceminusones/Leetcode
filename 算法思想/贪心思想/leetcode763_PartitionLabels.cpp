#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    /*
     * 【贪心算法】
     * 策略就是不断地选择从最左边起最小的区间
     * 加入第一个字母是'a'，那么第一个区间一定包含最后一次出现的a，然后第一个a和最后一个a之间的字母，会让区间慢慢扩大
     * 
     * 所以算法思想就是，对于遇到的第一个字母，去找它最后一次出现的位置，然后再利用中间出现的字母去更新这个区间
    */
    vector<int> partitionLabels(string S)
    {
        vector<int> res;
        unordered_map<char, int> record; // 用来记录每次字母的最后一个位置
        unordered_map<char, int>::iterator it;
        for (int i = 0; i < S.size(); i++)
            record[S[i]] = i;

        int start = 0, end = 0;
        for (int i = 0; i < S.size(); i++)
        {
            end = max(record[S[i]], end);

            if (i == end)
            {
                res.push_back(end - start + 1);
                start = i + 1;
            }
        }
        return res;
    }
};

int main()
{
    string s;
    cin >> s;

    Solution sol;
    vector<int> res = sol.partitionLabels(s);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";

    return 0;
}