#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // vector<int> numOfFood(vector<int> foods, int target)
    // {
    //     vector<int> res;
    //     dfs(foods, target, 0, {}, res);
    //     return res;
    // }

    // void dfs(vector<int> &foods, int target, int index, vector<int> cur, vector<int> &res)
    // {
    //     if (index == foods.size() && target > 0)
    //         return;
    //     if (target <= 0)
    //     {
    //         if (res.empty())
    //             res = cur;
    //         else if (cur.size() < res.size())
    //             res = cur;
    //         return;
    //     }

    //     for (int i = index; i < foods.size(); i++)
    //     {
    //         cur.push_back(i + 1);
    //         dfs(foods, target - foods[i], i + 1, cur, res);
    //         cur.pop_back();
    //     }
    // }

    vector<int> numOfFood(vector<int> foods, int target)
    {
        vector<int> res;
        vector<vector<int>> nums(foods.size(), vector<int>(2));
        int sum = 0;
        for (int i = 0; i < foods.size(); i++)
        {
            nums[i][0] = foods[i];
            nums[i][1] = i + 1;
            sum += foods[i];
        }

        if (sum < target)
            return res;

        sort(nums.begin(), nums.end(), cmp);
        sum = 0;
        int i = 0, j = 0;
        vector<int> cur;
        while (j < nums.size())
        {
            if (sum < target)
            {
                sum += nums[j][0];
                cout << nums[j][0] << " " << nums[j][1] << endl;
                res.push_back(nums[j][1]);
                j++;
            }
            else
                return res;
        }
        return res;
    }

    static bool cmp(vector<int> &a, vector<int> &b)
    {
        return a[0] >= b[0];
    }
};

int main()
{
    int T;
    cin >> T;
    vector<vector<int>> res;
    for (int i = 0; i < T; i++)
    {
        int n, m;
        cin >> n >> m;
        vector<int> foods;
        int item;
        for (int i = 0; i < n; i++)
        {
            cin >> item;
            foods.push_back(item);
        }
        Solution s;
        vector<int> r = s.numOfFood(foods, m);
        res.push_back(r);
    }

    for (auto r : res)
    {
        if (r.size())
        {
            cout << r.size() << endl;
            for (int i = 0; i < r.size(); i++)
                cout << r[i] << " ";
            cout << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}