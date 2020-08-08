#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int discardValue(vector<int> values)
    {
        sort(values.begin(), values.end());

        int discard = 0;
        int a = 0;
        int b = 0;
        int res = accumulate(values.begin(), values.end(), 0);
        backtracking(values, 0, discard, a, b, res);

        return res;
    }

    void backtracking(vector<int> nums, int index, int discard, int a, int b, int &res)
    {
        if (index >= nums.size())
        {
            if (a == b)
            {
                res = min(res, discard);
            }
            return;
        }

        backtracking(nums, index + 1, discard + nums[index], a, b, res);
        backtracking(nums, index + 1, discard, a + nums[index], b, res);
        backtracking(nums, index + 1, discard, a, b + nums[index], res);
    }
};

int main()
{
    int T;
    cin >> T;
    vector<vector<int>> values;
    for (int i = 0; i < T; i++)
    {
        int n;
        cin >> n;

        vector<int> value;
        int item;
        for (int i = 0; i < n; i++)
        {
            cin >> item;
            value.push_back(item);
        }

        values.push_back(value);
    }

    Solution s;

    vector<int> res;
    for (int i = 0; i < values.size(); i++)
    {
        int discard = s.discardValue(values[i]);
        res.push_back(discard);
    }

    for (auto r : res)
        cout << r << endl;
    return 0;
}