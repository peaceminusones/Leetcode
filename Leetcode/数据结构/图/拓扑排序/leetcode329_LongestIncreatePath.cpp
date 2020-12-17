#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        if (matrix.empty())
            return 0;
        // 统计每个位置的入度
        vector<vector<int>> indegrees(matrix.size(), vector<int>(matrix[0].size()));
        vector<vector<int>> direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                for (auto d : direction)
                {
                    if (isValid(matrix, i, j, d) && matrix[i + d[0]][j + d[1]] < matrix[i][j])
                        indegrees[i][j]++;
                }
            }
        }

        // 入度为0的放入que中
        queue<pair<int, int>> que;
        for (int i = 0; i < indegrees.size(); i++)
        {
            for (int j = 0; j < indegrees[0].size(); j++)
            {
                if (indegrees[i][j] == 0)
                    que.push({i, j});
            }
        }

        // 对入度为0的进行广度优先遍历
        int level = 0;
        while (!que.empty())
        {
            level++;
            int size = que.size();
            for (int i = 0; i < size; i++)
            {
                int curi = que.front().first;
                int curj = que.front().second;
                que.pop();
                for (auto d : direction)
                {
                    if (isValid(matrix, curi, curj, d) && matrix[curi + d[0]][curj + d[1]] > matrix[curi][curj])
                    {
                        indegrees[curi + d[0]][curj + d[1]]--;
                        if (indegrees[curi + d[0]][curj + d[1]] == 0)
                            que.push({curi + d[0], curj + d[1]});
                    }
                }
            }
        }
        return level;
    }

    bool isValid(vector<vector<int>> &matrix, int &i, int &j, vector<int> &d)
    {
        if (i + d[0] >= 0 && i + d[0] < matrix.size() && j + d[1] >= 0 && j + d[1] < matrix[0].size())
            return true;
        return false;
    }
};

int main()
{
    vector<vector<int>> nums;
    vector<int> num;
    int item;
    while (cin >> item)
    {
        num.push_back(item);
        if (cin.get() == '\n')
        {
            nums.push_back(num);
            num.clear();
        }
        if (cin.peek() == '\n')
        {
            nums.push_back(num);
        }
    }

    Solution s;
    int res = s.longestIncreasingPath(nums);
    cout << res << " ";

    return 0;
}