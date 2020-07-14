#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> FindContinuousSequence(int sum)
    {
        vector<vector<int>> result;
        int l = 1, r = 2;
        while (l < r)
        {
            int cursum = (l + r) * (r - l + 1) / 2; // 求当前窗口内的和，等差数列求和公式
            if (cursum < sum)                       // 如果当前窗口内的和小于sum，则把右指针往后移动一位
                r++;
            else if (cursum > sum) // 如果当前窗口内的和大于sum，则把左指针的和往右移动一位
                l++;
            else if (cursum == sum) // 如果当前窗口内的和等于sum，则记录下来，并把左指针往右移动一位
            {
                vector<int> res;
                for (int i = l; i <= r; i++)
                    res.push_back(i);
                result.push_back(res);
                l++;
            }
            // for (int i = l; i <= r; i++)
            //     cout << i << " ";
            // cout << endl;
        }
        return result;
    }
};

int main()
{
    int sum;
    cin >> sum;
    Solution s;
    vector<vector<int>> res = s.FindContinuousSequence(sum);
    cout << endl;
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << endl;
    }

    return 0;
}