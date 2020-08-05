#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxComfort(vector<int> coins, vector<int> house)
    {
        sort(coins.begin(), coins.end());
        sort(house.begin(), house.end(), cmp);

        long sum = 0;
        // vector<bool> flag()
    }

    static bool cmp(pair<int, int> a, pair<int, int> b)
    {
        return a.first > b.first;
    }
};

int main()
{
    return 0;
}