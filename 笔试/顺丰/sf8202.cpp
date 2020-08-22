#include <bits/stdc++.h>
using namespace std;

// 赏金猎人
// 任务有{开始时间，结束时间，获得的金钱}
// 给定n个任务，求不冲突的情况下，最多获得多少金钱

// 任务结构体
struct mission
{
    int start;
    int end;
    long long money;
};

class Solution
{
public:
    long long maxMoney(vector<mission> &task)
    {
        sort(task.begin(), task.end(), cmp);
        vector<long long> res(task.size());
        for (int i = 1; i < task.size(); i++)
        {
            // 从后往前找到和task[i]不重叠的任务
            int j;
            for (j = i - 1; j >= 0; j--)
            {
                if (task[j].end < task[i].start)
                    break;
            }

            // 选择当前任务
            long long cur = task[i].money;
            if (j >= 0)
            {
                cur = res[j] + task[i].money;
            }

            // 选择当前任务task[i]和不选择当前任务task[i]做对比，选择最大的
            // (res[i-1]) vs (res[j] + task[i].money)
            res[i] = max(res[i - 1], cur);
        }
        return res[task.size() - 1];
    }

    // 按照结束时间从小到大排序
    static bool cmp(mission &a, mission &b)
    {
        return a.end < b.end;
    }
};

int main()
{
    int n = 0;
    cin >> n;
    vector<mission> M(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> M[i].start >> M[i].end >> M[i].money;
    }

    Solution s;
    cout << s.maxMoney(M);
    return 0;
}