#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        stack<int> st;
        int size = nums.size();
        vector<int> res(size, -1);
        st.push(0);
        for (int i = 1; i < 2 * size; i++)
        {
            while (!st.empty() && nums[i % size] > nums[st.top()])
            {
                res[st.top()] = nums[i % size];
                st.pop();
            }
            st.push(i % size);
        }

        return res;
    }
};

int main()
{
    vector<int> nums;
    int item;
    while (cin >> item)
        nums.push_back(item);

    Solution s;
    vector<int> res = s.nextGreaterElements(nums);
    for (int r : res)
        cout << r << " ";
    return 0;
}