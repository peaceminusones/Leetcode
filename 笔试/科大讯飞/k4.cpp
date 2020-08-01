#include <iostream>
#include <vector>
#include <string>
using namespace std;

string abstractInt(string str)
{
    if (str.empty())
        return "";
    vector<char> res;
    int flag = 1;
    int isnumber = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            res.push_back(str[i]);
            isnumber = 1;
        }
        if (str[i] == '-' && isnumber == 0)
            flag = -1;
    }

    string nums = "";
    for (auto r : res)
    {
        nums += r;
    }

    if (flag == -1)
        return ("-" + nums);

    return nums;
}

int main()
{
    string str;
    cin >> str;
    cout << abstractInt(str) << endl;
    return 0;
}