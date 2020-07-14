#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Soltuion
{
public:
    // 方法一：bfs 超时！！！！！！！！==================================================================
    // bool searchMatrix(vector<vector<int>> &matrix, int target)
    // {
    //     return bfs(matrix, target);
    // }

    // bool bfs(vector<vector<int>> &matrix, int &target)
    // {
    //     queue<pair<int, int>> que;
    //     que.push({0, 0});

    //     while (!que.empty())
    //     {
    //         int x = que.front().first;
    //         int y = que.front().second;
    //         que.pop();
    //         if (x < 0 || x >= matrix.size() || y < 0 || y >= matrix[0].size())
    //             continue;
    //         if (matrix[x][y] == target)
    //             return true;
    //         else if (matrix[x][y] < target)
    //         {
    //             que.push({x + 1, y}); // 下
    //             que.push({x, y + 1}); // 右
    //         }
    //     }
    //     return false;
    // }

    // 方法二：每一行分别二分法（通过） ===================================================================
    // bool searchMatrix(vector<vector<int>> &matrix, int target)
    // {
    //     for (int i = 0; i < matrix.size(); i++)
    //     {
    //         if (binarySearch(matrix[i], target))
    //             return true;
    //     }
    //     return false;
    // }

    // bool binarySearch(vector<int> &nums, int target)
    // {
    //     int start = 0;
    //     int end = nums.size() - 1;
    //     while (start <= end)
    //     {
    //         int m = start + (end - start) / 2;
    //         if (nums[m] == target)
    //             return true;
    //         else if (nums[m] < target)
    //         {
    //             start = m + 1;
    //         }
    //         else
    //         {
    //             end = m - 1;
    //         }
    //     }
    //     return false;
    // }

    // 方法三：从右上角开始遍历，就变成像是二叉树一样 =========================================================
    // 如果比target值比当前的值大，则往下走，如果比当前值小则往左走
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        if (matrix.empty())
            return false;
        int row = 0;
        int col = matrix[0].size() - 1;
        while (row < matrix.size() && col >= 0)
        {
            if (target > matrix[row][col])
                row++;
            else if (target < matrix[row][col])
                col--;
            else
                return true;
        }
        return false;
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

    int target;
    cin >> target;

    Soltuion s;
    bool res = s.searchMatrix(matrix, target);
    cout << res << endl;

    return 0;
}