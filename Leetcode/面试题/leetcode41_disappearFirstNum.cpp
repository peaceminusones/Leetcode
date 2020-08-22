#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    // leetcode41 缺失的第一个正数
    int firstMissingPositive(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
                swap(nums[nums[i] - 1], nums[i]);
        }

        for (int i = 0; i < n; i++)
        {
            if (nums[i] != i + 1)
                return i + 1;
        }

        return n + 1;
    }

    // leetcode268 缺失数字
    // 给定一个包含 0, 1, 2, ..., n 中 n 个数的序列，找出 0 .. n 中没有出现在序列中的那个数
    int missingNumber(vector<int> &nums)
    {
        int res = 0;
        nums.push_back(0);
        for (int i = 0; i < nums.size(); i++)
        {
            res = res ^ i ^ nums[i];
        }
        return res;
    }

    // leetcode448 找到所有数组中消失的数字
    // 给定一个范围在  1 ≤ a[i] ≤ n ( n = 数组大小 ) 的 整型数组，数组中的元素一些出现了两次，另一些只出现一次。
    // 找到所有在 [1, n] 范围之间没有出现在数组中的数字。
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        // 方法一：哈希表 ===================
        // unordered_map<int, int> map;
        // for (auto n : nums)
        // {
        //     map[n]++;
        // }

        // vector<int> res;
        // for (int i = 1; i <= nums.size(); i++)
        // {
        //     if (map.find(i) == map.end())
        //         res.push_back(i);
        // }
        // return res;
        // 方法二：原地修改 ===================
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++)
        {
            // 注意！因为是在原数组上修改
            // 所以用到的时候可能值已经变了，需要取余才能得到原来的数
            int index = (nums[i] - 1) % n;
            nums[index] += n;
        }

        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] <= n)
                res.push_back(i + 1);
        }
        return res;
    }

    // leetcode287 寻找重复数
    // 快慢指针
    int findDuplicate(vector<int> &nums)
    {
        int slow = 0;
        int fast = 0;
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        slow = 0;
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};

int main()
{
    vector<int> nums;
    int item;
    while (cin >> item)
    {
        nums.push_back(item);
        if (cin.get() == '\n')
            break;
    }
    Solution s;
    // leetcode41
    cout << s.firstMissingPositive(nums) << endl;

    // leetcode268
    // cout << s.missingNumber(nums) << endl;

    // leetcode448
    // vector<int> res = s.findDisappearedNumbers(nums);
    // for (auto r : res)
    //     cout << r << " ";
    // cout << endl;

    // leetcode287
    // cout << s.findDuplicate(nums) << endl;

    return 0;
}