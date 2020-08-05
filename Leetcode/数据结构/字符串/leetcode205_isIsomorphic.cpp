#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        return isIsomorphicHelper(s, t) && isIsomorphicHelper(t, s);
    }

    bool isIsomorphicHelper(string s, string t)
    {
        if (s.size() != t.size())
            return false;
        unordered_map<char, char> mapping;
        for (int i = 0; i < s.size(); i++)
        {
            auto it = mapping.find(s[i]);
            if (it != mapping.end())
            {
                if (mapping[s[i]] != t[i])
                    return false;
            }
            else
            {
                mapping[s[i]] = t[i];
            }
        }
        return true;
    }

    // 进化！
    bool isIsomorphic1(string s, string t)
    {
        if (s.size() != t.size())
            return false;

        // 对比两个字符串对应位置的字符在字符串内第一次出现的位置
        for (int i = 0; i < s.size(); i++)
        {
            if (s.find(s[i]) != t.find(t[i]))
                return false;
        }
        return true;
    }
};

int main()
{
    string s, t;
    cin >> s >> t;

    Solution sol;
    bool res = sol.isIsomorphic1(s, t);
    cout << res << endl;

    return 0;
}