#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    /*
     * 二分查找
    */
    int binarySearch(vector<int> &nums, int key)
    {
        int l = 0, r = nums.size() - 1;
        while (l <= r)
        {
            // int m = (l + r) / 2;  //可能出现加法溢出，即加法的结果大于整型能够表示的范围
            int m = l + (r - l) / 2; // r-l不会出现加法溢出的问题，所以最好用第二种方法
            if (nums[m] == key)
                return m;
            else if (key < nums[m])
                r = m - 1;
            else
                l = m + 1;
        }
        return -1;
    }

    /*
     * 二分查找变种
     *     在有重复元素的数组中找key的最左位置
     * 
     * ！！！注意边界值的判断
    */
    int binarySearch_1(vector<int> &nums, int key)
    {
        int l = 0, r = nums.size() - 1;
        while (l < r) // 注意边界
        {
            int m = l + (r - l) / 2;
            if (key <= nums[m])
                r = m; // 注意边界！
            else
                l = m + 1;
        }
        return r;
    }

    /*
     * 一个数x的开方一定在0~x之间，并且满足sqrt=x/sqrt，可以利用二分查找在0~x之间查找sqrt
    */
    int sqrt(int x)
    {
        if (x < 1)
            return 0;

        int l = 1, r = x;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            int sqrt = x / mid;
            if (mid == sqrt)
                return mid;
            else if (mid < sqrt)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return r; // 因为sqrt(8) = 2.828 = 2。再结合while的循环条件（l<=r），所以最后返回的是r
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
    cin.clear();
    cin.ignore();

    int k;
    cin >> k;

    Solution s;
    int res = s.binarySearch_1(nums, k);
    cout << res << endl;

    // int x;
    // cin >> x;
    // Solution s;
    // int res = s.sqrt(x);
    // cout << res << endl;

    return 0;
}