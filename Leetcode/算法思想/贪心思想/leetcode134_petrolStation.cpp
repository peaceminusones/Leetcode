#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int totalSum = 0;
        vector<int> left;
        for (int i = 0; i < gas.size(); i++)
        {
            left.push_back(gas[i] - cost[i]);
            totalSum += left[i];
        }

        if (totalSum < 0)
            return -1;

        int start = 0;
        int startToCurrentCost = 0;
        for (int i = 0; i < left.size(); i++)
        {
            if (startToCurrentCost < 0)
            {
                start = i;
                startToCurrentCost = 0;
            }

            startToCurrentCost += left[i];
        }

        return start;
    }
};

int main()
{
}