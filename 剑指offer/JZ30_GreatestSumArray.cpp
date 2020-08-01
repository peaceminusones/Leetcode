#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int FindGreatestSumOfSubArray(vector<int> array)
    {
        if (array.empty())
            return 0;
        vector<int> dp(array.size());
        dp[0] = array[0];
        int res = array[0];
        for (int i = 1; i < array.size(); i++)
        {
            dp[i] = max(array[i], dp[i - 1] + array[i]);
            res = max(res, dp[i]);
        }

        return res;
    }
};

int main()
{
    vector<int> array;
    int item;
    while (cin >> item)
    {
        array.push_back(item);
        if (cin.get() == '\n')
            break;
    }

    Solution s;
    int res = s.FindGreatestSumOfSubArray(array);
    cout << res << endl;

    return 0;
}