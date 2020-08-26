#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string multiply(string num1, string num2)
    {
        if (num1 == "0" || num2 == "0")
            return "0";

        string res = "";
        for (int i = num2.size() - 1; i >= 0; i--)
        {
            // 补0
            string cur = "";
            for (int k = 0; k < num2.size() - 1 - i; k++)
            {
                cur += "0";
            }

            int carry = 0; // 进位
            for (int j = num1.size() - 1; j >= 0; j--)
            {
                int multi = (num1[j] - '0') * (num2[i] - '0') + carry;
                cur += to_string(multi % 10);
                carry = multi / 10;
            }
            if (carry)
                cur += to_string(carry);

            reverse(cur.begin(), cur.end());
            res = addstring(res, cur);
        }

        return res;
    }

    string addstring(string &num1, string &num2)
    {
        string res = "";
        int i = num1.size() - 1, j = num2.size() - 1;
        int carry = 0;
        while (carry == 1 || i >= 0 || j >= 0)
        {
            if (i >= 0)
                carry += num1[i] - '0';
            if (j >= 0)
                carry += num2[j] - '0';

            res += to_string(carry % 10);
            carry /= 10;
            i--, j--;
        }
        reverse(res.begin(), res.end());
        return res;
    }

    string factorial(int n)
    {
        string res = "1";
        for (int i = 2; i <= n; i++)
        {
            res = multiply(res, to_string(i));
        }
        return res;
    }
};

int main()
{
    // string s1, s2;
    // cin >> s1 >> s2;

    // Solution s;
    // cout << s.multiply(s1, s2) << endl;

    int n;
    cin >> n;

    Solution s;
    cout << s.factorial(n) << endl;
    return 0;
}