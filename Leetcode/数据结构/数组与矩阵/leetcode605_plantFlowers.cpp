#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        if (flowerbed.empty())
            return false;
        if (n == 0)
            return true;

        int count = 0;
        for (int i = 0; i < flowerbed.size(); i++)
        {
            if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) && (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0))
            {
                flowerbed[i] = 1;
                count++;
            }
            if (count >= n)
                return true;
        }
        return false;
    }
};

int main()
{
    return 0;
}