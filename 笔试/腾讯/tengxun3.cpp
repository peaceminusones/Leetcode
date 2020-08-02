#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int minoperat(vector<int> a, vector<int> b)
    {
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> a, b;
    int item;
    for (int i = 0; i < n; i++)
    {
        cin >> item;
        a.push_back(item);
    }
    cin.clear();
    cin.ignore();

    for (int i = 0; i < n; i++)
    {
        cin >> item;
        b.push_back(item);
    }

    Solution s;
    int res = s.minoperat(a, b);
    cout << res << endl;
    return 0;
}