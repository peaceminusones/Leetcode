#include <iostream>
#include <vector>
#include <set>
using namespace std;

int ExeNumber(vector<vector<int>> records)
{
    vector<int> res;
    int max = 0;
    int index;
    for (int j = 0; j < records[0].size(); j++)
    {
        for (int i = 0; i < records.size(); i++)
        {
            if (records[i][j] > max)
            {
                max = records[i][j];
                index = i;
            }
        }
        res.push_back(index);
        for (int i = 0; i < records.size(); i++)
        {
            if (records[i][j] == max)
            {
                res.push_back(i);
            }
        }
        max = 0;
    }
    
    set<int> s(res.begin(), res.end());

    return s.size();
}

int main()
{
    int n, m;
    cin >> n >> m;
    if (n == 0 || m == 0)
        return 0;
    vector<vector<int>> records;
    for (int i = 0; i < n; i++)
    {
        vector<int> record;
        int item;
        for (int j = 0; j < m; j++)
        {
            cin >> item;
            record.push_back(item);
        }
        records.push_back(record);
    }

    int res = ExeNumber(records);
    cout << res << endl;
    return 0;
}