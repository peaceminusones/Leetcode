#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int arrayNesting(vector<int> &nums)
    {
        vector<int> visited(nums.size());
        int res = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int start = i;
            int count = 0;
            while (visited[start] != -1)
            {
                visited[start] = -1;
                start = nums[start];
                count++;
            }
            res = max(res, count);
        }

        return res;
    }
};

int main()
{
    vector<int> nums;
    int item;
    while (cin >> item)
    {
        nums.push_back(item);
    }
    Solution s;
    int res = s.arrayNesting(nums);
    cout << res << endl;

    return 0;
}