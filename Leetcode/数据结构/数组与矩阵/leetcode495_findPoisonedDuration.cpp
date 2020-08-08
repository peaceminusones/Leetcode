#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution
{
public:
    int findPoisonedDuration(vector<int> &timeSeries, int duration)
    {
        if (timeSeries.empty())
            return 0;
        int total = 0;
        for (int i = 0; i < timeSeries.size() - 1; i++)
        {
            total += min(timeSeries[i + 1] - timeSeries[i], duration);
        }
        return total + duration;
    }
};

int main()
{
    vector<int> timeSeries;
    int time;
    while (cin >> time)
    {
        timeSeries.push_back(time);
        if (cin.get() == '\n')
            break;
    }

    int duration;
    cin >> duration;

    Solution s;
    int res = s.findPoisonedDuration(timeSeries, duration);
    cout << res << endl;
    return 0;
}