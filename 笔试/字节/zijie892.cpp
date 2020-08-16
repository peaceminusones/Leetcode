#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution
{
public:
    int MaxSubSum(vector<int> nums)
    {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];
        
        int res = 0;
        for (int j = 1; j <= nums.size(); j++)
        {
            int sum = 0;
            for (int i = j; i <= nums.size(); i++)
            {
                sum += pow(-1, j - i) * nums[i - 1];
                res = max(res, sum);
            }
        }

        return res;
    }
};

int main()
{
    int n;
    cin >> n;
    int item;
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        cin >> item;
        nums.push_back(item);
    }

    Solution s;
    cout << s.MaxSubSum(nums) << endl;
    return 0;
}