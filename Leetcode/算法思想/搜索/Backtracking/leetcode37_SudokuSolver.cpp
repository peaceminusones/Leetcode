#include <iostream>
#include <vector>
#include <bitset>
#include <string>
using namespace std;

class Solution
{
public:
    void solveSudoku(vector<vector<char>> &board)
    {
        if (board.empty())
            return;

        vector<vector<bool>> usedr(board.size()); // usedr[i][j]==1：第i行，数字j被用过了（1<=j<=9）
        for (int i = 0; i < board.size(); i++)
            usedr[i].resize(10);
        vector<vector<bool>> usedc(board[0].size()); // usedc[i][j]==1：第i列，数字j被用过了（1<=j<=9）
        for (int i = 0; i < board[0].size(); i++)
            usedc[i].resize(10);
        // 小方块的数量
        int n = (board.size() / 3) * (board[0].size() / 3);
        vector<vector<bool>> usedb(n); // used[i][j]==1：第i个小方块，数字j被用过了（1<=j<=9）
        for (int i = 0; i < n; i++)
            usedb[i].resize(10);

        // 对board先遍历一遍，因为board中有一些数字，更新usedr,usedc,usedb
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] >= '0' && board[i][j] <= '9')
                {
                    int num = board[i][j] - '0';
                    usedr[i][num] = 1;
                    usedc[j][num] = 1;
                    // 小方块的索引
                    int index = (i / 3) * 3 + (j / 3);
                    usedb[index][num] = 1;
                }
            }
        }

        backtrack(board, usedr, usedc, usedb, 0, 0);
    }

    bool backtrack(vector<vector<char>> &board, vector<vector<bool>> &usedr, vector<vector<bool>> &usedc, vector<vector<bool>> &usedb, int row, int col)
    {
        // 换行
        if (col == board[0].size())
            return backtrack(board, usedr, usedc, usedb, row + 1, 0);

        // 找到一个可行解
        if (row == board.size())
            return true;

        // 如果当前位置有预设的数字，跳过
        if (board[row][col] != '.')
            return backtrack(board, usedr, usedc, usedb, row, col + 1);

        for (int num = 1; num <= 9; num++)
        {
            if (usedr[row][num] == 1 || usedc[col][num] == 1 || usedb[(row / 3) * 3 + col / 3][num] == 1)
                continue;
            board[row][col] = num + '0';
            usedr[row][num] = 1;
            usedc[col][num] = 1;
            usedb[(row / 3) * 3 + col / 3][num] = 1;

            // 如果找到一个可行解，立即结束
            if (backtrack(board, usedr, usedc, usedb, row, col + 1))
                return true;

            board[row][col] = '.';
            usedr[row][num] = 0;
            usedc[col][num] = 0;
            usedb[(row / 3) * 3 + col / 3][num] = 0;
        }

        // 穷举完1-9，说明此路不通；
        return false;
    }
};

int main()
{
    vector<vector<char>> boards;
    vector<char> board;
    char item;
    cin >> item;
    while (item != '#')
    {
        board.push_back(item);
        if (cin.get() == '\n')
        {
            boards.push_back(board);
            board.clear();
        }
        if (cin.peek() == '\n')
        {
            boards.push_back(board);
        }
        cin >> item;
    }

    Solution s;
    s.solveSudoku(boards);
    cout << endl;
    for (int i = 0; i < boards.size(); i++)
    {
        for (int j = 0; j < boards[0].size(); j++)
        {
            cout << boards[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}