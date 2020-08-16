#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

class Solution
{
public:
    // bool Game24Points(int *num, int arrLen)
    // {
    //     double a = num[0], b = num[1], c = num[2], d = num[3];
    //     return points24_4(a, b, c, d);
    // }

    // bool points24_1(double a)
    // {
    //     return abs(a - 24) < 1e-6;
    // }

    // bool points24_2(double a, double &b)
    // {
    //     return points24_1(a + b) || points24_1(a - b) || points24_1(b - a) || points24_1(a * b) || points24_1(a / b) || points24_1(b / a);
    // }

    // bool points24_3(double a, double &b, double &c)
    // {
    //     return points24_2(b + c, a) ||
    //            points24_2(b - c, a) ||
    //            points24_2(c - b, a) ||
    //            points24_2(b * c, a) ||
    //            points24_2(b / c, a) ||
    //            points24_2(c / b, a) ||
    //            points24_2(a + c, b) ||
    //            points24_2(a - c, b) ||
    //            points24_2(c - a, b) ||
    //            points24_2(c * a, b) ||
    //            points24_2(a / c, b) ||
    //            points24_2(c / a, b) ||
    //            points24_2(a + b, c) ||
    //            points24_2(a - b, c) ||
    //            points24_2(b - a, c) ||
    //            points24_2(a * b, c) ||
    //            points24_2(a / b, c) ||
    //            points24_2(b / a, c);
    // }

    // bool points24_4(double a, double b, double c, double d)
    // {
    //     return points24_3(c + d, a, b) ||
    //            points24_3(c - d, a, b) ||
    //            points24_3(d - c, a, b) ||
    //            points24_3(c * d, a, b) ||
    //            points24_3(c / d, a, b) ||
    //            points24_3(d / c, a, b) ||
    //            points24_3(b + d, a, c) ||
    //            points24_3(b - d, a, c) ||
    //            points24_3(d - b, a, c) ||
    //            points24_3(b * d, a, c) ||
    //            points24_3(b / d, a, c) ||
    //            points24_3(d / b, a, c) ||
    //            points24_3(a + b, c, d) ||
    //            points24_3(a - b, c, d) ||
    //            points24_3(b - a, c, d) ||
    //            points24_3(a * b, c, d) ||
    //            points24_3(a / b, c, d) ||
    //            points24_3(b / a, c, d);
    // }

    bool judgePoint24(vector<int> &nums)
    {
        bool res = false;
        double eps = 1e-6;
        vector<double> arr(nums.begin(), nums.end());
        helper(arr, eps, res);
        return res;
    }

    void helper(vector<double> &nums, double &eps, bool &res)
    {
        if (res)
            return;

        if (nums.size() == 1)
        {
            if (abs(nums[0] - 24) < eps)
                res = true;

            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                double a = nums[i], b = nums[j];
                vector<double> newnum{a + b, a - b, b - a, a * b};
                if (a > eps)
                    newnum.push_back(b / a);
                if (b > eps)
                    newnum.push_back(a / b);

                nums.erase(nums.begin() + i);
                nums.erase(nums.begin() + j);
                for (auto k : newnum)
                {
                    nums.push_back(k);
                    helper(nums, eps, res);
                    // 回溯
                    nums.pop_back();
                }
                nums.insert(nums.begin() + j, b);
                nums.insert(nums.begin() + i, a);
            }
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
        if (cin.get() == '\n')
            break;
    }
    Solution s;
    cout << s.judgePoint24(nums) << endl;
    return 0;
}