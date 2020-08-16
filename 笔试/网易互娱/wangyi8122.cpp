#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution
{
public:
    vector<vector<int>> Cross(vector<vector<int>> nums)
    {
        vector<vector<int>> res;
        for (int i = 0; i < nums.size(); i++)
        {
            int sum = accumulate(nums[i].begin(), nums[i].end(), 0);
            for (int j = 0; j < nums[i].size(); j++)
            {
            }
        }
        return res;
    }

    // void sumvalue(vector<vector<int>> nums, int i, int j, int sum)
    // {
    // }
};

int main()
{
    int N;
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

    nums[1].erase(nums[1].begin() + 1);

    for (int i = 0; i < nums.size(); i++)
    {
        for (auto n : nums[i])
        {
            cout << n << " ";
        }
        cout << endl;
    }

    // Solution s;
    // vector<vector<int>> res = s.Cross(nums);
    // for (auto r : res)
    // {
    //     cout << r[0] << " " << r[1] << endl;
    // }
    return 0;
}