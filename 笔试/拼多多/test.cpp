#include <iostream>
#include <vector>
using namespace std;

int Fibonaci(int n)
{
    int dp0 = 1;
    int dp1 = 1;
    int dp2;
    for (int i = 2; i < n; i++)
    {
        dp2 = dp1 + dp0;
        dp0 = dp1;
        dp1 = dp2;
    }
    return dp2;
}

int main()
{
    int n;
    cin >> n;
    int res = Fibonaci(n);
    cout << res << endl;
    return 0;
}