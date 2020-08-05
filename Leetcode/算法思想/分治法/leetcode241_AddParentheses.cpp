#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    /*
     * 方法一：递归 ===============================================================================
    */
    vector<int> diffWaysToCompute(string input)
    {
        vector<int> res;
        if (input.empty())
            return res;

        // 把input中运算符号前的string类型数字转换为int类型的数字
        int num = 0;
        int index = 0;
        while (index < input.size() && !isOperation(input[index]))
        {
            num = num * 10 + (input[index++] - '0');
        }
        // 终止条件：如果长度相等，说明input中没有符号，都是数字
        if (input.size() == index)
        {
            res.push_back(num);
            return res;
        }
        // 如果input中有符号
        for (int i = 0; i < input.size(); i++)
        {
            if (isOperation(input[i])) // 位置i处是运算符
            {
                // cout << input.substr(0, i) << " " << input.substr(i + 1, input.size() - i) << endl;
                vector<int> res1 = diffWaysToCompute(input.substr(0, i));                    // 对当前运算符左边递归
                vector<int> res2 = diffWaysToCompute(input.substr(i + 1, input.size() - i)); // 对当前运算符右边递归

                // cout << "res1:" << endl;
                // for (int p = 0; p < res1.size(); p++)
                //     cout << res1[p] << " ";
                // cout << endl;
                // cout << "res2:" << endl;
                // for (int q = 0; q < res2.size(); q++)
                //     cout << res2[q] << " ";
                // cout << endl;

                // 把两部分解通过符号input[i]计算，得到最终结果
                for (int j = 0; j < res1.size(); j++)
                {
                    for (int k = 0; k < res2.size(); k++)
                    {
                        // cout << res1[j] << " " << res2[k] << " " << input[i] << endl;
                        res.push_back(calculate(res1[j], res2[k], input[i]));
                    }
                }

                // cout << "res:" << endl;
                // for (int r = 0; r < res.size(); r++)
                //     cout << res[r] << " ";
                // cout << endl;
            }
        }

        return res;
    }

    int calculate(int a, int b, char op)
    {
        if (op == '+')
            return a + b;
        else if (op == '-')
            return a - b;
        else
            return a * b;
    }

    bool isOperation(char c)
    {
        return c == '+' || c == '-' || c == '*';
    }

    /*
     * 方法二：动态规划 ========================================================================
    */
    vector<int> diffWaysToCompute_dp(string input)
    {
        vector<int> res;
        if (input.empty())
            return res;

        vector<int> numlist;
        vector<char> oplist;
        int num = 0;
        for (int i = 0; i < input.size(); i++) // 把数字和运算符号分开提取出来
        {
            if (!isOperation(input[i]))
                num = num * 10 + (input[i] - '0');
            else if (isOperation(input[i]))
            {
                numlist.push_back(num);
                oplist.push_back(input[i]);
                num = 0;
            }
        }
        numlist.push_back(num); // 最后一个数放进去
        int N = numlist.size();

        /*
         * 初始化dp[0][0],dp[1][1],...
        */
        vector<vector<vector<int>>> dp(N); // 初始化第一维度的大小

        for (int i = 0; i < N; i++) // 初始化第二维度的大小
            dp[i].resize(N);

        for (int i = 0; i < N; i++) // 第三维度放入结果，先放入单个数字的结果，dp[0][0],dp[1][1],...
            dp[i][i].push_back(numlist[i]);

        // 一个数字的结果已经完成，接下来考虑两个数字到N个数字
        for (int n = 2; n <= N; n++)
        {
            // 开始下标
            for (int i = 0; i < N; i++)
            {
                // 结束下标
                int j = i + n - 1;
                // 如果结束下标超过存储数字数组的大小，则跳出循环
                if (j >= N)
                    break;

                // 计算dp[i][j] =====================================================
                // 将从i到j分成（i，k）（k+1，j）两部分，因为[j - i = n - 1 >= 1]
                vector<int> res;
                for (int k = i; k < j; k++)
                {
                    vector<int> res1 = dp[i][k];
                    vector<int> res2 = dp[k + 1][j];

                    // 两部分的结果两两在用运算符oplist[k]计算
                    for (int p = 0; p < res1.size(); p++)
                        for (int q = 0; q < res2.size(); q++)
                            res.push_back(calculate(res1[p], res2[q], oplist[k]));
                }
                dp[i][j] = res;
                // ==================================================================
            }
        }

        return dp[0][N - 1];
    }
};

int main()
{
    string input;
    cin >> input;
    // cout << input.substr(0, 2);
    Solution sol;
    // vector<int> res = sol.diffWaysToCompute(input);
    // for (int i = 0; i < res.size(); i++)
    //     cout << res[i] << " ";

    vector<int> res = sol.diffWaysToCompute_dp(input);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";

    return 0;
}