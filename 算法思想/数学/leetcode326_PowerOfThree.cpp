#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        if (n == 0)
            return false;
        while (n % 3 == 0)
            n /= 3;
        return n == 1;
    }
};

int main()
{
    int nums;
    cin >> nums;

    Solution s;
    bool res = s.isPowerOfThree(nums);
    cout << res << endl;
    return 0;
}