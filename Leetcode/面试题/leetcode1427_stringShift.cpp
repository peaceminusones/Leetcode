#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string stringShift(string s, vector<vector<int>> &shift)
    {
        for (int i = 0; i < shift.size(); i++)
        {
            int len = shift[i][1] % s.size();
            string tmp;
            if (shift[i][0] == 1) // 向右移动
            {
                tmp = s.substr(s.size() - len, len);
                s = tmp + s.substr(0, s.size() - len);
            }
            else // 向左移动
            {
                tmp = s.substr(0, len);
                s = s.substr(len, s.size() - len) + tmp;
            }
        }
        return s;
    }

    vector<int> numShift(vector<int> nums, int k)
    {
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + nums.size() - k);
        reverse(nums.begin() + nums.size() - k, nums.end());
        return nums;
    }
};

int main()
{
    // string s;
    // cin >> s;
    // vector<vector<int>> shift;
    // vector<int> sh;
    // int item;
    // while (cin >> item)
    // {
    //     sh.push_back(item);
    //     if (cin.get() == '\n')
    //     {
    //         shift.push_back(sh);
    //         sh.clear();
    //     }
    //     if (cin.peek() == '\n')
    //     {
    //         shift.push_back(sh);
    //     }
    // }

    // Solution sol;
    // cout << sol.stringShift(s, shift) << endl;

    vector<int> nums;
    int item;
    while (cin >> item)
    {
        nums.push_back(item);
        if (cin.get() == '\n')
            break;
    }
    int k;
    cin >> k;

    Solution s;
    vector<int> res = s.numShift(nums, k);
    for (auto r : res)
        cout << r << " ";

    return 0;
}