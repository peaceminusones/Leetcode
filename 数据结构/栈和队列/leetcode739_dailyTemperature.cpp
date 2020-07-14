#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &T)
    {
        vector<int> res(T.size());
        stack<pair<int, int>> temperature;
        temperature.push({T[0], 0});
        for (int i = 1; i < T.size(); i++)
        {
            while (!temperature.empty() && T[i] > temperature.top().first)
            {
                res[temperature.top().second] = (i - temperature.top().second);
                temperature.pop();
            }

            if (temperature.empty() || T[i] <= temperature.top().first)
            {
                temperature.push({T[i], i});
            }
        }
        return res;
    }

    // 优化！栈中只存下标，不存温度
    vector<int> dailyTemperatures1(vector<int> &T)
    {
        vector<int> res(T.size());
        stack<int> temp_index;
        temp_index.push(0);
        for (int i = 1; i < T.size(); i++)
        {
            while (!temp_index.empty() && T[i] > T[temp_index.top()])
            {
                res[temp_index.top()] = (i - temp_index.top());
                temp_index.pop();
            }

            temp_index.push(i);
        }
        return res;
    }
};

int main()
{
    vector<int> temperatrues;
    int temp;
    while (cin >> temp)
        temperatrues.push_back(temp);

    Solution s;
    vector<int> res = s.dailyTemperatures1(temperatrues);
    for (int r : res)
        cout << r << " ";
    return 0;
}