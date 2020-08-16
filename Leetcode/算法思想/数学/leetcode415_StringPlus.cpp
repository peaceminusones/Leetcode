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
        int sum = 0;
        int i = num1.size() - 1, j = num2.size() - 1;
        while (sum == 1 || i >= 0 || j >= 0)
        {
            if (i >= 0)
                sum += num1[i] - '0';
            if (j >= 0)
                sum += num2[j] - '0';

            res += to_string(sum % 10);
            sum /= 10;
            i--, j--;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main()
{
    return 0;
}