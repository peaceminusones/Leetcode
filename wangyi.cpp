#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int getSurface(vector<vector<int>> sq)
    {
        vector<vector<int>> s1;
        vector<vector<int>> s2;
        int n = 0, m = 0;
        int flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0, flag5 = 0, flag6 = 0;

        for (int i = 0; i < sq.size(); i++)
        {
            vector<int> temp = sq[i];
            temp[0] += 1;
            vector<vector<int>>::iterator it = find(sq.begin(), sq.end(), temp);
            vector<vector<int>>::iterator st = find(s1.begin(), s1.end(), temp);
            if (it != sq.end())
            {
                n++;
                flag1 = 1;
            }
            if (flag1 && st == s1.end())
                s1.push_back(temp);

            temp[0] -= 1;
            temp[1] += 1;
            it = find(sq.begin(), sq.end(), temp);
            st = find(s1.begin(), s1.end(), temp);
            if (it != sq.end())
            {
                n++;
                flag2 = 1;
            }
            if (flag2 && st == s1.end())
                s1.push_back(temp);

            temp[1] -= 1;
            temp[2] += 1;
            it = find(sq.begin(), sq.end(), temp);
            st = find(s1.begin(), s1.end(), temp);
            if (it != sq.end())
            {
                n++;
                flag3 = 1;
            }
            if (flag3 && st == s1.end())
                s1.push_back(temp);

            temp[2] -= 1;
            temp[0] -= 1;
            it = find(sq.begin(), sq.end(), temp);
            st = find(s1.begin(), s1.end(), temp);
            if (it != sq.end())
            {
                n++;
                flag4 = 1;
            }
            if (flag4 && st == s1.end())
                s1.push_back(temp);

            temp[0] += 1;
            temp[1] -= 1;
            it = find(sq.begin(), sq.end(), temp);
            st = find(s1.begin(), s1.end(), temp);
            if (it != sq.end())
            {
                n++;
                flag5 = 1;
            }
            if (flag5 && st == s1.end())
                s1.push_back(temp);

            temp[1] += 1;
            temp[2] -= 1;
            it = find(sq.begin(), sq.end(), temp);
            st = find(s1.begin(), s1.end(), temp);
            if (it != sq.end())
            {
                n++;
                flag6 = 1;
            }
            if (flag6 && st == s1.end())
                s1.push_back(temp);

            temp[2] += 1;
            st = find(s1.begin(), s1.end(), temp);
            if (!flag1 && !flag2 && !flag3 && !flag4 && !flag5 && !flag6)
                s2.push_back(temp);
            else if (st == s1.end())
                s1.push_back(temp);

            flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0, flag5 = 0, flag6 = 0;
        }

        // cout << n << endl;
        // cout << s1.size() << endl;
        // cout << s2.size() << endl;

        return s1.size() * 6 - (n / 2) * 2 + s2.size() * 6;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> sq;
    int item;
    for (int i = 0; i < n; i++)
    {
        vector<int> s;
        for (int j = 0; j < 3; j++)
        {
            cin >> item;
            s.push_back(item);
        }
        sq.push_back(s);
    }

    // for (int i = 0; i < sq.size(); i++)
    // {
    //     for (int j = 0; j < sq[0].size(); j++)
    //         cout << sq[i][j] << " ";
    //     cout << endl;
    // }
    Solution s;
    int res = s.getSurface(sq);
    cout << res << endl;

    return 0;
}
