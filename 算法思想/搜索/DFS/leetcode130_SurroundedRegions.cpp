#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class Solution
{
public:
    /**
     * 递归dfs ===============================================================================
    */
    void solve(vector<vector<char>> &board)
    {
        if (board.empty())
            return;

        // 重点在于把 与边界有连通的O 和 与边界没有连通的O 区分来
        // 先对边界上的O进行处理，如果遇到边界上有O，则逐个遍历，把与边界有连通的O都变为#
        // 这时与边界连通的O都变成了#，剩下的O都是被X包围的
        // 所以重新遍历整个board
        // 把剩余的O转换为X
        // 把变成#的重新变回O
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                // 边界上的O
                if (isEdge(i, j, board) && board[i][j] == 'O')
                {
                    dfs_stack(i, j, board);
                }
            }
        }

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }

    bool isEdge(int &i, int &j, vector<vector<char>> &board)
    {
        return (i == 0 || i == board.size() - 1 || j == 0 || j == board[0].size() - 1);
    }

    void dfs(int i, int j, vector<vector<char>> &board)
    {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] == 'X' || board[i][j] == '#')
            return;
        board[i][j] = '#';
        dfs(i - 1, j, board);
        dfs(i + 1, j, board);
        dfs(i, j - 1, board);
        dfs(i, j + 1, board);
    }

    /**
     * bfs ================================================================================
    */
    void solve_bfs(vector<vector<char>> &board)
    {
        if (board.empty())
            return;

        queue<pair<int, int>> que;
        int row = board.size();
        int col = board[0].size();
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (isEdge(i, j, board) && board[i][j] == 'O')
                {
                    bfs(i, j, board, que);
                }
            }
        }

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }

    void bfs(int i, int j, vector<vector<char>> &board, queue<pair<int, int>> &que)
    {
        int row = board.size();
        int col = board[0].size();

        que.push({i, j});
        board[i][j] = '#';
        while (!que.empty())
        {
            int x = que.front().first;
            int y = que.front().second;
            que.pop();
            if (x - 1 >= 0 && board[x - 1][y] == 'O')
            {
                que.push({x - 1, y});
                board[x - 1][y] = '#';
            }
            if (x + 1 < row && board[x + 1][y] == 'O')
            {
                que.push({x + 1, y});
                board[x + 1][y] = '#';
            }
            if (y - 1 >= 0 && board[x][y - 1] == 'O')
            {
                que.push({x, y - 1});
                board[x][y - 1] = '#';
            }
            if (y + 1 < col && board[x][y + 1] == 'O')
            {
                que.push({x, y + 1});
                board[x][y + 1] = '#';
            }
        }
    }

    /**
     * 非递归dfs ================================================================================
    */
    void dfs_stack(int i, int j, vector<vector<char>> &board)
    {
        cout << "dfs_stack" << endl;
        stack<pair<int, int>> st;
        st.push({i, j});
        board[i][j] = '#';
        while (!st.empty())
        {
            int x = st.top().first;
            int y = st.top().second; // 先不pop。等这个位置的上下左右都搜索不到后再弹出
            st.pop();
            // up
            if (x - 1 >= 0 && board[x - 1][y] == 'O')
            {
                st.push({x - 1, y});
                board[x - 1][y] = '#';
                continue;
            }
            // down
            if (x + 1 < board.size() && board[x + 1][y] == 'O')
            {
                board[x + 1][y] = '#';
                continue;
            }
            // left
            if (y - 1 >= 0 && board[x][y - 1] == 'O')
            {
                st.push({x, y - 1});
                board[x][y - 1] = '#';
                continue;
            }
            if (y + 1 < board[0].size() && board[x][y + 1] == 'O')
            {
                st.push({x, y + 1});
                board[x][y + 1] = '#';
                continue;
            }
            // 栈顶位置的上下左右都搜索不到O，弹出栈顶
            
        }
    }
};

int main()
{
    vector<vector<char>> board;
    vector<char> vec;
    char item;
    while (cin >> item)
    {
        if (item == 'q')
            break;
        vec.push_back(item);
        if (cin.get() == '\n')
        {
            board.push_back(vec);
            vec.clear();
        }
        if (cin.peek() == '\n')
            board.push_back(vec);
    }

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    Solution s;
    s.solve(board);
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}