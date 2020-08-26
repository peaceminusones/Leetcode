#include <bits/stdc++.h>
using namespace std;

void insertSort(vector<int> &arr)
{
    for (int j = 1; j < arr.size(); j++)
    {
        int val = arr[j];
        int i = j - 1;
        while (i >= 0 && arr[i] > val)
        {
            arr[i + 1] = arr[i];
            i--;
        }
        arr[i + 1] = val;
    }
}

int main()
{
    vector<int> arr;
    int item;
    while (cin >> item)
    {
        arr.push_back(item);
        if (cin.get() == '\n')
            break;
    }

    insertSort(arr);
    for (auto a : arr)
        cout << a << " ";
    return 0;
}