#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = m - 1;
        int j = n - 1;
        int p = m + n - 1;
        while (i >= 0 && j >= 0)
        {
            nums1[p--] = nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
        }
        while (j >= 0)
        {
            nums1[p--] = nums2[j--];
        }
    }
};

int main()
{
    int m, n;
    cin >> m >> n;
    vector<int> num1;
    vector<int> num2;

    int item;
    for (int i = 0; i < m + n; i++)
    {
        cin >> item;
        num1.push_back(item);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> item;
        num2.push_back(item);
    }

    Solution s;
    s.merge(num1, m, num2, n);
    for (int i = 0; i < num1.size(); i++)
        cout << num1[i] << " ";

    return 0;
}