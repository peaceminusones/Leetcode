#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <numeric>
using namespace std;

class Solution
{

public:
    int number(vector<int> &nums, int N, int k)
    {
        int res = 0;
        vector<int> visited(nums.size());
        vector<int> cur;
        int maxn = 0;
        dfs(nums, visited, cur, k, 0, maxn);
        return maxn;
    }

    void dfs(vector<int> &nums, vector<int> &visited, vector<int> cur, int k, int res, int &maxn)
    {
        if (cur.size() == k)
        {
            res++;
            return;
        }
        if (accumulate(nums.begin(), nums.end(), 0) < 3)
        {
            maxn = max(maxn, res);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] && !visited[i])
            {
                cur.push_back(i);
                nums[i]--;
                visited[i] = 1;
                dfs(nums, visited, cur, k, res, maxn);
                visited[i] = 0;
                nums[i]++;
                cur.pop_back();
            }
        }
    }
};

int main()
{
    int N, k;
    cin >> N >> k;

    vector<int> nums;
    int item;
    for (int i = 0; i < 5; i++)
    {
        cin >> item;
        nums.push_back(item);
    }

    Solution s;
    cout << s.number(nums, N, k) << endl;

    return 0;
}