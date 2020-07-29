#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int jumpFloor(int number)
    {
        if (number == 1 || number == 2)
            return number;

        return jumpFloor(number - 1) + jumpFloor(number - 2);
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