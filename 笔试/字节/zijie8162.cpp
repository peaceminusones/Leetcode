#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    int count = 0;
    void remove(string str)
    {
        if (str.empty())
            return;

        int index = str.find("0010");
        if (index == -1)
            return;
        if (index + 4 + 1 < str.size() && str[index + 4 + 1] == '1')
        {
            str.erase(str.begin() + index);
            count++;
        }
        else
        {
            str.erase(str.begin() + index + 2);
            count++;
        }
        cout << str << endl;
        remove(str);
    }
};

int main()
{
    int n;
    cin >> n;
    vector<string> code;
    string item;
    for (int i = 0; i < n; i++)
    {
        cin >> item;
        code.push_back(item);
    }

    Solution s;
    vector<int> res;
    for (auto str : code)
    {
        s.remove(str);
        res.push_back(s.count);
        s.count = 0;
    }

    for (auto r : res)
        cout << r << endl;

    return 0;
}