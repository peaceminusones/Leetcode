#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int a;
    int b;
    char c;

public:
    int search(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (target == nums[mid])
                return mid;
            if (target == nums[l])
                return l;
            if (target == nums[r])
                return r;

            if (nums[l] < nums[mid])
            {
                if (target < nums[mid] && target > nums[l])
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            else
            {
                if (target > nums[mid] && target < nums[r])
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }

        return nums[l] == target ? l : -1;
    }
};

void init(int *a)
{
    *a = 4;
}

int main()
{
    // vector<int> nums;
    // int item;
    // while (cin >> item)
    // {
    //     nums.push_back(item);
    //     if (cin.get() == '\n')
    //         break;
    // }

    // int target;
    // cin >> target;
    // Solution s;
    // cout << s.search(nums, target) << endl;
    // cout << sizeof(Solution) << endl;
    // cout << sizeof(int) << endl;
    int a = 1;
    init(&a);
    cout << a << endl;
    return 0;
}