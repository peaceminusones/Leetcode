#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int NumberOf1(int n)
    {
        int count = 0;
        unsigned int num = unsigned(n);
        while (num)
        {
            if ((num & 1) == 1)
                count++;
            num >>= 1;
        }
        return count;
    }
};

int main()
{
    int n;
    cin >> n;
    Solution s;
    int res = s.NumberOf1(n);
    cout << res << endl;

    return 0;
}