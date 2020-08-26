#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int rand12()
    {
        while (true)
        {
            int a = rand7();
            int b = rand7();
            int num = (a - 1) * 7 + b;
            if (num <= 48)
                return num % 12 + 1;
        }
    }

    // 产生1-7的随机数
    int rand7()
    {
        srand((unsigned)time(NULL));
        return rand() % 7 + 1;
    }
};

int main()
{
    Solution s;
    for (int i = 0; i < 12; i++)
        cout << s.rand12() << endl;
    return 0;
}