#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int GetUglyNumber_Solution(int index)
    {
        if (index <= 6)
            return index;

        int newugly = 1;
        vector<int> res;
        int p2 = 0, p3 = 0, p5 = 0;
        res.push_back(newugly);
        while (res.size() < index)
        {
            newugly = min(min(res[p2] * 2, res[p3] * 3), res[p5] * 5);
            if (res[p2] * 2 == newugly)
                p2++;
            if (res[p3] * 3 == newugly)
                p3++;
            if (res[p5] * 5 == newugly)
                p5++;
            res.push_back(newugly);
        }

        return newugly;
    }
};

int main()
{
    return 0;
}