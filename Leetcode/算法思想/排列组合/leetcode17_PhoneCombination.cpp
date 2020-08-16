#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
    unordered_map<char, string> dic = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> res;
        if (digits.empty())
            return res;
        string cur;
        backtracking(digits, res, cur, 0);
        return res;
    }

    void backtracking(string &digits, vector<string> &res, string &cur, int index)
    {
        if (cur.size() == digits.size())
        {
            res.push_back(cur);
            return;
        }

        char number = digits[index];
        for (int i = 0; i < dic[number].size(); i++)
        {
            cur.push_back(dic[number][i]);
            backtracking(digits, res, cur, index + 1);
            cur.pop_back();
        }
    }
};

int main()
{
    string str;
    cin >> str;
    Solution s;
    vector<string> res = s.letterCombinations(str);
    for (auto r : res)
        cout << r << " ";
    return 0;
}