#include <iostream>
#include <sstream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &T)
    {
        vector<int> res(T.size());
        stack<int> index;
        index.push(0);
        for (int i = 1; i < T.size(); i++)
        {
            while (!index.empty() && T[i] > T[index.top()])
            {
                res[index.top()] = i - index.top();
                index.pop();
            }
            index.push(i);
        }

        return res;
    }
};

int main()
{
    vector<int> temp;
    int item;
    while (cin >> item)
    {
        temp.push_back(item);
        if (cin.get() == '\n')
            break;
    }

    Solution s;
    vector<int> res = s.dailyTemperatures(temp);
    for (auto r : res)
        cout << r << " ";
    cout << endl;

    string str;
    cin >> str;
    istringstream is(str);
    string fields;
    string field;
    while (getline(is, field, '['))
    {
        fields += field;
    }
    cout << fields << endl;
    istringstream iis(fields);
    fields = "";
    while (getline(iis, field, ']'))
    {
        fields += field;
    }
    cout << fields << endl;
    // is >> fields;
    // while (getline(is, field, ']'))
    // {
    //     fields += field;
    // }
    // cout << fields << endl;

    return 0;
}