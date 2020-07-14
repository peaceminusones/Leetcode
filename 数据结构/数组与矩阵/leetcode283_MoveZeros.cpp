#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void moveZeros(vector<int> &nums)
    {
        // 找到第一个0的位置
        int i = 0, j = 0;
        while (i < nums.size() && nums[i] != 0)
            i++;
        j = i;
        // 从第一个0位置开始，让0和后面第一个非0数相交换
        while (i < nums.size() && j < nums.size())
        {
            while (i < nums.size() && nums[i] != 0)
                i++;
            while (j < nums.size() && nums[j] == 0)
                j++;

            if (i < nums.size() && j < nums.size())
                swap(nums[i], nums[j]);
            i++, j++;
        }
    }

    // 上一种方法的写法简化，但是时间复杂度上升了！
    void moveZeros2(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                int j = i;
                while (j < nums.size() && nums[j] == 0)
                    j++;

                if (j < nums.size())
                    swap(nums[i], nums[j]);
                j++;
            }
        }
    }

    // 方法三，记录零的个数，并把非零元素一次重新放入nums中，最后把0补全
    void moveZeros3(vector<int> &nums)
    {
        int i = 0;
        for (auto n : nums)
        {
            if (n != 0)
                nums[i++] = n;
        }

        while (i < nums.size())
        {
            nums[i++] = 0;
        }
    }
};

int main()
{
    vector<int> nums;
    int item;
    while (cin >> item)
        nums.push_back(item);
    Solution s;
    s.moveZeros3(nums);
    for (auto n : nums)
        cout << n << " ";
    return 0;
}