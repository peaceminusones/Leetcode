#include <iostream>
#include <string>
#include <vector>
#include <bitset>
using namespace std;

class Solution
{
public:
    string toHex(int num)
    {
        if (num == 0)
            return to_string(0);

        unsigned int n = num;
        string res = "";
        vector<char> map = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
        while (n)
        {
            res = map[n & 0b1111] + res;
            n >>= 4;
        }

        return res;
    }
};

int main()
{
    unsigned int n = -1;
    cout << bitset<sizeof(n) * 8>(n) << endl;
    int num;
    cin >> num;
    Solution s;
    string res = s.toHex(num);
    cout << res << endl;
    return 0;
}