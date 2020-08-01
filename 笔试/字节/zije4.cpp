#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isCircleString(string &str)
    {
        for (int i = 0; i < str.size() - 1; i++)
        {
            string str1 = str.substr(0, i - 0);
            string str2 = str.substr(i);
            string newstr = str2 + str1;
            int l = 0, r = newstr.size() - 1;
            while (l < r)
            {
                if (newstr[l] == newstr[r])
                {
                    l++, r--;
                }
                else
                    break;
            }

            if (l >= r)
                return true;
        }

        return false;
    }
};

int main()
{
    string str;
    cin >> str;
    Solution s;
    bool res = s.isCircleString(str);
    cout << res << endl;
    return 0;
}