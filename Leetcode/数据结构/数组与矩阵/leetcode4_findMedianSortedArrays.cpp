#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();

        // 中位数左边位置
        int left = (n1 + n2 + 1) / 2;
        // 中位数右边位置(如果是奇数，则left==right)
        int right = (n1 + n2 + 2) / 2;

        // 找到左边中位数的值（找到第left的值）
        double medianleft = findKth(nums1, nums2, 0, n1 - 1, 0, n2 - 1, left);
        // 找到右边中位数的值（找到第right的值）
        double medianright = findKth(nums1, nums2, 0, n1 - 1, 0, n2 - 1, right);

        return (medianleft + medianright) / 2;
    }

    double findKth(vector<int> &nums1, vector<int> &nums2, int start1, int end1, int start2, int end2, int k)
    {
        int len1 = end1 - start1 + 1;
        int len2 = end2 - start2 + 1;
        if (len1 > len2)
            return findKth(nums2, nums1, start2, end2, start1, end1, k);

        if (len1 == 0)
            return nums2[start2 + k - 1];

        if (k == 1)
            return min(nums1[start1], nums2[start2]);

        // 分别走k/2步
        int i = start1 + min(len1, k / 2) - 1; // 在长度len和k/2之前取最小值，防止走的超过数组长度
        int j = start2 + min(len2, k / 2) - 1;

        if (nums1[i] > nums2[j])
            return findKth(nums1, nums2, start1, end1, j + 1, end2, k - (j - start2 + 1));
        else
            return findKth(nums1, nums2, i + 1, end1, start2, end2, k - (i - start1 + 1));
    }
};

int main()
{
    // vector<int> arr1, arr2;
    // int item;
    // while (cin >> item)
    // {
    //     arr1.push_back(item);
    //     if (cin.get() == '\n')
    //         break;
    // }

    // while (cin >> item)
    // {
    //     arr2.push_back(item);
    //     if (cin.get() == '\n')
    //         break;
    // }

    vector<int> arr1 = {2};
    vector<int> arr2 = {};

    Solution s;
    cout << s.findMedianSortedArrays(arr1, arr2) << endl;

    return 0;
}