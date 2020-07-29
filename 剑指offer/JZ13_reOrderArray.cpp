#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void reOrderArray(vector<int> &array)
    {
        vector<int> res;
        for (auto a : array)
        {
            if (a % 2 == 1)
                res.push_back(a);
        }

        for (auto a : array)
        {
            if (a % 2 == 0)
                res.push_back(a);
        }

        array.assign(res.begin(), res.end());
    }

    void reOrderArray1(vector<int> &array)
    {
        int i = 0; // 记录当前已经插入了多少个数
        int j = 0; // 遍历数组，遇到奇数停下，插入到i位置，其中i到j-1的数据需要往后平移1位
        while (j < array.size())
        {
            if (array[j] & 1) // array[j]是奇数
            {
                int temp = array[j];
                for (int k = j - 1; k >= i; k--)
                    array[k + 1] = array[k];

                array[i] = temp;
                i++;
            }
            j++;
        }
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
    Solution s;
    s.reOrderArray1(array);
    for (auto a : array)
    {
        cout << a << " ";
    }
    cout << endl;

    return 0;
}
