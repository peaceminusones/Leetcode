#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void FindNumsAppearOnce(vector<int> data, int *num1, int *num2)
    {
        if (data.size() < 2)
            return;

        int size = data.size();
        int temp = data[0];

        for (int i = 1; i < size; i++)
            temp = temp ^ data[i];

        if (temp == 0)
            return;

        int index = findlowFirst1(temp); // 找到最低位的1所在位置
        
        // 根据该位置是否为1，把所有数据分为两半
        // 如此 相同的数字肯定在一个组
        // 而不同的数肯定不在一个组
        // 然后按照上面的思路，再依次进行异或
        // 剩下的结果，就是这两个只出现过一次的数字
        *num1 = *num2 = 0;
        for (int i = 0; i < size; i++)
        {
            // cout << i << endl;
            // cout << IsBit(data[i], index) << endl;
            if (IsBit(data[i], index))
            {
                *num1 ^= data[i]; // 倒数index位为1
            }
            else
            {
                *num2 ^= data[i]; // 倒数index位不为1
            }
        }
    }

    // 找到temp的二进制中最低位的1所在位置
    int findlowFirst1(int temp)
    {
        int index = 0;
        while ((temp & 1) == 0) // 如果temp二进制最后一位为0
        {
            temp = temp >> 1; // 位数右移
            ++index;          // 计算temp的1最低位所在的是第几位
        }
        return index;
    }

    // 判断数num的二进制，倒数第index位是否位1
    bool IsBit(int num, int index)
    {
        num >>= index;
        return (num & 1);
    }
};

int main()
{
    int item;
    vector<int> arr;
    while (cin >> item)
        arr.push_back(item);
    Solution s;
    int num1;
    int num2;
    s.FindNumsAppearOnce(arr, &num1, &num2); // 纠结了很久的地方！！用引用符号传送指针
    cout << num1 << " " << num2 << endl;

    return 0;
}