#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
using namespace std;

class Solution
{
public:
    /**
     * 【贪心+BFS】=======================================================================================
     * 从0到n有n+1个证书，可以把这n+1个整数看作是节点
     * 如果两个节点之间的差是一个完全平方数，我们就说这两个节点之间是有连接的
     * 通过这个思路我们可以建立一张图
     * 找到n到0的最短路径
     * 我们就找到了n至少需要几个完全平方数
    */
    int numSquares(int n)
    {
        // 小于等于n的所有完全平方数
        vector<int> squares = generateSquares(n);

        // 广度优先搜索需要用到队列
        // 把根节点n放入队列中
        queue<int> que;
        que.push(n);

        // 初始化了n+1个默认值为0的元素
        vector<bool> marked(n + 1);
        marked[n] = true; // n节点已被遍历过

        int level = 0;
        // 队列不空
        while (!que.empty())
        {
            level++;
            // 当前层有多少个节点
            int size = que.size();
            // 遍历当前层的节点，把下一层符合条件的节点也放到队列中
            for (int i = 0; i < size; i++)
            {
                int cur = que.front();
                que.pop();
                for (int j = 0; j < squares.size(); j++)
                {
                    // 当前节点值减去一个完全平方数，为下一层节点的值
                    int next = cur - squares[j];
                    // 如果差小于零，则后面的完全平方数就不用考虑了
                    if (next < 0)
                        break;
                    else if (next == 0) // 如果差等于零，则说明找到了最后一个节点值
                        return level;   // 找到了结果

                    // 其他的情况放入队列中
                    que.push(next);
                }
            }
        }
        return level;
    }

    vector<int> generateSquares(int n)
    {
        vector<int> squares;
        int square = 1;
        while (pow(square, 2) <= n)
        {
            squares.push_back(pow(square, 2));
            square++;
        }
        return squares;
    }

    vector<int> generateSquares_1(int n)
    {
        vector<int> squares;
        int square = 1;
        int diff = 3;
        while (square <= n)
        {
            squares.push_back(square);
            square += diff;
            diff += 2;
        }

        return squares;
    }
    /**
     * ================================================================================================
    */

    /**
     * 动态规划
    */
    int numSquares_dp(int n)
    {
        // 小于等于n的所有完全平方数
        vector<int> squares = generateSquares(n);
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; i++)
        {
            dp[i] = i;
            for (int j = 0; j < squares.size(); j++)
            {
                if (i - squares[j] < 0)
                    break;
                dp[i] = min(dp[i], dp[i - squares[j]] + 1);
            }
        }
        return dp[n];
    }
};

int main()
{
    int n;
    cin >> n;

    Solution s;
    int res = s.numSquares(n);
    cout << res << endl;

    int rres = s.numSquares_dp(n);
    cout << rres << endl;

    vector<int> res1 = s.generateSquares(n);
    for (int i = 0; i < res1.size(); i++)
        cout << res1[i] << " ";
    cout << endl;

    vector<int> res2 = s.generateSquares_1(n);
    for (int i = 0; i < res2.size(); i++)
        cout << res2[i] << " ";
    cout << endl;
    return 0;
}