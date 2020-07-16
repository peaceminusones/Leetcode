#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    /*
     * n = 8
     * k = 1: |1 2 3 4 5 6 7 8
     * k = 2: 1 |8 7 6 5 4 3 2
     * k = 3: 1 8 |2 3 4 5 6 7
     * k = 4: 1 8 2 |7 6 5 4 3
    */

    // 翻转就完事了~~~
    vector<int> constructArray(int n, int k)
    {
        vector<int> nums;
        for (int i = 1; i <= n; i++)
        {
            nums.push_back(i);
        }

        int size = nums.size();
        for (int i = 1; i <= k - 1; i += 1)
        {
            nums.insert(nums.begin() + i, nums[size - 1]);
            nums.erase(nums.begin() + size);
            reverse(nums.begin() + i + 1, nums.end());
        }

        return nums;
    }

    // 方法二：后面都是1，所以直接排前面k-1个数
    vector<int> constructArray1(int n, int k)
    {
        bool flag = 0; // 0:正向，1：负向
        vector<int> res;
        int val1 = 1;
        int val2 = n;
        for (int i = 1; i <= n; i++)
        {
            if (k > 0) // 先按照k的个数来安排前面的几个值
            {
                if (i % 2 != 0) // 奇数位
                {
                    res.push_back(val1); // 从1往后放
                    val1++;
                    flag = 0;
                }
                else // 偶数位
                {
                    res.push_back(val2); // 从n往前放
                    val2--;
                    flag = 1;
                }
                k--;
            }
            else
            {
                if (flag == 0) // 如果flag=0，剩下值正向补充
                {
                    int next = res[res.size() - 1] + 1;
                    res.push_back(next);
                }
                else // 如果flag=1，剩下值反向补充
                {
                    int next = res[res.size() - 1] - 1;
                    res.push_back(next);
                }
            }
        }
        return res;
    }

    // 方法三：上一个方法的简化
    vector<int> constructArray2(int n, int k)
    {
        vector<int> res;
        int val1 = 1;
        int val2 = n;
        for (int i = 1; i <= k; i++) // 同样先排前面的k个数
        {
            if (i % 2 != 0)
                res.push_back(val1++);
            else
                res.push_back(val2--);
        }

        if (k % 2 != 0)
        {
            for (int i = k; i < n; i++)
                res.push_back(res[res.size() - 1] + 1);
        }
        else
        {
            for (int i = k; i < n; i++)
                res.push_back(res[res.size() - 1] - 1);
        }
        return res;
    }
};

int main()
{
    int n, k;
    cin >> n >> k;

    Solution s;
    vector<int> res = s.constructArray2(n, k);
    for (auto r : res)
        cout << r << " ";
    return 0;
}