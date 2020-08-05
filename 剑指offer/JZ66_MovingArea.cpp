#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

class Solution
{
public:
    int movingCount(int threshold, int rows, int cols)
    {
        if (threshold <= 0)
            return 0;

        vector<vector<bool>> visited(rows, vector<bool>(cols));
        int count = 0;
        moving(threshold, rows, cols, 0, 0, visited, count);
        return count;
    }

    void moving(int threshold, int rows, int cols, int i, int j, vector<vector<bool>> &visited, int &count)
    {
        if (i < 0 || i >= rows || j < 0 || j >= cols || visited[i][j] == 1 || Sum(i) + Sum(j) > threshold)
        {
            return;
        }

        visited[i][j] = 1;
        count++;
        moving(threshold, rows, cols, i + 1, j, visited, count);
        moving(threshold, rows, cols, i - 1, j, visited, count);
        moving(threshold, rows, cols, i, j + 1, visited, count);
        moving(threshold, rows, cols, i, j - 1, visited, count);
    }

    int Sum(int num)
    {
        int sum = 0;
        while (num)
        {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
};

int main()
{
    return 0;
}