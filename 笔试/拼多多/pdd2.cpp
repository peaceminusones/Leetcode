#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool belongAClass(vector<int> nums1, vector<int> nums2)
    {
        int sum = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                if (nums1[i] == nums2[j] && nums1[5 - i] == nums2[5 - j])
                {
                    sum++;
                    nums1[i] = 7;
                    nums1[5 - i] = 7;
                    nums2[j] = 0;
                    nums2[5 - j] = 0;
                }
            }
        }
        cout << sum << endl;
        return sum == 3;
    }
};

int main()
{
    vector<int> nums1, nums2;
    int item;
    for (int i = 0; i < 6; i++)
    {
        cin >> item;
        nums1.push_back(item);
    }

    for (int i = 0; i < 6; i++)
    {
        cin >> item;
        nums2.push_back(item);
    }

    Solution s;
    cout << s.belongAClass(nums1, nums2);
    return 0;
}