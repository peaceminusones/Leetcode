#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution
{
public:
    // string reverseVowels(string s)
    // {
    //     map<char, int> vowels = {{'a', 1}, {'e', 2}, {'i', 3}, {'o', 4}, {'u', 5}, {'A', 6}, {'E', 7}, {'I', 8}, {'O', 9}, {'U', 10}};
    //     map<char, int>::iterator it1;
    //     map<char, int>::iterator it2;

    //     if (s.empty())
    //         return s;

    //     int i = 0, j = s.size() - 1;
    //     while (i <= j)
    //     {
    //         it1 = vowels.find(s[i]);
    //         it2 = vowels.find(s[j]);
    //         if (it1 != vowels.end() && it2 != vowels.end())
    //         {
    //             char temp = s[i];
    //             s[i] = s[j];
    //             s[j] = temp;
    //             i++, j--;
    //         }
    //         else if (it1 == vowels.end() && it2 != vowels.end())
    //             i++;
    //         else if (it1 != vowels.end() && it2 == vowels.end())
    //             j--;
    //         else
    //         {
    //             i++;
    //             j--;
    //         }
    //     }
    //     return s;
    // }

    string reverseVowels(string s)
    {
        if (s.empty())
            return s;

        int i = 0, j = s.size() - 1;
        while (i <= j)
        {
            if (!isVowels(s[i]))
            {
                i++;
                continue;
            }
            if (!isVowels(s[j]))
            {
                j--;
                continue;
            }
            swap(s[i++], s[j--]);
        }

        return s;
    }

    bool isVowels(char c)
    {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            return true;
        return false;
    }
};

int main()
{
    string s;
    cin >> s;

    Solution sol;
    string res = sol.reverseVowels(s);
    cout << res << endl;
    return 0;
}