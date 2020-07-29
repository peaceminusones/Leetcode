#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> printMatrix(vector<vector<int>> matrix)
    {
        vector<int> res;
        int lx = 0, ly = 0, rx = matrix.size() - 1, ry = matrix[0].size() - 1;
        while (lx <= rx && ly <= ry)
        {
            print(lx++, ly++, rx--, ry--, matrix, res);
        }
        return res;
    }

    void print(int lx, int ly, int rx, int ry, vector<vector<int>> &matrix, vector<int> &res)
    {
        //(lx,ly):左上角的点坐标；(rx,ry):右下角的点坐标
        // 从左上角开始打印最上面一行
        for (int j = ly; j <= ry; j++)
            res.push_back(matrix[lx][j]);
        // 打印最右边一列
        for (int i = lx + 1; i <= rx; i++)
            res.push_back(matrix[i][ry]);

        if (rx - lx != 0) // 如果等于0，说明只有一行
        {
            for (int j = ry - 1; j >= ly; j--)
                res.push_back(matrix[rx][j]);
        }

        if (ry - ly != 0)
        {
            for (int i = rx - 1; i >= lx + 1; i--)
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
            matrix.push_back(m);
    }

    Solution s;
    vector<int> res = s.printMatrix(matrix);
    for (auto r : res)
    {
        cout << r << " ";
    }
    cout << endl;

    return 0;
}
