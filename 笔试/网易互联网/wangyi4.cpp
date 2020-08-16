#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int admit(int n, vector<vector<int>> prof)
    {
        vector<vector<int>> adjacency(n + 1, vector<int>(n + 1));
        for (int i = 0; i < prof.size(); i++)
            adjacency[prof[i][0]][prof[i][1]] = 1;

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
            }
        }
    }

    void Cycle(vector<int> trace, vector<vector<int>> adjacency, int i, int j)
    {
        
    }
};

int main()
{
    int n, m;
    vector<vector<int>> prof;
    for (int i = 0; i < m; i++)
    {
        int item1, item2;
        cin >> item1 >> item2;
        vector<int> p;
        p.push_back(item1);
        p.push_back(item2);
        prof.push_back(p);
    }

    Solution s;
    int res = s.admit(n, prof);
    return 0;
}