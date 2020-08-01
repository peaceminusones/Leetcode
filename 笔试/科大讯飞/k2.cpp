#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &num, int l, int r, vector<vector<int>> &res)
{
    int mid = num[l];
    int i = l, j = r;
    while (i < j)
    {
        while (i < j && num[j] >= mid)
            j--;
        while (i < j && num[i] <= mid)
            i++;

        if (i < j)
            swap(num[i], num[j]);
    }

    swap(num[i], num[l]);
    res.push_back(num);
    return i;
}

void quickSort(vector<int> &num, int l, int r, vector<vector<int>> &res)
{
    if (l < r)
    {
        int m = partition(num, l, r, res);
        quickSort(num, l, m - 1, res);
        quickSort(num, m + 1, r, res);
    }
}

int main()
{
    int k;
    cin >> k;
    int item;
    vector<int> num;
    for (int i = 0; i < k; i++)
    {
        cin >> item;
        num.push_back(item);
    }
    vector<vector<int>> res;
    quickSort(num, 0, num.size() - 1, res);
    for (int i = 0; i < res.size(); i++)
    {
        for (auto n : res[i])
            cout << n << " ";
        cout << endl;
    }

    return 0;
}