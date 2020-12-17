#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numSeq(vector<int> nums, int id, int l, int r)
    {
        id %= 2;

        

    }

    void dfs(vector<int> nums)

};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> nums;
    int item;
    for (int i = 0; i < n; i++)
    {
        cin >> item;
        nums.push_back(item);
    }

    vector<int> res;
    Solution s;
    for (int i = 0; i < m; i++)
    {
        int id, left, right;
        int r = s.numSeq(nums, id, left, right);
        res.push_back(r);
    }

    for (auto r : res)
        cout << r << endl;

    return 0;
}