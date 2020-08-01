#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // 滑动窗口！！！！！！
    vector<vector<int>> FindContinuousSequence(int sum)
    {
        vector<vector<int>> res;
        if (sum == 0)
            return res;

        int start = 1, end = 1;  // 初始化窗口为0
        int total = 0;           // 窗口中的和也为0
        while (start <= sum / 2) // 如果start大于或等于sum的一半，则后面连续两个数是一定大于sum的，所以跳出循环
        {
            if (total < sum) // 当前窗口中的和小于sun
            {
                total += end; // 把窗口的最后一个值加上，然后有边界向右扩大窗口
                end++;
            }
            else if (total > sum)
            {
                total -= start; // 把窗口的第一个值删掉，然后左边界向右缩小窗口
                start++;
            }
            else
            {
                vector<int> tmp;
                for (int i = start; i < end; i++)
                    tmp.push_back(i);
                res.push_back(tmp);
                total -= start;
                start++;
            }
        }
        return res;
    }

    // 前缀和
    // vector<vector<int>> FindContinuousSequence_prefix(int sum)
    // {
    // }
};

int main()
{
    int sum;
    cin >> sum;
    Solution s;
    vector<vector<int>> res = s.FindContinuousSequence(sum);
    for (int i = 0; i < res.size(); i++)
    {
        for (auto r : res[i])
            cout << r << " ";
        cout << endl;
    }

    return 0;
}