#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int firstBadVersion(int n)
    {
        int l = 1, r = n;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (isBadVersion(mid))
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }

    bool isBadVersion(int version)
    {
        vector<int> a = {false, false, false, true, true};
        return a[version - 1];
    }
};

int main()
{
    int n;
    cin >> n;
    Solution s;
    int res = s.firstBadVersion(n);
    cout << res << endl;
    return 0;
}