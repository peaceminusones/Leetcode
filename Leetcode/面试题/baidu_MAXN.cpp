#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> MaxNnumber(vector<int> &nums, int N)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        int size = 0;
        for (auto n : nums)
        {
            if (size < N)
            {
                pq.push(n);
                size++;
            }
            else if (size >= N && n > pq.top())
            {
                pq.pop();
                pq.push(n);
            }
        }
        vector<int> res;
        while (!pq.empty())
        {
            res.push_back(pq.top());
            pq.pop();
        }
        return res;
    }
};

int main()
{
    vector<int> nums;
    int item;
    while (cin >> item)
    {
        nums.push_back(item);
        if (cin.get() == '\n')
            break;
    }
    int N;
    cin >> N;

    Solution s;

    vector<int> res = s.MaxNnumber(nums, N);
    for (auto r : res)
        cout << r << " ";
    return 0;
}