#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> printMatrix(vector<vector<int>> matrix)
{
    vector<int> new_m;
    if (matrix.empty())
        return new_m;
    int col = matrix[0].size();
    int row = matrix.size();

    int left = 0, top = 0, right = col - 1, bottom = row - 1;
    while (top <= bottom && left <= right)
    {
        // 左到右
        for (int i = left; i <= right; i++)
            new_m.push_back(matrix[top][i]);
        // 上到下
        for (int i = top + 1; i <= bottom; i++)
            new_m.push_back(matrix[i][right]);
        // 右到左
        for (int i = right - 1; i >= left && top < bottom; i--)
            new_m.push_back(matrix[bottom][i]);
        // 下到上
        for (int i = bottom - 1; i > top && right > left; i--)
            new_m.push_back(matrix[i][left]);
        left++;
        top++;
        right--;
        bottom--;
    }
    return new_m;
}

int main()
{
    vector<vector<int>> m;
    vector<int> a;
    int n, item;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> item;
            a.push_back(item);
        }
        m.push_back(a);
        a.clear();
    }
    vector<int> results = printMatrix(m);
    for (int i = 0; i < results.size(); i++)
        cout << results[i] << " ";
    return 0;
}