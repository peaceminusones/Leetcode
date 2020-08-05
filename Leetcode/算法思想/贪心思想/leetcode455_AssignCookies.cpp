#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        if (g.size() == 0 || s.size() == 0)
            return 0;
        sort(g.begin(), g.end()); // 排序孩子的胃口
        sort(s.begin(), s.end()); // 排序饼干的大小

        int i = 0, j = 0;
        while (i < g.size() && j < s.size())
        {
            if (g[i] <= s[j]) // 按照胃口从小到大满足
                i++;
            j++;
        }
        return i;
    }
};

int main()
{
    vector<int> g;
    vector<int> s;
    int item;
    while (cin >> item)
        g.push_back(item);
    cin.clear();
    cin.ignore();
    while (cin >> item)
        s.push_back(item);

    Solution sol;
    int res = sol.findContentChildren(g, s);
    cout << res << endl;

    return 0;
}