#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution
{
public:
    int jumpFloor(int number)
    {
        return pow(2, number - 1);
    }
};

int main()
{
    int n;
    cin >> n;
    Solution s;
    cout << s.jumpFloor(n) << endl;

    return 0;
}