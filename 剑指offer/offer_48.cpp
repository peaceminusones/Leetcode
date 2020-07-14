#include <iostream>
using namespace std;

class Solution
{
public:
    int Add(int num1, int num2)
    {
        while (num2 != 0) // 如果进位值不为0
        {
            int temp = num1 ^ num2;    // 相加各位，不算进位
            num2 = (num1 & num2) << 1; // num2值变成表示计算进位值
            num1 = temp;               // num1值变成表示不算进位的和
        }
        return num1;
    }
};

int main()
{
    int n1, n2;
    cin >> n1 >> n2;
    Solution s;
    int res = s.Add(n1, n2);
    cout << res << endl;
    return 0;
}