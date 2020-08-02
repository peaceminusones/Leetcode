#include <iostream>
#include <vector>
using namespace std;

void mindistance(int n, int m, vector<vector<int>> arr)
{
    vector<int> shel;
    int k = 0;
    while (k++ <= n)
        shel.push_back(1);

    for (int i = 0; i < m; i++)
    {
        if (arr[i][0] == 1 && shel[arr[i][1]] <= n)
        {
            shel[arr[i][1]] = 0;
        }
        else if (arr[i][0] == 2 && shel[arr[i][1]] <= n)
        {
            if (shel[arr[i][1]] == 1)
                cout << arr[i][1] << endl;
            else if (arr[i][1] < n && shel[arr[i][1] + 1] == 1)
                cout << arr[i][1] + 1 << endl;
            else
                cout << -1 << endl;
        }
        else
            cout << -1 << endl;

        // for (k = 0; k < shel.size(); k++)
        //     cout << shel[k] << " ";
        // cout << endl;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> vs;
    int op, pos;
    for (int i = 0; i < m; i++)
    {
        int item;
        vector<int> v;
        for (int j = 0; j < 2; j++)
        {
            cin >> item;
            v.push_back(item);
        }
        vs.push_back(v);
    }
    mindistance(n, m, vs);

    return 0;
}