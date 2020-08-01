#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    int count = 0;

public:
    // 归并排序的化用
    int InversePairs(vector<int> data)
    {
        if (data.empty())
            return 0;

        mergeSort(data, 0, data.size() - 1);

        return count;
    }

    void mergeSort(vector<int> &data, int l, int r)
    {
        if (l < r)
        {
            int m = l + (r - l) / 2;
            mergeSort(data, l, m);
            mergeSort(data, m + 1, r);
            merge(data, l, m, r);
        }
    }

    void merge(vector<int> &data, int l, int m, int r)
    {
        // 注意！从小到大排序
        // l到m是排序好的，m到r是排序好的
        // 当data[i]>data[j]时，则i到m都是大于data[j]的
        vector<int> array;
        int i = l, j = m + 1;
        while (i <= m && j <= r)
        {
            if (data[i] > data[j])
            {
                array.push_back(data[j++]);
                // 与归并排序不同的地方，在merge过程中统计逆序对数
                count += (m - i + 1);
                count %= 1000000007;
            }
            else
            {
                array.push_back(data[i++]);
            }
        }

        while (i <= m)
            array.push_back(data[i++]);
        while (j <= r)
            array.push_back(data[j++]);

        for (int i = 0; i < array.size(); i++)
        {
            data[l + i] = array[i];
        }
    }
};

int main()
{
    vector<int> data;
    int item;
    while (cin >> item)
    {
        data.push_back(item);
        if (cin.get() == '\n')
            break;
    }

    Solution s;
    int res = s.InversePairs(data);
    cout << res << endl;
    return 0;
}