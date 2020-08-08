#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int MinEnergy(vector<pair<int, int>> meal, int T)
    {
        if (T == 0)
            return 0;

        sort(meal.begin(), meal.end(), cmp);

        int i = 0, j = meal.size() - 1;
        int energy = 2000;
        while (i < j)
        {
            if (meal[i].second == T)
            {
                energy = min(energy, meal[i].first);
                i++;
            }

            if (meal[i].second + meal[j].second >= T)
            {
                if (meal[i].first + meal[j].first < energy)
                {
                    energy = min(energy, meal[i].first + meal[j].first);
                    if (meal[i + 1].first < meal[i].first)
                        i++;
                    else
                        j--;
                }
                else
                {
                    j--;
                }
            }

            if (meal[i].second + meal[j].second < T)
            {
                j--;
            }
        }

        return (energy == 2000) ? -1 : energy;
    }

    static bool cmp(pair<int, int> a, pair<int, int> b)
    {
        if (a.second == b.second)
            return a.first < b.first;
        return a.second > b.second;
    }
};

int main()
{
    int N, M, T;
    cin >> N >> M >> T;
    vector<pair<int, int>> meal;
    int item1, item2;
    for (int i = 0; i < M + N; i++)
    {
        cin >> item1 >> item2;
        meal.push_back(pair<int, int>{item1, item2});
    }

    Solution s;
    int res = s.MinEnergy(meal, T);
    cout << res << endl;
    return 0;
}