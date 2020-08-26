#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double getMedian(vector<int> &arr)
    {
        if (arr.size() == 1)
            return arr[0];

        int l = 0, r = arr.size() - 1;
        int mid = l + (r - l) / 2;
        int index = quicksort(arr, l, r);

        while (index != mid)
        {
            if (index < mid)
            {
                index = quicksort(arr, index + 1, r);
            }
            else if (index > mid)
            {
                index = quicksort(arr, l, index - 1);
            }
        }

        if (arr.size() % 2 != 0)
            return arr[index];
        else
        {
            return (arr[index] + arr[index + 1]) / 2.0;
        }
    }

    int quicksort(vector<int> &arr, int l, int r)
    {
        int mid = arr[l];
        int i = l, j = r;
        while (i < j)
        {
            while (i < j && arr[j] >= mid)
                j--;
            while (i < j && arr[i] <= mid)
                i++;

            if (i < j)
                swap(arr[i], arr[j]);
        }
        swap(arr[l], arr[i]);
        return i;
    }
};

int main()
{
    vector<int> arr;
    int a;
    while (cin >> a)
    {
        arr.push_back(a);
        if (cin.get() == '\n')
            break;
    }

    Solution s;
    cout << s.getMedian(arr) << endl;

    return 0;
}