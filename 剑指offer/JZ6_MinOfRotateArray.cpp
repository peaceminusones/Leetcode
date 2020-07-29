#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // 二分法！！！！
    int minNumberInRotateArray(vector<int> rotateArray)
    {
        if (rotateArray.size() == 0)
            return 0;
        int l = 0, r = rotateArray.size() - 1;
        while (l < r)
        {
            if (rotateArray[l] < rotateArray[r])
                return rotateArray[l];

            int mid = l + (r - l) / 2;
            if (rotateArray[mid] > rotateArray[l])
                l = mid + 1;
            else if (rotateArray[mid] < rotateArray[r])
                r = mid;
            else
                l++;
        }

        return rotateArray[l];
    }
};

int main()
{
    vector<int> rotateArray;
    int item;
    while (cin >> item)
    {
        rotateArray.push_back(item);
        if (cin.get() == '\n')
        {
            break;
        }
    }

    Solution s;
    int res = s.minNumberInRotateArray(rotateArray);
    cout << res << endl;
    return 0;
}