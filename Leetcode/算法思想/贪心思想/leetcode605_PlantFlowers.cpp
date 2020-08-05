#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        if (flowerbed.size() == 0)
            return false;
        if (n == 0)
            return true;

        flowerbed.insert(flowerbed.begin(), 0);
        flowerbed.insert(flowerbed.end(), 0);

        int count = 0;
        for (int i = 1; i < flowerbed.size() - 1 && count < n; i++)
        {
            if (flowerbed[i] == 0 && flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0)
            {
                flowerbed[i] = 1;
                count++;
            }
        }
        return count == n;
    }
};

int main()
{
    vector<int> flowerbed;
    int item;
    while (cin >> item)
    {
        flowerbed.push_back(item);
    }
    cin.clear();
    cin.ignore();
    int n;
    cin >> n;

    Solution s;
    bool res = s.canPlaceFlowers(flowerbed, n);
    cout << res << endl;

    return 0;
}