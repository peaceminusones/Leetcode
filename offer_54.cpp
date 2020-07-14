#include <iostream>
#include <string>
#include <string.h>
#include <queue>
using namespace std;

class Solution
{
    int cnt[128]; // ascii码表大小是128
    queue<char> q;

public:
    Solution()
    {
        memset(cnt, 0, sizeof(cnt)); // 把cnt都初始化为0
    }

    void Insert(char ch)
    {
        cnt[ch - '\0']++;        // 把符号减去'\0'成为在cnt中的位置，且把当前位置加1
        if (cnt[ch - '\0'] == 1) // 如果当前位置为1，则表示第一次出现，qush到队列q中
            q.push(ch);
    }

    char FirstAppearingOnce()
    {
        // 按照顺序遍历队列q，且在cnt中查找，如果cnt的值为1，则是我们所找的
        while (!q.empty() && cnt[q.front() - '\0'] > 1)
        {
            q.pop();
        }

        if (q.empty())
            return '#';

        return q.front();
    }
};

int main()
{
    string str;
    cin >> str;

    Solution s;
    for (int i = 0; i < str.length(); i++)
        s.Insert(str[i]);

    char res = s.FirstAppearingOnce();
    cout << res << endl;

    return 0;
}