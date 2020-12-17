#include <bits/stdc++.h>
using namespace std;

struct cmp
{
    bool operator()(pair<string, int> a, pair<string, int> b)
    {
        return a[1] == b[1] ? a[0] > b[0] : a[1] < b[1];
    }
};

vector<int> rankSortByx(vector<vector<int>> submits, int m)
{
    unordered_map<string, int> map;
    for (int i = 0; i < submits.size(); i++)
    {
        string id = to_string(submits[i][0]);
        map[id] += submits[i][1];
    }

    priority_queue<pair<string, int>, vector<pair<string, int>>, cmp> pq;

    for (int i = 0; i < submits.size(); i++)
    {
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> submits;
    int x, y;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        submits.push_back({x, y});
    }

    vector<int> res = rankSortByx(submits, m);

    return 0;
}