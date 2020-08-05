#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution
{
    unordered_map<char, int> map; //用来记录每个字符出现了多少次
    queue<char> q;

public:
    void Insert(char ch)
    {
        // 如果ch是第一次出现
        if (map.find(ch) == map.end())
        {
            q.push(ch);
        }
        // 不论是不是第一次出现都计数
        map[ch]++;
    }

    char FirstAppearingOnce()
    {
        // 从队列头开始遍历
        while (!q.empty())
        {
            // 如果是map中存储的次数等于1，则返回结果
            if (map[q.front()] == 1)
                return q.front();
            // 如果次数不为1，则pop出去
            else
                q.pop();
        }

        return '#';
    }

    char FirstAppearingOnce()
    {
    }
};

int main()
{
    string str;
    cin >> str;
    Solution s;
    cout << s.StrToInt(str) << endl;
    return 0;
}