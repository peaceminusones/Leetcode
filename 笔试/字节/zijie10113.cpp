#include <bits/stdc++.h>
using namespace std;

int rectCover(int number)
{
    if (number == 0)
        return 0;
    if (number == 1 || number == 2)
        return number;
    return rectCover(number - 1) + rectCover(number - 2);
}

int numberofmethod(int a, int b)
{
    if ((a * b) % 2 == 1)
        return 0;
    if (a < 2 && b < 2)
        return 0;

    vector<vector<int>> dp(a + 1, vector<int>(b + 1));
    if (a >= 2)
        dp[2][0] = 1;
    if (b >= 2)
        dp[0][2] = 1;

    for (int i = 1; i <= b; i++)
    {
        if (i % 2 == 0)
            dp[1][i] = 1;
    }

    for (int i = 1; i <= a; i++)
    {
        if (i % 2 == 0)
            dp[i][1] = 1;
    }

    for (int i = 2; i <= a; i++)
    {
        for (int j = 2; j <= b; j++)
        {
            if ((i * j) % 2 == 1)
                continue;
            if (i <= j)
                dp[i][j] = dp[i][j - 1] + dp[i][j - 2];
            else
                dp[i][j] = dp[i - 1][j] + dp[i - 2][j];
        }
    }

    return dp[a][b];
}

int main()
{
    int a, b;
    cin >> a >> b;

    int res = numberofmethod(a, b);
    cout << res << endl;

    cout << rectCover(b) << endl;

    return 0;
}