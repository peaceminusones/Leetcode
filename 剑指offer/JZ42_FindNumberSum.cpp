#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    // vector<int> FindNumbersWithSum(vector<int> array, int sum)
    // {
    //     unordered_map<int, int> map;
    //     for (int i = 0; i < array.size(); i++)
    //     {
    //         map[array[i]] = i;
    //     }

    //     vector<int> res;
    //     int multimax = sum * sum;
    //     for (int i = 0; i < array.size(); i++)
    //     {
    //         if (map.find(sum - array[i]) != map.end())
    //         {
    //             int j = map[sum - array[i]];
    //             if (j > i && array[j] * array[i] < multimax)
    //             {
    //                 multimax = array[i] * array[j];
    //                 res = {array[i], array[j]};
    //             }
    //         }
    //     }
    //     return res;
    // }

    vector<int> FindNumbersWithSum(vector<int> array, int sum)
    {
        int i = 0, j = array.size() - 1;
        while (i < j)
        {
            if (array[i] + array[j] == sum)
                return {array[i], array[j]};
            if (array[i] + array[j] < sum)
                i++;
            if (array[i] + array[j] > sum)
                j--;
        }
        return vector<int>{};
    }
};

int main()
{
    vector<int> array;
    int item;
    while (cin >> item)
    {
        array.push_back(item);
        if (cin.get() == '\n')
            break;
    }
    int sum;
    cin >> sum;

    Solution s;
    vector<int> res = s.FindNumbersWithSum(array, sum);
    cout << res[0] << res[1] << endl;
    return 0;
}