#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        if (n <= 0)
            return 0;
        int sum = 0;
        int i = 1; //1：表示个位，10：表示十位，100：表示百位
        while (n / i != 0)
        {
            int pre = n / 10;
            int cur = min(max(n % (i * 10) - i + 1, 0), i);
            sum += pre + cur;
            i *= 10;
        }
        return sum;
    }
};

int main()
{
    return 0;
}