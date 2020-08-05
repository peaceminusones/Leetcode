#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

class Solution
{
public:
    bool hasPath(char *matrix, int rows, int cols, char *str)
    {
        if (matrix == NULL || rows == 0 || cols == 0 || str == NULL)
            return false;

        bool *visited = new bool[rows * cols];
        memset(visited, 0, rows * cols);

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (ishasPath(matrix, rows, cols, str, visited, i, j))
                    return true;
            }
        }
        return false;
    }

    bool ishasPath(char *matrix, int rows, int cols, char *str, bool *visited, int i, int j)
    {
        int index = i * cols + j;

        if (i < 0 || i >= rows || j < 0 || j >= cols || visited[index] == 1 || *str != matrix[index])
            return false;

        if (*(str + 1) == '\0')
            return true;

        visited[index] = 1;

        if (ishasPath(matrix, rows, cols, str + 1, visited, i + 1, j) ||
            ishasPath(matrix, rows, cols, str + 1, visited, i - 1, j) ||
            ishasPath(matrix, rows, cols, str + 1, visited, i, j + 1) ||
            ishasPath(matrix, rows, cols, str + 1, visited, i, j - 1))
            return true;

        visited[index] = 0;
        return false;
    }
};

int main()
{
    return 0;
}