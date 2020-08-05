#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
using namespace std;

class Solution
{
public:
    // 动态规划
    // dp[i]: i所需的最少的完全平方数的个数
    int numSquares(int n)
    {
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; i++)
        {
            dp[i] = i; // 初始化为i，表示全都是1
            for (int j = 1; j < i; j++)
            {
                if (i - pow(j, 2) >= 0)
                    dp[i] = min(dp[i], dp[i - pow(j, 2)] + 1);
            }
        }
        return dp[n];
    }

    // bfs+贪心
    int numSquares_bfs(int n)
    {
        // 小于等于n的所有完全平方数
        vector<int> squares = generateSquares(n);
        queue<int> que;
        que.push(n);
        int res = 0;
        while (!que.empty())
        {
            res++;
            // 当前层有多少个节点
            int size = que.size();
            // 遍历当前层的节点，把下一层符合条件的节点也放到队列中
            for (int i = 0; i < size; i++)
            {
                int val = que.front();
                que.pop();
                for (int j = 0; j < squares.size(); j++)
                {
                    // 当前节点值减去一个完全平方数，为下一层节点的值
                    // 如果差小于零，则后面的完全平方数就不用考虑了
                    if (val - squares[j] < 0)
                        break;
                    if (val - squares[j] == 0) // 如果差等于零，则说明找到了最后一个节点值
                        return res;
                    
                    // 其他的情况放入队列中
                    que.push(val - squares[j]);
                }
            }
        }

        return -1;
    }

    vector<int> generateSquares(int n)
    {
        vector<int> res;
        int i = 1;
        while (pow(i, 2) <= n)
        {
            res.push_back(pow(i, 2));
            i++;
        }
        return res;
    }
};

int main()
{
    int n;
    cin >> n;
    Solution s;
    int res = s.numSquares_bfs(n);
    cout << res << endl;
    return 0;
}