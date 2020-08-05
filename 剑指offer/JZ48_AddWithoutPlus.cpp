#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int Add(int num1, int num2)
    {
        return (num1 & num2) == 0 ? num1 | num2 : Add(num1 ^ num2, (num1 & num2) << 1);
    }
};

int main()
{
    int n1, n2;
    cin >> n1 >> n2;
    Solution s;
    cout << s.Add(n1, n2) << endl;
    return 0;
}