#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;

    vector<vector<int>> matrix;
    int item;
    for (int i = 0; i < m; i++)
    {
        vector<int> m;
        for (int j = 0; j < n; j++)
        {
            cin >> item;
            m.push_back(item);
        }
        matrix.push_back(m);
    }

    int sum = accumulate(matrix.begin(), matrix.end(), 0);

    cout << sum << endl;
    return 0;
}