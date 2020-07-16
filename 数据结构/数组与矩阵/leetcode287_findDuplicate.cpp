#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    // 哈希表！但是空间复杂度不是O（1）
    int findDuplicate(vector<int> &nums)
    {
        unordered_map<int, int> map;
        for (auto n : nums)
        {
            auto it = map.find(n);
            if (it != map.end())
                return n;
            map[n]++;
        }
        return 0;
    }

    // 二分法！不过不是堆索引二分，而是对值二分
    int findDuplicate1(vector<int> &nums)
    {
        int n = nums.size();
        int left = 1;
        int right = n - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;

            int cnt = 0;
            for (auto n : nums)
            {
                if (n <= mid)
                    cnt++;
            }
            if (cnt > mid)
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }

    // 方法三：快慢指针（类似环形链表的方法） =============================================
    // 数组中如果有重复的数，那么就会产生多对一的映射，这样，形成的链表就一定会有环路了
    // 1.数组中有一个重复的整数 <==> 链表中存在环
    // 2.找到数组中的重复整数 <==> 找到链表的环入口
    int findDuplicate2(vector<int> &nums)
    {
        int slow = 0;
        int fast = 0;
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        fast = 0;
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
    }

    Solution s;
    int res = s.findDuplicate2(nums);
    cout << res << endl;
    return 0;
}