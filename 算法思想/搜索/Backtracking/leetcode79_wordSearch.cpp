#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    vector<pair<int, int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    bool exist(vector<vector<char>> &board, string word)
    {
        if (board.empty() || word.empty())
            return false;

        vector<vector<int>> visited(board.size());
        for (int i = 0; i < board.size(); i++)
            visited[i].resize(board[0].size());

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == word[0])
                {
                    string cur;
                    if (backtracking(board, word, visited, cur, i, j))
                        return true;
                }
            }
        }
        return false;
    }

    bool backtracking(vector<vector<char>> &board, string word, vector<vector<int>> &visited, string &cur, int i, int j)
    {
        if (cur == word)
            return true;

        if (word.substr(0, cur.size()) != cur)
            return false;

        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || visited[i][j] == 1)
            return false;

        visited[i][j] = 1;
        cur.push_back(board[i][j]);
        for (int d = 0; d < direction.size(); d++)
        {
            if (backtracking(board, word, visited, cur, i + direction[d].first, j + direction[d].second))
                return true;
        }
        cur.pop_back();
        visited[i][j] = 0;
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
    cin.clear();
    cin.ignore();
    string word;
    cin >> word;

    Solution s;
    bool res = s.exist(boards, word);
    cout << res << endl;
    return 0;
}