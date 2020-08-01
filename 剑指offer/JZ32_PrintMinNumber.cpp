#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    static bool cmp(int a, int b)
    {
        string s1 = "", s2 = "";

        s1 += to_string(a) + to_string(b);

        s2 += to_string(b) + to_string(a);

        return s1 < s2;
    }

    string PrintMinNumber(vector<int> numbers)
    {
        string res = "";
        sort(numbers.begin(), numbers.end(), cmp);
        for (int i = 0; i < numbers.size(); i++)
        {
            res += to_string(numbers[i]);
        }
        return res;
    }
};

int main()
{
    vector<int> numbers;
    int item;
    while (cin >> item)
    {
        numbers.push_back(item);
        if (cin.get() == '\n')
            break;
    }

    Solution s;
    string res = s.PrintMinNumber(numbers);
    cout << res << endl;

    return 0;
}