#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool IsContinuous(vector<int> numbers)
    {
        sort(numbers.begin(), numbers.end());
        if (numbers.size() != 5)
            return false;
        
        // 大小王数量问题
        int joker = 0;
        for (int i = 0; i < numbers.size() && numbers[i] == 0; i++)
            joker++;
        if (joker > 4)
            return false;

        // 不能重复牌的问题
        for (int i = joker + 1; i < numbers.size(); i++)
        {
            if (numbers[i] == numbers[i - 1])
                return false;
        }

        // 距离问题
        int min = numbers[joker];
        int max = numbers[numbers.size() - 1];
        if ((max - min) > 4)
            return false;
        return true;
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
    bool res = s.IsContinuous(numbers);
    cout << res << endl;
    return 0;
}