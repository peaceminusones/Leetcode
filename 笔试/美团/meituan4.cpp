#include <iostream>
#include <vector>
#include <string>
#include <numeric>
using namespace std;

int sum_string(string s, int k)
{
    if (s.length() < 2 * k + 1)
        return 0;

    int len = s.length();
    vector<vector<int>> f(len, vector<int>(len, 0));
    for (int i = 0; i < len - 2 * k - 1; i++)
    {
        for (int j = i + 2 * k; j < len; j++)
        {
            string s1 = s.substr(i, k);
            string s2 = s.substr(j - k, k);
            if (s1 == s2 && j - k - (i + k) != 0)
            {
                cout << s1 << " " << s2 << endl;
                cout << s.substr(i, j - i);
                f[i][j] = 1;
            }
        }
    }
    int sum = 0;
    for (int i = 0; i < f.size(); i++)
        for (int j = 0; j < f[0].size(); j++)
            sum += f[i][j];
    return sum;
}

int main()
{
    string s;
    cin >> s;
    int k;
    cin >> k;
    int res = sum_string(s, k);
    cout << res << endl;
    return 0;
}