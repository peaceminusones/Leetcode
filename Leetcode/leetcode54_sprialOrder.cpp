#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // 螺旋顺序打印矩阵
    // 通过左上角坐标，右下角坐标，缩小打印范围
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int lx = 0, ly = 0;
        int rx = matrix.size() - 1, ry = matrix[0].size() - 1;
        vector<int> res;
        while (lx <= rx && ly <= ry)
        {
            print(matrix, lx++, ly++, rx--, ry--, res);
        }
        return res;
    }

    void print(vector<vector<int>> &matrix, int lx, int ly, int rx, int ry, vector<int> &res)
    {
        // 上面一行
        for (int i = 0; i <= ry; i++)
            res.push_back(matrix[lx][i]);

        // 右边一列
        for (int i = lx + 1; i <= rx; i++)
            res.push_back(matrix[i][ry]);

        // 如果左上角横坐标等于右下角横坐标，说明只有一行
        // 如果不等，则输出下面一行
        if (lx != rx)
        {
            for (int i = ry - 1; i >= ly; i--)
                res.push_back(matrix[rx][i]);
        }

        // 如果左上角纵坐标等于右下角纵坐标，说明只有一列
        // 如果不等，则输出左边一列
        if (ly != ry)
        {
            for (int i = rx - 1; i >= rx + 1; i--)
                res.push_back(matrix[i][ly]);
        }
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
            m.push_back(item);
        }
    }
    Solution s;
    vector<int> res = s.spiralOrder(matrix);
    for (auto r : res)
        cout << r << " ";
    return 0;
}