#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int l, int m, int r)
{
    vector<int> res;

    int i = l;
    int j = m + 1;

    while (i <= m && j <= r)
    {
        if (arr[i] < arr[j])
        {
            res.push_back(arr[i++]);
        }
        else
        {
            res.push_back(arr[j++]);
        }
    }

    while (i <= m)
        res.push_back(arr[i++]);
    while (j <= r)
        res.push_back(arr[j++]);

    for (int k = 0; k < res.size(); k++)
        arr[k + l] = res[k];
}

void merge_sort(vector<int> &arr, int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main()
{
    vector<int> arr;
    int item;
    while (cin >> item)
    {
        arr.push_back(item);
    }
    cin.clear();
    cin.ignore();

    merge_sort(arr, 0, arr.size() - 1);

    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";

    return 0;
}