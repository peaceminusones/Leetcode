#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int MoreThanHalfNum_Solution(vector<int> numbers)
    {
        unordered_map<int, int> map;
        int res = 0;
        for (auto n : numbers)
        {
            map[n]++;
            if (map[n] > numbers.size() / 2)
            {
                res = n;
                break;
            }
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
    int res = s.MoreThanHalfNum_Solution(numbers);
    cout << res << endl;
    return 0;
}