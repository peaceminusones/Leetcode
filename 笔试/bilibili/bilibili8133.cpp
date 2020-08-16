#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int GetCoinCount(int N)
    {
        int cash = 1024 - N;
        int coin64 = cash / 64;
        int coin16 = cash % 64 / 16;
        int coin4 = cash % 64 % 16 / 4;
        int coin1 = cash % 64 % 16 % 4;
        return coin64 + coin16 + coin4 + coin1;
    }
};

int main()
{
    int N;
    cin >> N;
    Solution s;
    cout << s.GetCoinCount(N) << endl;
    return 0;
}