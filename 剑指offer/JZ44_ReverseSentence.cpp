#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

class Solution
{
public:
    string ReverseSentence(string str)
    {
        reverse(str.begin(), str.end());

        int i = 0, j = 0;
        while (j < str.size())
        {
            while (str[i] == ' ')
            {
                i++;
            }
            while (j < str.size() && str[j] != ' ')
            {
                j++;
            }

            if (j - i > 1)
                reverse(str.begin() + i, str.begin() + j);

            i = j, j++;
        }
        return str;
    }
};

int main()
{
    string str;
    getline(cin, str);

    Solution s;
    string res = s.ReverseSentence(str);
    cout << res << endl;
    return 0;
}