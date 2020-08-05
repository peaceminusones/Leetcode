#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int numTimesAllBlue(vector<int> &light)
    {
        int res = 0;
        int m = 0;
        for (int i = 0; i < light.size(); i++)
        {
            m = max(m, light[i]);
            if (m == (i + 1))
                res++;
        }
        return res;
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
    int res = s.numTimesAllBlue(nums);
    cout << res << endl;
    return 0;
}