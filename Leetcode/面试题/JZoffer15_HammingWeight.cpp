#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        string str = to_string(n);
        bitset<32> a(str);
        return a.count();
    }
};

int main()
{
    uint32_t n;
    cin >> n;
    Solution s;
    cout << s.hammingWeight(n) << endl;
    return 0;
}