#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    vector<int> divingBoard(int shorter, int longer, int k)
    {
        if (k == 0)
            return {};

        if (shorter == longer)
            return {k * shorter};

        vector<int> res;
        for (int i = 0; i <= k; i++)
        {
            res.push_back(i * longer + (k - i) * shorter);
        }
        return res;
    }
};

int main()
{
    int a, b, k;
    cin >> a >> b >> k;
    Solution s;
    vector<int> res = s.divingBoard(a, b, k);
    cout << "[";
    for (auto r : res)
        cout << r << ",";
    cout << "]" << endl;

    return 0;
}