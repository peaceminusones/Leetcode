#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Solution
{
public:
    // 二分法找到这个数的左界或者右界，然后++，或者--
    int GetNumberOfK(vector<int> data, int k)
    {
        if (data.empty())
            return 0;
        if (k < data[0] || k > data[data.size() - 1])
            return 0;
        int pos1 = binarySearch_l(data, k);
        int pos2 = binarySearch_r(data, k);

        return pos2 - pos1 + 1;
    }

    // 二分法找左界
    int binarySearch_l(vector<int> data, int k)
    {
        int l = 0, r = data.size() - 1;
        while (l <= r)
        {
            int m = l + ((r - l) >> 1);
            if (k <= data[m]) // 目标在左边
                r = m - 1;
            else
                l = m + 1;
        }
        return l;
    }

    // 二分法找右界
    int binarySearch_r(vector<int> data, int k)
    {
        int l = 0, r = data.size() - 1;
        while (l <= r)
        {
            int m = l + ((r - l) >> 1);
            if (k < data[m]) // 目标在左边
                r = m - 1;
            else
                l = m + 1;
        }
        return r;
    }
};

int main()
{
    vector<int> data;
    int item;
    while (cin >> item)
    {
        data.push_back(item);
        if (cin.get() == '\n')
            break;
    }
    int k;
    cin >> k;

    Solution s;
    int res = s.GetNumberOfK(data, k);
    cout << res << endl;
    return 0;
}