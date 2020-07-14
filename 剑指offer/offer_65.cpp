#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

/*
 * 回溯法经典算法！
 * 首先在矩阵中任选一个格子作为路径的起点，如果路径上的第i个字符不对应，则这个格子不可能处于路径上
 * 如果路径上的第i个字符是对应的，则往相邻的格子寻找第i+1字符
 * 除了边界，其他各自都有四个方向，重复以上过程。
 * 
 * 由于回溯法的递归特性，路径可以被开成一个栈。当在矩阵中定位了路径中前n个字符的位置之后
 * 而第n个字符对应格子的附近没找到第n+1个字符，则需要回溯到第n-1个字符，重新定位第n个字符
 * 
 * 由于路径不能重复进入同一个矩阵的格子，则需要定义一个和矩阵大小一样的bool矩阵，用于记录当前格子是否已在路径中
*/

class Solution
{
public:
    bool hasPath(char *matrix, int rows, int cols, char *str)
    {
        if (matrix == NULL || rows == 0 || cols == 0 || str == NULL)
            return false;

        // 记录当前位置是否已经走过
        bool *visited = new bool[rows * cols];
        memset(visited, 0, rows * cols);

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                // cout << i << " " << j << " " << matrix[i * cols + j] << endl;
                if (isPath(matrix, rows, cols, str, visited, i, j))
                    return true;
            }
        }
        return false;
    }

    bool isPath(char *matrix, int rows, int cols, char *str, bool *visited, int i, int j)
    {
        int index = i * cols + j; // 二维 --> 一维

        // 越界 || 该位置访问过了 || 当前位置不在路径里
        if (i < 0 || i >= rows || j < 0 || j >= cols || visited[index] || *str != matrix[index])
            return false;

        // 到达路径的末尾了
        if (*(str + 1) == '\0')
            return true;

        visited[index] = true;

        if (isPath(matrix, rows, cols, str + 1, visited, i - 1, j)     // 左
            || isPath(matrix, rows, cols, str + 1, visited, i + 1, j)  // 右
            || isPath(matrix, rows, cols, str + 1, visited, i, j - 1)  // 上
            || isPath(matrix, rows, cols, str + 1, visited, i, j + 1)) // 下
        {
            return true;
        }

        visited[index] = false; // 回溯
        return false;
    }
};

int main()
{
    char matrix[100];
    char item;
    int i = 0;
    while (cin >> item)
    {
        if (item == '#')
            break;

        *(matrix + i++) = item;
    }

    int rows, cols;
    cin >> rows >> cols;
    cout << rows << cols << endl;

    char str[100];
    i = 0;
    while (cin >> item)
    {
        if (item == '#')
            break;
        *(str + i++) = item;
    }

    Solution s;
    bool res = s.hasPath(matrix, rows, cols, str);
    cout << res << endl;

    return 0;
}