#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
    /*
     * 用map存储数字和位置
    */
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        vector<int> res;
        if (numbers.empty())
            return res;

        map<int, int> m; // 存储{number: site}
        map<int, int>::iterator it;
        for (int i = 0; i < numbers.size(); i++)
        {
            int diff = target - numbers[i]; // 计算target和当前数字的差
            it = m.find(diff);              // 如果能在m中出现，则得到了结果
            if (it != m.end())
            {
                res.push_back(m[diff] + 1); // 找到这个差出现的位置
                res.push_back(i + 1);       // 当前数字的位置
                return res;
            }
            m[numbers[i]] = i; // 没有在m中出现，则把数字和他的位置存下来
        }

        return res;
    }

    /*
     * 双指针
     * 使用双指针，一个指针指向值较小的元素，一个指针指向值较大的元素。
     * 指向较小元素的指针从头向尾遍历，指向较大元素的指针从尾向头遍历。
     * 
     * 1.如果两个指针指向元素的和 sum == target，那么得到要求的结果；
     * 2.如果 sum > target，移动较大的元素，使 sum 变小一些；
     * 3.如果 sum < target，移动较小的元素，使 sum 变大一些。
    */
    vector<int> twoSum_2(vector<int> &numbers, int target)
    {
        vector<int> res;
        if (numbers.empty())
            return res;

        int i = 0, j = numbers.size() - 1;

        while (i < j)
        {
            if (numbers[i] + numbers[j] == target)
            {
                res.push_back(i + 1);
                res.push_back(j + 1);
                return res;
            }
            else if (numbers[i] + numbers[j] < target)
            {
                i++;
            }
            else if (numbers[i] + numbers[j] > target)
            {
                j--;
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
    }
    cin.clear();
    cin.ignore();

    int target;
    cin >> target;

    Solution s;
    vector<int> res = s.twoSum(numbers, target);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";

    return 0;
}