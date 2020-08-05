#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        string res = "";
        int carry = 0;
        int i = num1.size() - 1, j = num2.size() - 1;
        while (carry == 1 || i >= 0 || j >= 0)
        {
            if (i >= 0 && num1[i] != 0)
                carry += (num1[i] - '0');
            if (j >= 0 && num2[j] != 0)
                carry += (num2[j] - '0');
            res += to_string(carry % 10);
            carry /= 10;
            i--, j--;
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
    string res = s.addStrings(a, b);
    cout << res << endl;
    return 0;
}