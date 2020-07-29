#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    vector<string> Permutation(string str)
    {
        vector<string> res;
        if (str.empty())
            return res;
        vector<bool> visited(str.size());
        string cur;
        backtrack(str, res, visited, cur);
        return res;
    }

    void backtrack(string str, vector<string> &res, vector<bool> &visited, string &cur)
    {
        if (cur.size() == str.size())
        {
            res.push_back(cur);
            return;
        }

        for (int i = 0; i < str.size(); i++)
        {
            if (visited[i] == 1 || (i > 0 && str[i] == str[i - 1] && visited[i - 1] == 1))
                continue;

            visited[i] = 1;
            cur.push_back(str[i]);
            backtrack(str, res, visited, cur);
            cur.pop_back();
            visited[i] = 0;
        }
    }
};

int main()
{
    string str;
    cin >> str;
    Solution s;
    vector<string> res = s.Permutation(str);
    for (auto r : res)
        cout << r << " ";
    return 0;
}