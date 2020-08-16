#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    vector<string> restoreIpAddresses(string s)
    {
        vector<string> res;
        vector<string> cur;
        backtracking(s, res, cur, 0);
        return res;
    }

    void backtracking(string &s, vector<string> &res, vector<string> &cur, int pos)
    {
        if (cur.size() == 4)
        {
            if (pos == s.size())
            {
                res.push_back(cur[0] + '.' + cur[1] + '.' + cur[2] + '.' + cur[3]);
            }
            return;
        }

        for (int i = 1; i < 4; i++)
        {
            if (pos + i > s.size())
                break;

            string substr = s.substr(pos, i);
            if (checkValid(substr))
            {
                cur.push_back(substr);
                backtracking(s, res, cur, pos + i);
                cur.pop_back();
            }
        }
    }

    bool checkValid(string &str)
    {
        if (str.empty())
            return false;

        int val = stoi(str);
        if (val > 255 || val < 0)
            return false;
        if (str.size() == 3 && val < 100)
            return false;
        if (str.size() == 2 && val < 10)
            return false;

        return true;
    }
};

int main()
{
    string str;
    cin >> str;
    Solution s;
    vector<string> res = s.restoreIpAddresses(str);
    for (auto r : res)
        cout << r << endl;
    return 0;
}