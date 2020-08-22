#include <bits/stdc++.h>
using namespace std;



class Solution
{
public:
    int maxMoney(vector<int> server, vector<pair<int, int>> &client)
    {
        sort(server.begin(), server.end()); // 服务器宽带从小到大排序
        sort(client.begin(), client.end()); // 客户按照宽带的需求，从小到大排序

        int ans = 0;
        for (int i = 0; i < server.size(); ++i)
        {
            int max_price = 0, k = -1;
            for (int j = 0; j < client.size(); ++j)
            {
                // 从客户的宽带需求从小到大找，找到第i个服务器可以满足，且钱最多的那个
                if (server[i] >= client[j].first && client[j].second > max_price)
                {
                    // 记录当前最多的钱
                    max_price = client[j].second;
                    // 记录这个客户的id
                    k = j;
                }
                // 如果宽带不足，则跳出
                else if (server[i] < client[j].first)
                    break;
            }

            // 如果k不为-1，则表示成功租出
            if (k != -1)
            {
                // 记录租出去盈利的钱数
                ans += max_price;
                // 当前服务器的宽带置为负值，表示不能再选择
                server[i] = -1;
                // 客户的钱置为-1，表示不再会花钱
                client[k].second = -1;
            }
        }

        return ans;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> server(n);
    vector<pair<int, int>> client(m);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &server[i]);
    }
    for (int i = 0; i < m; ++i)
    {
        int t1 = 0, t2 = 0;
        scanf("%d%d", &t1, &t2);
        client[i] = make_pair(t1, t2);
    }

    Solution s;
    cout << s.maxMoney(server, client) << endl;
    return 0;
}