#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int Sum_Solution(int n)
    {
        int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            sum += i;
        }
        return sum;
    }
};

int main()
{
    int n;
    cin >> n;
    Solution s;
    cout << s.Sum_Solution(n) << endl;
    return 0;
}