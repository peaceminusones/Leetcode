#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> reverseNumber(vector<int> &num)
    {
        // swap(num[0], num[1]);
        num[0] ^= num[1];
        num[1] ^= num[0];
        num[0] ^= num[1];
        return num;
    }
};

int main()
{
    vector<int> num;
    int item1, item2;
    cin >> item1 >> item2;
    num.push_back(item1);
    num.push_back(item2);

    Solution s;
    vector<int> res = s.reverseNumber(num);
    for (auto r : res)
        cout << r << " ";
    return 0;
}