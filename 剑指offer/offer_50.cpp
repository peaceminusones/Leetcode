#include <iostream>
using namespace std;

class Solution
{
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int *duplication)
    {
        // 利用特性：numbers里的所有数字都在0~n-1之间
        // 所以可以把numbers里的值当作索引，如果两个值相同，会索引到同一个值
        for (int i = 0; i < length; i++)
        {
            int index = numbers[i] % length;

            if (numbers[index] >= length)
            {
                *duplication = index;
                return 1;
            }
            numbers[index] += length;
        }
        return 0;
    }
};

int main()
{
    int n;
    cin >> n;
    int *numbers = new int[n];
    int item;
    for (int i = 0; i < n; i++)
    {
        cin >> item;
        numbers[i] = item;
    }
    
    int *duplication = numbers;
    Solution s;
    bool res = s.duplicate(numbers, n, duplication);
    cout << res << " " << *duplication << endl;

    return 0;
}