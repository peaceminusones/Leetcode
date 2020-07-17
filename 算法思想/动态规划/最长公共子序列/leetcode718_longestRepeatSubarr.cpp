#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // 动态规划
    int findLength(vector<int> &A, vector<int> &B)
    {
        vector<vector<int>> dp(A.size() + 1, vector<int>(B.size() + 1));
        int res = 0;
        for (int i = 1; i <= A.size(); i++)
        {
            for (int j = 1; j <= B.size(); j++)
            {
                if (A[i - 1] == B[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = 0;

                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};

int main()
{
    vector<int> A, B;
    int item;
    while (cin >> item)
    {
        A.push_back(item);
    }
    cin.clear();
    cin.ignore();
    while (cin >> item)
    {
        B.push_back(item);
    }

    Solution s;
    int res = s.findLength(A, B);
    cout << res << endl;
    return 0;
}