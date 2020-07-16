#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
using namespace std;

class Solution
{
public:
    // 方法一：归并排序（时间复杂度、空间复杂度较高）====================================================
    // int kthSmallest(vector<vector<int>> &matrix, int k)
    // {
    //     vector<int> res = matrix[0];
    //     for (int i = 1; i < matrix.size(); i++)
    //     {
    //         merge(res, matrix[i]);
    //     }
    //     return res[k - 1];
    // }

    // void merge(vector<int> &a, vector<int> &b)
    // {
    //     vector<int> res;
    //     int i = 0;
    //     int j = 0;
    //     while (i < a.size() && j < b.size())
    //     {
    //         if (a[i] <= b[j])
    //             res.push_back(a[i++]);
    //         else
    //             res.push_back(b[j++]);
    //     }

    //     if (i < a.size())
    //         res.insert(res.end(), a.begin() + i, a.end());
    //     if (j < b.size())
    //         res.insert(res.end(), b.begin() + j, b.end());
    //     a = res;
    // }

    // 方法二：二分查找 ==================================================================
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        if (matrix.empty())
            return 0;
        int n = matrix.size();
        if (k >= pow(n, 2))
            return 0;
        int left = matrix[0][0];
        int right = matrix[n - 1][n - 1];
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            // 如果小于或等于mid的个数小于k
            if (check(matrix, k, mid) < k)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        return right;
    }

    int check(vector<vector<int>> &matrix, int k, int mid)
    {
        int n = matrix.size();
        int count = 0;
        // 从左下角开始
        int i = n - 1;
        int j = 0;
        while (i >= 0 && j < n)
        {
            if (matrix[i][j] <= mid)
            {
                count += (i + 1);
                j++;
            }
            else
            {
                i--;
            }
        }
        return count;
    }
};

int main()
{
    vector<vector<int>> matrix;
    vector<int> m;
    int item;
    while (cin >> item)
    {
        m.push_back(item);
        if (cin.get() == '\n')
        {
            matrix.push_back(m);
            m.clear();
        }
        if (cin.peek() == '\n')
        {
            matrix.push_back(m);
        }
    }
    cin.clear();
    cin.ignore();

    int k;
    cin >> k;

    Solution s;
    int res = s.kthSmallest(matrix, k);
    cout << res << endl;
    return 0;
}