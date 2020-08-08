#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<string> encoding(vector<int> &num)
    {
        vector<string> res;
        for (auto n : num)
        {
            if (n == 0)
            {
                res.push_back("0");
            }
            else
            {
                string tmp = encode(n);
                reverse(tmp.begin(), tmp.end());
                res.push_back(tmp);
            }
        }

        for (int i = 0; i < res.size(); i++)
        {
            if (res[i] == "0")
                continue;
            
            int index = 0;
            while (res[i][index] == '0')
                index++;
            res[i] = res[i].substr(index);

            // cout << res[i] << endl;
        }

        return res;
    }

    string encode(int n)
    {
        int num = n;
        string res = "";
        while (num)
        {
            int single = num % 10;
            bitset<4> t(single);
            res.insert(0, t.to_string());
            num = num / 10;
        }
        if (n < 100 && n >= 10)
        {
            bitset<4> t(0);
            res.insert(0, t.to_string());
        }
        if (n < 10)
        {
            bitset<4> t(0);
            res.insert(0, t.to_string());
            res.insert(0, t.to_string());
        }

        return res;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> num;
    int item;
    for (int i = 0; i < n; i++)
    {
        cin >> item;
        num.push_back(item);
    }

    Solution s;
    vector<string> res = s.encoding(num);
    for (auto r : res)
        cout << r << endl;

    return 0;
}