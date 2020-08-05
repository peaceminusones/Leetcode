#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &nums, int r, int c)
    {
        if (r * c != nums.size() * nums[0].size())
            return nums;
        vector<vector<int>> res(r, vector<int>(c));

        int index = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < nums[0].size(); j++)
            {
                res[index / c][index % c] = nums[i][j];
                index++;
            }
        }
        return res;
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
            nums.push_back(num);
    }
    cin.clear();
    cin.ignore();

    int r, c;
    cin >> r >> c;
    Solution s;
    vector<vector<int>> res = s.matrixReshape(nums, r, c);

    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[0].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}