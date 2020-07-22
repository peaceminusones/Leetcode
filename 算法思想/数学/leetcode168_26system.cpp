#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    // 麻烦的在于没有0！！26应该对应Z，但是由于对26取余为0，就会变成A
    string convertToTitle(int n)
    {
        string res = "";
        while (n)
        {
            res = (char)((n - 1) % 26 + 'A') + res;
            n = (n - 1) / 26;
        }
        return res;
    }
};

int main()
{
    int n;
    cin >> n;

    Solution s;
    string res = s.convertToTitle(n);
    cout << res << endl;

    return 0;
}