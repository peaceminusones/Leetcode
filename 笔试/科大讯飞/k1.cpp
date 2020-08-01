#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
    vector<int> money = {1, 5, 10, 50, 100};

public:
    int number(vector<int> num, int k)
    {
        unordered_map<int, int> map;
        for (int i = 0; i < num.size(); i++)
            map[money[i]] = num[i];

        reverse(money.begin(), money.end());

        int res = k + 1;
        int count = 0;
        dfs(money, k, 0, count, res, map);
        return res == k + 1 ? -1 : res;
    }

    void dfs(vector<int> &money, int k, int index, int count, int &res, unordered_map<int, int> &map)
    {
        if (k <= 0 || index == money.size())
        {
            if (k == 0)
                res = min(res, count);
            return;
        }

        int n = k / money[index];
        if (n > map[money[index]])
            n = map[money[index]];

        for (int i = n; i >= 0 && i + count < res; i--)
        {
            dfs(money, k - i * money[index], index + 1, count + i, res, map);
        }
    }
};

int main()
{
    vector<int> num;
    int item;
    for (int i = 0; i < 5; i++)
    {
        cin >> item;
        num.push_back(item);
    }

    int k;
    cin >> k;

    Solution s;
    cout << s.number(num, k) << endl;

    return 0;
}