#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool findNumberIn2DArray(vector<vector<int>> &matrix, int target)
    {
        int i = matrix.size() - 1, j = 0;
        while (i >= 0 && j < matrix[0].size())
        {
            if (matrix[i][j] > target)
                i--;
            else if (matrix[i][j] < target)
                j++;
            else if (matrix[i][j] == target)
                return true;
        }
        return false;
    }
};

int main()
{
    int target;
    cin >> target;
    
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

    
    Solution s;
    cout << s.findNumberIn2DArray(matrix, target) << endl;

    return 0;
}