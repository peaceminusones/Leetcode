#include <iostream>
#include <string.h>
using namespace std;

class Solution
{
public:
    int movingCount(int threshold, int rows, int cols)
    {
        if (threshold == 0)
            return 0;

        bool *visited = new bool[rows * cols];
        memset(visited, 0, rows * cols);

        int count = moving(threshold, rows, cols, 0, 0, visited);

        delete[] visited;
        return count;
    }

    int moving(int threshold, int rows, int cols, int i, int j, bool *visited)
    {
        if (i < 0 || i >= rows || j < 0 || j >= cols || visited[i * cols + j] == 1 || Sum(i) + Sum(j) > threshold)
            return 0;

        visited[i * cols + j] = 1;
        return 1 + moving(threshold, rows, cols, i - 1, j, visited) + moving(threshold, rows, cols, i + 1, j, visited) + moving(threshold, rows, cols, i, j - 1, visited) + moving(threshold, rows, cols, i, j + 1, visited);
    }

    int Sum(int num)
    {
        int count = 0;
        while (num)
        {
            count += num % 10;
            num = num / 10;
        }
        return count;
    }
};

int main()
{
    int threshold, rows, cols;
    cin >> threshold >> rows >> cols;
    cout << threshold << " " << rows << " " << cols << endl;
    Solution s;
    int res = s.movingCount(threshold, rows, cols);
    cout << res << endl;

    return 0;
}