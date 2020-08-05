#include <iostream>
#include <vector>
#include <numeric>
#include <list>
using namespace std;

class Solution
{
public:
    int LastRemaining_Solution(int n, int m)
    {
        // 要删除的下标号：(i+m-1)%n
        if (n <= 0)
            return -1;
        if (m == 1)
            return n - 1;
        list<int> lt; // 双向链表
        for (int i = 0; i < n; i++)
            lt.push_back(i);

        int index = 0;
        while (n > 1)
        {
            index = (index + m - 1) % n;
            auto it = lt.begin();
            advance(it, index); // 把迭代器往后移动index位
            lt.erase(it);       // 删除
            n--;                // 人数减一
        }
        return lt.front();
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    Solution s;
    int res = s.LastRemaining_Solution(n, m);
    cout << res << endl;
    return 0;
}