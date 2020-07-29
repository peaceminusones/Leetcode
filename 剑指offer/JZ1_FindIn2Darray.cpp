#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool Find(int target, vector<vector<int>> &array)
    {
        int n = array.size();
        int m = array[0].size();
        int i = n - 1;
        int j = 0;
        while (i >= 0 && j < m)
        {
            if (target == array[i][j])
                return true;
            else if (target > array[i][j])
                j++;
            else if (target < array[i][j])
                i--;
        }
        return false;
    }
};

int main()
{
    vector<vector<int>> nums;
    vector<int> num;
    int item;
    while (cin >> item)
    {
        num.push_back(item);
        if (cin.get() == '\n')
        {
            nums.push_back(num);
            num.clear();
        }
        if (cin.peek() == '\n')
        {
            nums.push_back(num);
        }
    }
    cin.clear();
    cin.ignore();
    int target;
    cin >> target;

    Solution s;
    bool res = s.Find(target, nums);
    cout << res << endl;
    return 0;
}