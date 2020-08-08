#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <math.h>
using namespace std;

class Solution
{
public:
    string addtime(int seconds)
    {
        int hours = seconds / 3600;
        int minu = seconds / 60;
        int secod = seconds % 60;

        string h, m, s;
        if (hours + 8 >= 24)
        {
            hours /= 24;
        }
        if (hours + 8 >= 10)
        {
            h = to_string(8 + hours);
        }
        else if (hours + 8 < 10)
        {
            h = "0" + to_string(8 + hours);
        }

        if (minu == 0)
            m = "00";
        else if (minu < 10)
            m = "0" + to_string(minu);
        else
            m = to_string(minu);

        if (secod == 0)
            s = "00";
        else if (secod < 10)
            s = "0" + to_string(secod);
        else
            s = to_string(secod);

        string tail = "am";
        if (hours >= 12)
            tail = "pm";
        return (h + ":" + m + ":" + s + " " + tail);
    }

    string closetime(int n, vector<int> a, vector<int> b)
    {

        vector<int> dp(n);
        dp[0] = 0;
        dp[1] = a[0];
        for (int i = 2; i <= n; i++)
        {
            dp[i] = min(dp[i - 1] + a[i - 1], dp[i - 2] + b[i - 2]);
        }

        return addtime(dp[n]);
    }
};

int main()
{
    int T;
    cin >> T;
    vector<vector<int>> A;
    vector<vector<int>> B;
    Solution s;
    for (int i = 0; i < T; i++)
    {
        int n;
        cin >> n;

        vector<int> a;
        int item;
        for (int j = 0; j < n; j++)
        {
            cin >> item;
            a.push_back(item);
        }

        A.push_back(a);

        vector<int> b;
        for (int j = 0; j < n - 1; j++)
        {
            cin >> item;
            b.push_back(item);
        }
        B.push_back(b);
    }

    vector<string> res;
    for (int i = 0; i < A.size(); i++)
    {
        string time;
        
        if (A[i].size() > 1)
            time = s.closetime(A[i].size(), A[i], B[i]);
        else
            time = s.addtime(A[i][0]);

        res.push_back(time);
    }

    for (auto r : res)
        cout << r << endl;
    return 0;
}