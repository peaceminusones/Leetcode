#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution
{
public:
    int rectCover(int number)
    {
        if (number == 0)
            return 0;
        if (number == 1 || number == 2)
            return number;
        return rectCover(number - 1) + rectCover(number - 2);
    }
};

int main()
{
    int n;
    cin >> n;
    Solution s;
    cout << s.rectCover(n) << endl;

    return 0;
}