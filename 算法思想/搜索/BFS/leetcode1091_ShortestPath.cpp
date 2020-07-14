#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        // 如果grid为空，或者起始点就有障碍
        if (grid.empty() || grid[0][0] == 1)
            return -1;
        // 如果只有一个点
        if (grid.size() == 1)
            return 1;

        int N = grid.size();
        // 左上、上、右上、左、右、左下、下、右下
        vector<vector<int>> direction = {{-1, -1}, // 左上
                                         {-1, 0},  // 上
                                         {-1, 1},  // 右上
                                         {0, -1},  // 左
                                         {0, 1},   // 右
                                         {1, -1},  // 左下
                                         {1, 0},   // 下
                                         {1, 1}};  // 右下
        queue<pair<int, int>> que;
        que.push(pair<int, int>(0, 0)); // 起始位置放到队列中
        grid[0][0] = 1;                 // 起始位置的值变成1：表示已遍历过
        int level = 0;
        while (!que.empty())
        {
            level++;
            int size = que.size();
            for (int i = 0; i < size; i++)
            {
                pair<int, int> pos = que.front(); // 取出当前队列头部的位置
                que.pop();
                for (int j = 0; j < direction.size(); j++)
                {
                    int x = pos.first + direction[j][0]; // 分别对八个方向试探
                    int y = pos.second + direction[j][1];
                    if (x < 0 || x >= N || y < 0 || y >= N) // 如果超出范围，则考虑下一个方向
                        continue;
                    if (grid[x][y] == 1) // 如果下个位置是障碍物，则考虑下一个方向
                        continue;
                    if (x == N - 1 && y == N - 1) // 如果到达终点，则返回长度
                        return level + 1;

                    grid[x][y] = 1;  // 当前位置置为1
                    que.push(pair<int, int>(x, y));
                }
            }
        }
        return -1;
    }
};

int main()
{
    int N;
    cin >> N;
    vector<vector<int>> grid(N);
    int item;
    for (int i = 0; i < N; i++)
    {
        grid[i].resize(N);
        for (int j = 0; j < N; j++)
        {
            cin >> item;
            grid[i][j] = item;
        }
    }

    Solution s;
    int res = s.shortestPathBinaryMatrix(grid);
    cout << res << endl;
    return 0;
}