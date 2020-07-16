#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isToeplitzMatrix(vector<vector<int>> &matrix)
    {
        for (int i = matrix.size() - 1; i >= 0; i--)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (i - 1 >= 0 && j + 1 < matrix[0].size() && matrix[i - 1][j] != matrix[i][j + 1])
                    return false;
            }
        }
        return true;
    }
};

int main()
{
    vector<vector<int>> matrixs;
    vector<int> matrix;
    int item;
    while (cin >> item)
    {
        matrix.push_back(item);
        if (cin.get() == '\n')
        {
            matrixs.push_back(matrix);
            matrix.clear();
        }
        if (cin.peek() == '\n')
        {
            matrixs.push_back(matrix);
        }
    }

    Solution s;
    bool res = s.isToeplitzMatrix(matrixs);
    cout << res << endl;
    return 0;
}