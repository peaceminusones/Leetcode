#include <iostream>
#include <vector>
#include <unordered_map>
#include <numeric>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> smallestRange(vector<vector<int>> &nums)
    {
        vector<pair<int, int>> sortArr;
        for (int i = 0; i < nums.size(); i++)
        {
            for (auto &n : nums[i])
            {
                sortArr.push_back({n, i});
            }
        }
        sort(sortArr.begin(), sortArr.end());

        vector<int> res = {0, (--sortArr.end())->first};
        unordered_map<int, int> visited;
        int left = 0, right = 0;
        for (; right < sortArr.size(); right++)
        {
            int number_r = sortArr[right].second;
            visited[number_r]++;
            while (visited.size() == nums.size())
            {
                if (res[1] - res[0] > sortArr[right].first - sortArr[left].first)
                {
                    res[0] = sortArr[left].first;
                    res[1] = sortArr[right].first;
                }

                int number_l = sortArr[left].second;
                visited[number_l]--;
                if (visited[number_l] == 0)
                    visited.erase(number_l);
                left++;
            }
        }

        return res;
    }
};

int main()
{
    vector<vector<int>> nums;
    vector<int> num;
    int item;
    while (cin >> item)
    {
        num.push_back(item);
        if (cin.get() == '\n')
        {
            nums.push_back(num);
            num.clear();
        }
        if (cin.peek() == '\n')
        {
            nums.push_back(num);
        }
    }

    Solution s;
    vector<int> res = s.smallestRange(nums);
    for (auto r : res)
        cout << r << " ";
    return 0;
}