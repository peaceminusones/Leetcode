#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void similar(int n, vector<int> arr)
{
    vector<vector<int>> q(n, vector<int>(n, -2));
    for (int i = 0; i < arr.size(); i++)
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[i] & arr[j] != 0)
            {
                q[i][j] = -1;
                q[j][i] = -1;
            }
            else
            {
                q[i][j] = 1;
                q[j][i] = 1;
            }
        }
    for (int i = 0; i < q.size(); i++)
        cout << *max_element(q[i].begin(), q[i].end()) << " ";
}

int main()
{
    int n;
    cin >> n;
    int item;
    vector<int> arr;
    while (cin >> item)
    {
        arr.push_back(item);
    }
    similar(n, arr);
    return 0;
}