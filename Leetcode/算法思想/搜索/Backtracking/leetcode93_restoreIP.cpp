#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    /**
     * 暴力四层循环，用if剪枝 =============================================================================
    */
    vector<string> restoreIpAddresses(string s)
    {
        vector<string> res;
        if (s.empty())
            return res;

        for (int a = 1; a < 4; a++)
        {
            for (int b = 1; b < 4; b++)
            {
                for (int c = 1; c < 4; c++)
                {
                    for (int d = 1; d < 4; d++)
                    {
                        if (a + b + c + d == s.size())
                        {
                            string s1 = s.substr(0, a);
                            string s2 = s.substr(a, b);
                            string s3 = s.substr(a + b, c);
                            string s4 = s.substr(a + b + c, d);
                            if (checkValid(s1) && checkValid(s2) && checkValid(s3) && checkValid(s4))
                            {
                                string ip = s1 + '.' + s2 + '.' + s3 + '.' + s4;
                                res.push_back(ip);
                            }
                        }
                    }
                }
            }
        }

        return res;
    }

    bool checkValid(string s)
    {
        if (s.empty())
            return false;

        int val = stoi(s);
        if (val > 255 || val < 0)
            return false;
        if (s.size() == 3 && val < 100)
            return false;
        if (s.size() == 2 && val < 10)
            return false;

        return true;
    }

    /**
     * 回溯法！！==================================================================================
    */
    vector<string> restoreIpAddresses_back(string s)
    {
        vector<string> res;
        if (s.empty())
            return res;
        vector<string> cur;

        backtracking(s, 0, cur, res);

        return res;
    }

    // s:字符串
    // pos:当前遍历到字符串中的位置
    // cur:存放当前已经确定好的ip段
    void backtracking(string &s, int pos, vector<string> &cur, vector<string> &res)
    {
        // cur存储了4个ip段
        if (cur.size() == 4)
        {
            // pos遍历到结尾
            if (pos == s.size())
                res.push_back(cur[0] + '.' + cur[1] + '.' + cur[2] + '.' + cur[3]);

            // pos没有遍历到结尾
            return;
        }

        // ip地址的每段最少有一个数字，最多有3个数字
        for (int i = 1; i < 4; i++)
        {
            // 如果当前位置距离s的末尾小于3，则直接返回
            if (pos + i > s.length())
                break;

            // 从位置pos开始，截取长度为i的字符串
            string segment = s.substr(pos, i);  
            // 判断是否是合法的ip段
            if (checkValid(segment))
            {
                // 把合法的ip段放入cur中
                cur.push_back(segment);
                // 从pos+i位置开始重新截取
                backtracking(s, pos + i, cur, res);
                // 撤销选择
                cur.pop_back();
            }
        }
    }
};

int main()
{
    string s;
    cin >> s;
    Solution sol;
    vector<string> res = sol.restoreIpAddresses_back(s);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    return 0;
}