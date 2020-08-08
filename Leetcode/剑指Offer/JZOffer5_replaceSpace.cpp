#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string replaceSpace(string s)
    {
        string res = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != ' ')
                res += s[i];
            else
                res += "%20";
        }
        return res;
    }
};

int main()
{
    string s;
    getline(cin, s);  //!!!!!!!!!!!!!
    Solution Sol;
    cout << Sol.replaceSpace(s) << endl;
    return 0;
}