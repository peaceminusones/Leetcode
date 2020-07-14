#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void sumS(vector<vector<int>> &res, vector<int> &temp, int n, int s, int now_sum)
    {
        if (now_sum == s)
        {
            if (temp.size() < n)
            {
                res.push_back(temp);
            }
        }
    }

    int magicnumber(int n, int s, int x)
    {
        vector<vector<int>> res;
        vector<int> temp;
        sumS(res, temp, n, s, 0);
    }
};

int main()
{
    int n, s, x;
    cin >> n >> s >> x;

    Solution sol;
    int res = sol.magicnumber(n, s, x);
    cout << res << endl;
    return 0;
}