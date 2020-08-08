#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int i = 0, j = height.size() - 1;
        int maxarea = 0;
        while (i < j)
        {
            int area = (j - i) * min(height[i], height[j]);
            maxarea = max(area, maxarea);
            if (height[i] < height[j])
                i++;
            else
                j--;
        }
        return maxarea;
    }
};

int main()
{
    vector<int> height;
    int item;
    while (cin >> item)
    {
        height.push_back(item);
        if (cin.get() == '\n')
            break;
    }

    Solution s;
    cout << s.maxArea(height) << endl;
    return 0;
}