#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // W:背包的总体积
    // N：物品的数量
    // weights：数组存储N个物品的重量
    // values：数组存储N个物品的价值
    // dp[i][j]：前i件物品放入体积为j的背包中的最大价值
    int knapsack(int W, int N, vector<int> &weights, vector<int> &values)
    {
        vector<vector<int>> dp(N + 1, vector<int>(W + 1));
        for (int i = 1; i <= N; i++)
        {
            int weight_i = weights[i - 1];
            int value_i = values[i - 1];
            for (int j = 1; j <= W; j++)
            {
                if (j >= weight_i)
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight_i] + value_i);
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }

        return dp[N][W];
    }

    // 空间优化！不用二维数组，用一维数组
    int knapsack2(int W, int N, vector<int> &weights, vector<int> &values)
    {
        vector<int> dp(W + 1);
        for (int i = 1; i <= N; i++)
        {
            int weight_i = weights[i - 1];
            int value_i = values[i - 1];
            for (int j = W; j >= 1; j--)
            {
                if (weight_i <= j)
                    dp[j] = max(dp[j], dp[j - weight_i] + value_i);
            }
        }
        return dp[W];
    }
};

int main()
{
    int W, N;
    cin >> W >> N;
    vector<int> weights, values;
    int w, v;
    for (int i = 0; i < N; i++)
    {
        cin >> w;
        weights.push_back(w);
    }
    cin.clear();
    cin.ignore();

    for (int i = 0; i < N; i++)
    {
        cin >> v;
        values.push_back(v);
    }

    Solution s;
    int res1 = s.knapsack(W, N, weights, values);
    int res2 = s.knapsack2(W, N, weights, values);
    cout << res1 << endl;
    cout << res2 << endl;

    return 0;
}