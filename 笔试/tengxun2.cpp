#include <iostream>
#include <vector>
#include <math.h>
#include <iomanip>
using namespace std;

class Solution
{
public:
    double distance(vector<vector<double>> point)
    {
        double min = 100000;
        for (int i = 0; i < point.size() / 2; i++)
            for (int j = point.size() / 2; j < point.size(); j++)
            {
                double dis = sqrt(pow(point[i][0] - point[j][0], 2) + pow(point[i][1] - point[j][1], 2));
                if (dis < min)
                    min = dis;
            }
        return min;
    }
};

int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    cin.clear();
    cin.ignore();

    double x, y;
    vector<double> res;
    Solution s;
    for (int k = 0; k < n; k++)
    {
        vector<vector<double>> point;
        for (int i = 0; i < 2 * m; i++)
        {
            vector<double> item(2);
            cin >> item[0] >> item[1];
            point.push_back(item);
        }
        double r = s.distance(point);
        res.push_back(r);
    }

    for (int i = 0; i < res.size(); i++)
        cout << fixed << setprecision(3) << res[i] << endl;

    return 0;
}