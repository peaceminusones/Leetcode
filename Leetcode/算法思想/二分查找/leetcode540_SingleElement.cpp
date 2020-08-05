#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    /*
     * 二分搜索
     *     因为只有一个数是单个，其他都是双数，所以数组的个数总是奇数
     *     所以，如果我们移除一对元素，然后计算出它的左边和右边，那一侧的元素个数为奇数，就能知道单个数在哪边
     * 
     * 1、先将l，r分别指向数组的首尾，然后进行二分搜索将数组的搜索空间减半，直到找到单一元素，或只剩下一个元素位置
     * 2、在每次的循环迭代中，确定mid。查看与中间元素相同的元素在那一侧（利用变量halvesAreEven），然后更新l和r
     * 3、最难的部分就是根据mid和halvesAreEven来更新l和r：
     *       可以分为4种情况：
     *                   1）mid相同元素在右边，且右边个数为奇数：l = mid + 2
     *                   2）mid相同元素在右边，且左边个数为奇数：r = mid - 1
     *                   3）mid相同元素在左边，且右边个数为奇数：l = mid + 1
     *                   4）mid相同元素在左边，且左边个数为奇数：r = mid - 2
    */
    int singleNonDuplicate(vector<int> &nums)
    {
        int l = 0, r = nums.size() - 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (mid + 1 < nums.size() && nums[mid] == nums[mid + 1]) // mid相同元素在右边
            {
                if ((r - (mid + 1)) % 2 != 0) //右边个数为奇数
                    l = mid + 2;
                else // 左边个数为奇数
                    r = mid - 1;
            }
            else if (mid - 1 >= 0 && nums[mid - 1] == nums[mid]) // mid相同元素在左边
            {
                if ((r - mid) % 2 != 0) // 右边个数为奇数
                    l = mid + 1;
                else // 左边个数为奇数
                    r = mid - 2;
            }
            else
                return nums[mid];
        }
        return nums[l]; // nums[r]、nums[l]都可以
    }

    /*
     * 仅对偶数索引二分搜索
     * 
     * 在单个元素之前，都是“偶数位的元素与它后一个相同”，在单个元素之后，会变成“奇数位的元素与它后一个相同”
     * 
     * 所以可以通过偶数索引确定单个元素在左侧还是在右侧
     * 
     * 奇数长度的数组首尾索引（l，r）都为偶数
     * 我们需要确保mid为偶数，所以如果mid是奇数，则减一
     * 如果mid后面的元素与mid相同，则单个元素在mid右边，所以l = mid + 2
     * 如果mid后面的元素与mid不同，则相同的元素在mid左边，或者mid是单个元素，所以r = mid
     * 一旦l=r，就返回
    */
    int singleNonDuplicate_1(vector<int> &nums)
    {
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            mid = mid % 2 == 0 ? mid : mid - 1;
            if (nums[mid] == nums[mid + 1])
                l = mid + 2;
            else
                r = mid;
        }
        return nums[l];
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
    int res = s.singleNonDuplicate_1(nums);
    cout << res << endl;

    return 0;
}