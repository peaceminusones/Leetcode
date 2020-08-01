#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void FindNumsAppearOnce(vector<int> data, int *num1, int *num2)
    {
        // 通过异或，获得data中两个数字的二进制位哪几位不同，然后利用n&(-n)获得最低位的1
        int diff = data[0];
        for (int i = 1; i < data.size(); i++)
        {
            diff ^= data[i];
        }

        diff = (diff & (-diff));

        vector<int> arr1;
        vector<int> arr2;
        for (auto d : data)
        {
            if ((d & diff) == 0)
                arr1.push_back(d);
            else
                arr2.push_back(d);
        }

        *num1 = arr1[0];
        for (int i = 1; i < arr1.size(); i++)
            *num1 ^= arr1[i];
        *num2 = arr2[0];
        for (int i = 1; i < arr2.size(); i++)
            *num2 ^= arr2[i];
    }
};

int main()
{
    int num1;
    int *p1 = &num1;
    int num2;
    int *p2 = &num2;
    vector<int> data;
    int item;
    while (cin >> item)
    {
        data.push_back(item);
        if (cin.get() == '\n')
            break;
    }

    Solution s;
    s.FindNumsAppearOnce(data, p1, p2);
    cout << *p1 << " " << *p2 << endl;

    return 0;
}