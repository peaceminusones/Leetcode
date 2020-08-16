#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution
{
public:
    // 优先参加结束时早的，且尽可能早的参加，时间复杂度O(N2)超时！！！！！！！
    // int maxEvents(vector<vector<int>> &events)
    // {
    //     sort(events.begin(), events.end(), cmp);
    //     int lastday = events[events.size() - 1][1];
    //     vector<int> visited(lastday);
    //     int res = 0;
    //     for (int i = 0; i < events.size(); i++)
    //     {
    //         int start = events[i][0];
    //         while (start <= events[i][1])
    //         {
    //             if (visited[start - 1] == 0)
    //             {
    //                 res++;
    //                 visited[start - 1] = 1;
    //                 break;
    //             }
    //             start++;
    //         }
    //     }
    //     return res;
    // }

    static bool cmp(vector<int> &a, vector<int> &b)
    {
        return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
    }

    // 优先参加结束时早的，且尽可能早的参加
    // 动态获得当前结束时间最早的会议：维护一个最小堆，记录当前可参加会议的结束时间
    // 在每个时间点，首先将当前时间点开始的会议加入最小堆，然后把已经结束的会议移出最小堆
    // 然后从剩下的会议中选择一个结束时间最早的去参加
    int maxEvents(vector<vector<int>> &events)
    {
        // 排序，把开始时间小的排在前面，方便我们把开始时间相同的都先放到堆中
        sort(events.begin(), events.end(), cmp);

        // 小顶堆
        priority_queue<int, vector<int>, greater<>> pq;
        int res = 0;
        int last = 1;          // 开始时间
        int i = 0;             //events下标
        int n = events.size(); // 多少个会议
        while (i < n || !pq.empty())
        {
            // 把开始时间相同的会议 的 结束时间 都放到堆中
            while (i < n && events[i][0] == last)
            {
                pq.push(events[i++][1]);
            }
            // pop掉当前时间已经结束的会议
            while (!pq.empty() && pq.top() < last)
            {
                pq.pop();
            }

            // 如果堆中不空，则堆顶就是当前要开的会议
            if (!pq.empty())
            {
                pq.pop();
                res++;
            }
            last++; // 当前时间加一
        }
        return res;
    }
};

int main()
{
    vector<vector<int>> events;
    vector<int> event;
    int item;
    while (cin >> item)
    {
        event.push_back(item);
        if (cin.get() == '\n')
        {
            events.push_back(event);
            event.clear();
        }
        if (cin.peek() == '\n')
            events.push_back(event);
    }

    Solution s;
    cout << s.maxEvents(events) << endl;

    return 0;
}