#include <iostream>
#include <string>
#include <vector>
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
        
        backtracking(digits, res, "", 0);
        return res;
    }

    void backtracking(string &digits, vector<string> &res, string letter, int index)
    {
        if (index == digits.size())
        {
            res.push_back(letter);
            return;
        }

        char pos = digits[index];
        for (int i = 0; i < dic[pos].size(); i++)
        {
            // 做出选择
            letter.push_back(dic[pos][i]);
            backtracking(digits, res, letter, index + 1);
            // 撤销选择
            letter.pop_back();
        }
    }
};

int main()
{
    string digits;
    cin >> digits;

    Solution s;
    vector<string> res = s.letterCombinations(digits);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    return 0;
}