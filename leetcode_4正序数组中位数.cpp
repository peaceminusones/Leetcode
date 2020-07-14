#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
    }
};

int main()
{
    vector<int> nums1;
    vector<int> nums2;

    int item;
    while (cin >> item)
        nums1.push_back(item);
    cin.clear();
    cin.ignore();
    while (cin >> item)
        nums2.push_back(item);

    Solution s;
    double res = s.findMedianSortedArrays(nums1, nums2);
    cout << res << endl;

    return 0;
}