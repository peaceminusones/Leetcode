#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        string res = "";
        int carry = 0;
        int i = a.size() - 1, j = b.size() - 1;
        while (carry == 1 || i >= 0 || j >= 0)
        {
            if (i >= 0 && a[i--] == '1')
                carry++;
            if (j >= 0 && b[j--] == '1')
                carry++;

            res += to_string(carry % 2);
            carry /= 2;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main()
{
    string a, b;
    cin >> a >> b;
    Solution s;
    string res = s.addBinary(a, b);
    cout << res << endl;
    return 0;
}