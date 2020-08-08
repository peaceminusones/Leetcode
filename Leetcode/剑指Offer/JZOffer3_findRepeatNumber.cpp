#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int findRepeatNumber(vector<int> &nums)
    {
        
        unordered_map<int, int> map;
        for (auto n : nums)
        {
            if (map[n] != 0)
                return n;
            map[n]++;
        }
        return 0;
    }
};

int main()
{
    return 0;
}