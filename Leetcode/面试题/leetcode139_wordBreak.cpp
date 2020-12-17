#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // 对于aaaaaaa {aaaa, aaa}情况错误
    bool wordBreak(string s, vector<string> wordDict)
    {
        vector<int> dp(wordDict.size());
        int start = 0, end = 0;
        for (; end < s.size(); end++)
        {
            string tmp = s.substr(start, end - start + 1);
            auto it = find(wordDict.begin(), wordDict.end(), tmp);
            if (it != wordDict.end())
            {
                start = end + 1;
                cout << tmp << endl;
            }
        }
        return start == s.size();
    }

    // bool wordBreak2(string s,vector<string> wordDict)
    // {
    //     for(int i=0;i<=s.size();i++)
    //     {
    //         for()
    //     }
    // }
};

int main()
{
    // string s;
    // cin >> s;
    // vector<string> wordDict;
    // string item;
    // while (cin >> item)
    // {
    //     wordDict.push_back(item);
    //     if (cin.get() == '\n')
    //         break;
    // }

    // Solution sol;
    // cout << sol.wordBreak(s, wordDict) << endl;

    cout << sizeof(int[10]) << endl;

    return 0;
}