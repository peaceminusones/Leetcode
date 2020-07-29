#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int Fibonacci(int n)
    {
        if (n == 0 || n == 1)
            return n;

        return Fibonacci(n - 1) + Fibonacci(n - 2);
    }

    int Fibonacci_1(int n)
    {
        if (n == 0 || n == 1)
            return n;
        int a = 0, b = 1;
        int i = 2;
        int res;
        while (i <= n)
        {
            res = a + b;
            a = b;
            b = res;
            i++;
        }

        return res;
    }
};

int main()
{
    int n;
    cin >> n;
    Solution s;
    cout << s.Fibonacci(n) << endl;
    cout << s.Fibonacci_1(n) << endl;
    return 0;
}