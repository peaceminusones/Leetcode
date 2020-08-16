#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int MaxTime(vector<vector<int>> &tasks)
    {
        unordered_map<int, vector<int>> time;
        for (auto task : tasks)
        {
            time[task[1]].push_back(task[0]);
        }

        int maxtime = 0;
        int id = 0;
        for (auto it = time.begin(); it != time.end(); it++)
        {
            if (it->second[1] - it->second[0] > maxtime)
            {
                id = it->first;
                maxtime = it->second[1] - it->second[0];
            }
        }

        return id;
    }
};

int main()
{
    int N;
    cin >> N;
    int M;
    cin >> M;
    vector<vector<int>> task;
    for (int i = 0; i < M; i++)
    {
        int time, flag, start;
        cin >> time >> flag >> start;
        task.push_back({time, flag, start});
    }

    Solution s;
    int res = s.MaxTime(task);
    cout << res << endl;

    return 0;
}