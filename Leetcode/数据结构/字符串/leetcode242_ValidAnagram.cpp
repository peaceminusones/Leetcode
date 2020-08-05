#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        // unordered_map<int, int> sn;
        // for (auto s1 : s)
        //     sn[s1]++;
        // unordered_map<int, int> tn;
        // for (auto t1 : t)
        //     tn[t1]++;

        // if (sn.size() != tn.size())
        //     return false;

        // for (auto tmp : sn)
        // {
        //     if (tn[tmp.first] != tmp.second)
        //         return false;
        // }
        // return true;

        unordered_map<int, int> count;
        for (auto s1 : s)
            count[s1]++;
        for (auto t1 : t)
            count[t1]--;

        for (auto c : count)
        {
            if (c.second != 0)
                return false;
        }
        return true;
    }
};

int main()
{
    string s, t;
    cin >> s >> t;

    Solution sol;
    bool res = sol.isAnagram(s, t);
    cout << res << endl;
    return 0;
}