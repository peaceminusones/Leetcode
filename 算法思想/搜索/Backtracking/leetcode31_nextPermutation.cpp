#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Soltuion
{
public:
    void nextPermutation(vector<int> &nums)
    {
        if (nums.size() <= 1)
            return;
        int i = nums.size() - 2, j = nums.size() - 1, k = nums.size() - 1;
        while (i >= 0 && nums[i] >= nums[j])
            i--, j--;

        if (i >= 0)
        {
            while (k > i && nums[i] >= nums[k])
                k--;
            swap(nums[i], nums[k]);
        }

        for (int i = j, j = nums.size() - 1; i < j; i++, j--)
        {
            swap(nums[i], nums[j]);
        }
    }

    void prePermutation(vector<int> &nums)
    {
        nextPermutation(nums);
        return reverse(nums.begin(), nums.end());
    }
};

int main()
{
    vector<int> nums;
    int item;
    while (cin >> item)
    {
        nums.push_back(item);
        if (cin.get() == '\n')
            break;
    }

    Soltuion s;
    s.nextPermutation(nums);
    for (auto n : nums)
        cout << n;
    cout << endl;
    return 0;
}