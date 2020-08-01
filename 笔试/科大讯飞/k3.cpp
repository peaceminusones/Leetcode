#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isROI(vector<int> points)
{
    int zx = abs(points[0] - points[4] + points[2] - points[6]);
    int x = abs(points[0] - points[2]) + abs(points[4] - points[6]);
    int zy = abs(points[1] - points[5] + points[3] - points[7]);
    int y = abs(points[1] - points[3]) + abs(points[5] - points[7]);
    if (zx <= x && zy <= y)
        return true;
    else
        return false;
}

int main()
{
    vector<int> points;
    int item;
    for (int i = 0; i < 8; i++)
    {
        cin >> item;
        points.push_back(item);
    }
    cout << isROI(points) << endl;

    return 0;
}