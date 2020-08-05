#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> countBits(int num)
    {
        vector<int> count;
        count.push_back(0);
        for (int n = 1; n <= num; n++)
        {
            if ((n & (n - 1)) == 0)
            {
                count.push_back(1);
                continue;
            }

            int i = (1 << 30);
            while ((i & n) == 0)
                i >>= 1;

            count.push_back(count[i] + count[(i ^ n)]);
        }

        return count;
    }
};

int main()
{
    int num;
    cin >> num;

    Solution s;
    vector<int> res = s.countBits(num);
    for (auto r : res)
        cout << r << " ";
    return 0;
}