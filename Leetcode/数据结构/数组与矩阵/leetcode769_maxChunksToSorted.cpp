#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxChunksToSorted(vector<int> &arr)
    {
        int count = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            vector<int> tmp(arr.begin(), arr.begin() + i + 1);
            int maxv = *max_element(tmp.begin(), tmp.end());
            if (maxv == i)
                count++;
        }
        return count;
    }
};

int main()
{
    vector<int> nums;
    int item;
    while (cin >> item)
    {
        nums.push_back(item);
    }

    Solution s;
    int res = s.maxChunksToSorted(nums);
    cout << res << endl;

    return 0;
}
