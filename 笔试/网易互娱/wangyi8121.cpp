#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
    bool sevenStar(vector<string> nums)
    {
        unordered_map<char, vector<char>> map;
        for (string str : nums)
        {
            vector<char> tmp = map[str[1]];
            if (find(tmp.begin(), tmp.end(), str[0]) != tmp.end())
                return false;
            map[str[1]].push_back(str[0]);
        }
        return map.size() == 3;
    }
};

int main()
{
    int N;
    cin >> N;
    vector<string> res;
    vector<vector<string>> nums;
    for (int i = 0; i < N; i++)
    {
        vector<string> num;
        string str;
        while (cin >> str)
        {
            num.push_back(str);
            if (cin.get() == '\n')
                break;
        }
        nums.push_back(num);
    }

    Solution s;
    for (int i = 0; i < N; i++)
    {
        int r = s.sevenStar(nums[i]);
        if (r == 1)
            res.push_back("YES");
        else
            res.push_back("NO");
    }

    for (auto r : res)
    {
        cout << r << endl;
    }

    return 0;
}
