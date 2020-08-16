#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    // 区间长度是固定的，是s1的长度
    bool checkInclusion(string s1, string s2)
    {
        if (s1.size() > s2.size())
            return false;
        int len1 = s1.size(), len2 = s2.size();
        unordered_map<char, int> s1_count, s2_count;
        for (int i = 0; i < len1; i++)
        {
            s1_count[s1[i]]++;
            s2_count[s2[i]]++;
        }

        for (int right = len1; right < len2; right++)
        {
            if (isEqual(s1_count, s2_count))
                return true;
            s2_count[s2[right - len1]]--;
            s2_count[s2[right]]++;
        }

        return isEqual(s1_count, s2_count);
    }

    bool isEqual(unordered_map<char, int> s1, unordered_map<char, int> s2)
    {
        for (auto it = s1.begin(); it != s2.end(); it++)
        {
            if (it->second != s2[it->first])
                return false;
        }
        return true;
    }
};

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    Solution s;
    cout << s.checkInclusion(s1, s2) << endl;
    return 0;
}