#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    /*
     * 仍然是计算不重叠的区间个数，因为重叠的区间，可以用一个箭就把两个气球扎破
    */
    int findMinArrowShots(vector<vector<int>> &points)
    {
        if (points.size() == 0)
            return 0;

        sort(points.begin(), points.end(), cmp);

        int count = 1;
        int end = points[0][1];
        for (int i = 0; i < points.size(); i++)
        {
            if (points[i][0] <= end)
                continue;
            end = points[i][1];
            count++;
        }
        return count;
    }

    static bool cmp(vector<int> &a, vector<int> &b)
    {
        return a[1] < b[1];
    }
};

int main()
{
    return 0;
}