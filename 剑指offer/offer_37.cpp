#include <iostream>
#include <vector>
using namespace std;

/*二分查找*/

class Solution
{
public:
    int binary_search(vector<int> data, int k, int l, int r)
    {
        if (l > r)
            return -1;

        int mid = (l + r) / 2;
        // if (data[mid] > k)
        //     return binary_search(data, k, l, mid - 1);
        // else if (data[mid] < k)
        //     return binary_search(data, k, mid + 1, r);
        // else
        //     return mid;

        while (l < r)
        {
            if (data[mid] < k)
                l = mid + 1;
            else if (data[mid] > k)
                r = mid - 1;
            else
                return mid;

            mid = (l + r) / 2;
        }
        return -1;
    }

    int GetNumberOfK(vector<int> data, int k)
    {
        if (data.size() == 0)
            return 0;

        int pos = binary_search(data, k, 0, data.size() - 1);
        cout << pos << " " << data[pos] << endl;
        if (pos == -1)
            return 0;

        int i = pos, j = pos;
        while (data[i] == k || data[j] == k)
        {
            if (data[i] == k)
                i--;
            if (data[j] == k)
                j++;
        }

        // if (i == -1)
        //     i = 0;
        return (j - i - 1);
    }

    // int getFirstPos(vector<int> data, int k)
    // {
    //     int l = 0, r = data.size() - 1;
    //     int mid = (l + r) / 2;

    //     while (l <= r)
    //     {
    //         if (data[mid] < k)
    //             l = mid + 1;
    //         else
    //             r = mid - 1;
    //         mid = (l + r) / 2;
    //     }

    //     return l;
    // }

    // int getLastPos(vector<int> data, int k)
    // {
    //     int l = 0, r = data.size() - 1;
    //     int mid = (l + r) / 2;

    //     while (l <= r)
    //     {
    //         if (data[mid] <= k)
    //             l = mid + 1;
    //         else
    //             r = mid - 1;
    //         mid = (l + r) / 2;
    //     }
    //     return r;
    // }

    // int GetNumberOfK(vector<int> data, int k)
    // {
    //     if (data.size() == 0)
    //         return 0;

    //     int first = getFirstPos(data, k);
    //     int last = getLastPos(data, k);

    //     return last - first + 1;
    // }
};

int main()
{
    int k;
    cin >> k;
    int item;
    vector<int> arr;
    while (cin >> item)
        arr.push_back(item);

    Solution s;
    int res = s.GetNumberOfK(arr, k);
    cout << res << endl;

    return 0;
}