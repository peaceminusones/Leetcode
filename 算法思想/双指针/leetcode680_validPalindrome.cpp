#include <iostream>
#include <string>
using namespace std;

class Soltuion
{
public:
    bool validPalindrome(string s)
    {
        if (s.empty())
            return false;

        int i = 0, j = s.size() - 1;
        while (i <= j)
        {
            if (s[i] != s[j])
                return isPalindrome(s, i, j - 1) || isPalindrome(s, i + 1, j);
            i++;
            j--;
        }
        return true;
    }

    bool isPalindrome(string s, int i, int j)
    {
        while (i <= j)
        {
            if (s[i++] != s[j--])
                return false;
        }
        return true;
    }
};

int main()
{
    string s;
    cin >> s;

    Soltuion sol;
    bool res = sol.validPalindrome(s);
    cout << res << endl;
    return 0;
}