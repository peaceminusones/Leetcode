#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution
{
public:
    // dp[i]: 以A[i]为结尾的数列中等差数列的个数，dp[i] = dp[i-1]+1
    int numberOfArithmeticSlices(vector<int> &A)
    {
        if (A.size() < 3)
            return 0;
        vector<int> dp(A.size());
        dp[0] = 0;
        dp[1] = 0;
        int res = 0;
        for (int i = 2; i < A.size(); i++)
        {
            if ((A[i] - A[i - 1]) == (A[i - 1] - A[i - 2]))
                dp[i] = dp[i - 1] + 1;
            else
                dp[i] = 0;
            res += dp[i];
        }

        // return accumulate(dp.begin(), dp.end(), 0);
        return res;
    }
};

int main()
{
    vector<int> A;
    int item;
    while (cin >> item)
        A.push_back(item);
    Solution s;
    int res = s.numberOfArithmeticSlices(A);
    cout << res << endl;
    return 0;
}