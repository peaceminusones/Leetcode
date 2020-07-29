#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    // permutation!!!!!!!!!!!!!!!!!!!!!
    string maxvalue(int n)
    {
        string num = to_string(n);

        vector<bool> visited(num.size());
        string cur = "";
        int res = 0;
        backtrack(num, visited, res, cur);

        return to_string(res);
    }

    void backtrack(string &num, vector<bool> &visited, int &res, string &cur)
    {
        if (cur.size() == num.size())
        {
            if (stoi(cur) < stoi(num))
                res = max(res, stoi(cur));
        }

        for (int i = 0; i < num.size(); i++)
        {
            if (visited[i] == 0)
            {
                visited[i] = 1;
                cur.push_back(num[i]);
                backtrack(num, visited, res, cur);
                cur.pop_back();
                visited[i] = 0;
            }
        }
    }

    // combination !!!!!!!!!!!!!!!!!!!!!!!!!!!!
    vector<vector<int>> combination(int n, int k)
    {
        vector<int> nums;
        while (n)
        {
            nums.insert(nums.begin(), n % 10);
            n /= 10;
        }

        vector<vector<int>> res;
        vector<int> cur;
        backtrack_combi(nums, res, cur, 0, k);
        return res;
    }

    void backtrack_combi(vector<int> &nums, vector<vector<int>> &res, vector<int> &cur, int begin, int k)
    {
        if (cur.size() == k)
            res.push_back(cur);

        for (int i = begin; i < nums.size(); i++)
        {
            cur.push_back(nums[i]);
            backtrack_combi(nums, res, cur, i + 1, k);
            cur.pop_back();
        }
    }
};

int main()
{
    int n, k;
    cin >> n >> k;
    Solution s;
    string res = s.maxvalue(n);
    cout << res << endl;

    vector<vector<int>> res2 = s.combination(n, k);
    for (auto ve : res2)
    {
        for (auto v : ve)
        {
            cout << v;
        }
        cout << endl;
    }
    return 0;
}