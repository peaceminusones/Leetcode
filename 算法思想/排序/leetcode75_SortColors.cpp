#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
    /*
     * 计数排序的两趟扫描算法
     * 迭代计算出0、1 和 2 元素的个数，然后按照0、1、2的排序，重写当前数组
    */
    void sortColors(vector<int> &nums)
    {
        map<int, int> record;
        map<int, int>::iterator it;
        for (int i = 0; i < nums.size(); i++)
            record[nums[i]]++;

        vector<int> res;
        for (it = record.begin(); it != record.end(); it++)
        {
            int len = it->second;
            while (len--)
                res.push_back(it->first);
        }
        nums = res;
    }

    /*
     * 一趟扫描算法
     * 三个指针，p0追踪0的最右边界，p2追踪2的最左边界，cur追踪当前考虑的元素
     * 解题思路就是：
     *     cur遍历nums数组
     *     如果nums[cur]为0，则与p0位置的数交换，p0随之加一
     *     如果nums[cur]为2，则与p2位置的数交换，p2随之减一
    */
    void sortColors_threeP(vector<int> &nums)
    {
        int p0 = 0, p2 = nums.size() - 1;
        int cur = 0;

        int temp;
        while (cur <= p2)
        {
            if (nums[cur] == 0)
            {
                swap(nums[cur++], nums[p0++]);
            }
            else if (nums[cur] == 2)
            {
                swap(nums[cur], nums[p2--]);
            }
            else
                cur++;
        }
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

    Solution s;
    s.sortColors(nums);
    for (int i = 0; i < nums.size(); i++)
        cout << nums[i] << " ";

    return 0;
}