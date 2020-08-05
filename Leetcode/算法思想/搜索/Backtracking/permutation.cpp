// #include <iostream>
// #include <vector>
// using namespace std;

// class permutation
// {
//     vector<vector<int>> res;

// public:
//     vector<vector<int>> permutate(vector<int> &digit)
//     {
//         vector<int> visit(digit.size());
//         vector<int> track;
//         backtrack(digit, visit, track); // 选择列表，路径
//         return res;
//     }

//     void backtrack(vector<int> &digit, vector<int> &visit, vector<int> &track)
//     {
//         if (track.size() == digit.size())
//         {
//             res.push_back(track);
//             return;
//         }

//         for (int i = 0; i < digit.size(); i++)
//         {
//             if (visit[i] == 1)
//                 continue;
//             visit[i] = 1;
//             track.push_back(digit[i]);
//             backtrack(digit, visit, track);
//             track.pop_back();
//             visit[i] = 0;
//         }
//     }
// };

// int main()
// {
//     vector<int> digit;
//     int item;
//     while (cin >> item)
//     {
//         digit.push_back(item);
//     }
//     cin.clear();
//     cin.ignore();

//     permutation p;
//     vector<vector<int>> res = p.permutate(digit);
//     for (int i = 0; i < res.size(); i++)
//     {
//         for (int j = 0; j < res[0].size(); j++)
//         {
//             cout << res[i][j];
//         }
//         cout << endl;
//     }
//     return 0;
// }

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> permutation(vector<int> &nums)
    {
        vector<vector<int>> res;
        if (nums.empty())
            return res;

        vector<int> cur;
        vector<int> visited(nums.size());
        backtrack(nums, cur, visited, res);
        return res;
    }

    void backtrack(vector<int> &nums, vector<int> &cur, vector<int> &visited, vector<vector<int>> &res)
    {
        if (cur.size() == nums.size())
        {
            res.push_back(cur);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (visited[i] == 0)
            {
                visited[i] = 1;
                cur.push_back(nums[i]);
                backtrack(nums, cur, visited, res);
                cur.pop_back();
                visited[i] = 0;
            }
        }
    }
};

int main()
{
    vector<int> nums;
    int item;
    while (cin >> item)
    {
        nums.push_back(item);
    }
    cin.clear();
    cin.ignore();

    Solution s;
    vector<vector<int>> res = s.permutation(nums);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[0].size(); j++)
        {
            cout << res[i][j];
        }
        cout << endl;
    }
    return 0;
}