#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    /*
     * 特殊情况直接返回false，循环正常结束，判断递减的次数，如果是1次则返回true，如果大于1次，则返回true
     * 举例子特殊情况：[2, 4, 0, 1]
     *     当下标i为2时，nums[2]=0，此时nums[i-1]>nums[i]，也就是4>0，这是我们为了保证非递减性，有两种选择
     *         1）把0放大，并保证0后面的数不能比4小，0前面的数均是非递减的
     *         2）把4缩小，并保证4前面的数不能比4大，4后面的数均是非递减的
     *     但是如果这两个选择中的保证都不能满足，则表示，不能通过修改一个数而变为非递减数组
     *     例如本例中0<4，如果选择放大0，但后面的1<4，不能满足选择（1）
     *                   如果选择缩小4，但是4后面的数0小于2，不是非递减的，不能满足（2）
     *     所以直接返回false
     * 
     * 如果不是特殊情况，则count++，表示可以通过修改一个数，保证非递减性，如果count>1，返回false，小于或等于1，则返回true
    */
    bool checkPossibility(vector<int> &nums)
    {
        int cnt = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i - 1] > nums[i])
            {
                if (i + 1 < nums.size() && i - 2 >= 0 && nums[i + 1] < nums[i - 1] && nums[i - 2] > nums[i] && i - 2 >= 0)
                    return false;
                cnt++;
            }
        }
        return cnt <= 1;
    }

    /*
     * 方法二：
     *     遍历一遍nums，用d记录相邻两点是递减的次数，用g记录相隔一个点的两个数是递减的次数
     *     如果d或者g为2，则返回false，反之返回true
    */
    bool checkPossibility_1(vector<int> &nums)
    {
        int d = 0, g = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] > nums[i + 1])
                d++;
            if (i - 1 >= 0 && i + 1 < nums.size() && nums[i - 1] > nums[i + 1])
                g++;
            if (d >= 2 || g >= 2)
                return false;
        }
        return true;
    }

    /*
     * 方法三：实际上就是在i和i+1逆序的时候，判断i-1和i+1是升序还是逆序
     *     如果nums[i-1]<nums[i+1]：修改nums[i]
     *     如果nums[i-1]>nums[i+1]：修改nums[i+1]
    */
    bool checkPossibility_2(vector<int> &nums)
    {
        int cnt = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] <= nums[i + 1])
                continue;
            cnt++;
            if (cnt == 2)
                return false;

            if (i - 1 >= 0 && nums[i - 1] < nums[i + 1])
                nums[i] = nums[i - 1];
            if (i - 1 >= 0 && nums[i - 1] > nums[i + 1])
                nums[i + 1] = nums[i];
        }
        return true;
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
    bool res = s.checkPossibility_2(nums);
    cout << res << endl;

    return 0;
}