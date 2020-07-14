#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> FindNumbersWithSum1(vector<int> array, int sum)
    {
        vector<vector<int>> res;
        int l = 0, r = array.size() - 1;
        while (l < r)
        {
            int cursum = array[l] + array[r];
            if (cursum < sum)
                l++;
            else if (cursum > sum)
                r--;
            else if (cursum == sum && l != r)
            {
                vector<int> rr;
                rr.push_back(array[l]);
                rr.push_back(array[r]);
                res.push_back(rr);
                l++;
            }
        }
        return res;
    }

    vector<int> FindNumbersWithSum(vector<int> array, int sum)
    {
        vector<int> res;
        int l = 0, r = array.size() - 1;

        while (l < r)
        {
            int cursum = array[l] + array[r];
            if (cursum < sum)
                l++;
            else if (cursum > sum)
                r--;
            else if (cursum == sum && l != r)
            {
                res.push_back(array[l]);
                res.push_back(array[r]);
                return res;
            }
        }

        return res;
    }
};

int main()
{
    vector<int> array;
    int item;
    while (cin >> item)
        array.push_back(item);
    cin.clear();
    cin.ignore();

    int sum;
    cin >> sum;

    Solution s;
    vector<vector<int>> res1 = s.FindNumbersWithSum1(array, sum);
    for (int i = 0; i < res1.size(); i++)
    {
        for (int j = 0; j < res1[i].size(); j++)
            cout << res1[i][j] << " ";
        cout << endl;
    }

    vector<int> res = s.FindNumbersWithSum(array, sum);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";

    return 0;
}