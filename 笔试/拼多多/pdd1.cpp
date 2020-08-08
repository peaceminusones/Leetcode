#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // K:到终点的距离
    // N:投掷色子的次数
    // nums：分别投掷的点数
    void paradox(int K, int N, vector<int> nums)
    {
        if (K == 0)
        {
            cout << "paradox" << endl;
            return;
        }
        int dis;
        int back = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (K - nums[i] > 0)
            {
                K -= nums[i];
            }
            else if (K - nums[i] == 0 && i < nums.size() - 1)
            {
                cout << "paradox" << endl;
                return;
            }
            else if (K - nums[i] == 0 && i == nums.size() - 1)
                K -= nums[i];
            else if (K - nums[i] < 0)
            {
                back++;
                K = nums[i] - K;
            }
        }
        cout << K << " " << back;
    }
};

int main()
{
    int K, N;
    cin >> K >> N;
    vector<int> nums;
    int item;
    for (int i = 0; i < N; i++)
    {
        cin >> item;
        nums.push_back(item);
    }

    Solution s;
    s.paradox(K, N, nums);

    return 0;
}