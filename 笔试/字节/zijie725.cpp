#include <iostream>
#include <sstream>
#include <vector>
#include <stack>
#include <numeric>

using namespace std;

class Solution
{
public:
    int dividSum(int a, int b)
    {
        if (a == 0 || b == 0)
            return 0;
        if (b == 1)
            return a;

        vector<bool> visited(b + 1);
        int sum = 0;
        for (int i = 1; i <= b; i++)
        {
            if (i <= a / 2 && !visited[i])
            {
                int num1 = a / i;
                visited[i] = 1;

                int num2 = 0;
                if (num1 <= min(a / 2, b) && !visited[num1])
                {
                    num2 = a / num1;
                    visited[num1] = 1;
                }
                sum += num1 + num2;
            }
            else if (b > a && i > a / 2)
            {
                sum += a - (a / 2);
                break;
            }
            else if (b <= a && i > a / 2)
            {
                sum += b - (a / 2);
                break;
            }
        }

        return sum;
    }

    int noneZero(vector<int> &num)
    {
        int count = 0;
        vector<vector<int>> dp(num.size(), vector<int>(num.size()));
        for (int i = 0; i < num.size(); i++)
        {
            if (num[i] == 0)
            {
                dp[i][i] = 0;
            }
            else
            {
                count++;
                dp[i][i] = num[i];
            }
        }

        for (int i = 0; i < num.size(); i++)
        {
            for (int j = i + 1; j < num.size(); j++)
            {
                if (num[j] == 0)
                {
                    dp[i][j] = dp[i][j - 1];
                }
                else
                {
                    dp[i][j] = dp[i][j - 1] + num[j];
                }

                if (dp[i][j] != 0)
                    count++;
            }
        }
        return count;
    }
};

int main()
{
    Solution s;

    // int a, b;
    // cin >> a >> b;
    // int res = s.dividSum(a, b);
    // cout << res << endl;

    vector<int> num;
    int item;
    while (cin >> item)
    {
        num.push_back(item);
        if (cin.get() == '\n')
            break;
    }

    int res = s.noneZero(num);
    cout << res << endl;

    // Solution s;
    // vector<int> res = s.dailyTemperatures(temp);
    // for (auto r : res)
    //     cout << r << " ";
    // cout << endl;

    // string str;
    // cin >> str;
    // istringstream is(str);
    // string fields;
    // string field;
    // while (getline(is, field, '['))
    // {
    //     fields += field;
    // }
    // cout << fields << endl;
    // istringstream iis(fields);
    // fields = "";
    // while (getline(iis, field, ']'))
    // {
    //     fields += field;
    // }
    // cout << fields << endl;
    // is >> fields;
    // while (getline(is, field, ']'))
    // {
    //     fields += field;
    // }
    // cout << fields << endl;

    return 0;
}