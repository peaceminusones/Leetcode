#include <iostream>
#include <vector>
#include <map>
#include <math.h>
using namespace std;

class Solution
{
public:
    int count(int n, vector<int> depth)
    {
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> depth;
    int item;
    for (int i = 0; i < n; i++)
    {
        cin >> item;
        depth.push_back(item);
    }

    Solution s;
    cout << s.count(n, depth) << endl;
    return 0;
}