#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxUncrossedLines(vector<int> &A, vector<int> &B)
    {
        vector<vector<int>> dp(A.size() + 1, vector<int>(B.size() + 1));

        for (int i = 1; i <= A.size(); i++)
        {
            for (int j = 1; j <= B.size(); j++)
            {
                if (A[i - 1] == B[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[A.size()][B.size()];
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
    int res = s.maxUncrossedLines(A, B);
    cout << res << endl;
    return 0;
}