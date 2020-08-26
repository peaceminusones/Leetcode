#include <bits/stdc++.h>
using namespace std;

// 接雨水问题：单调栈！即维护栈内元素单调！
class Solution
{
public:
    int trap(vector<int> &height)
    {
        if (height.empty())
            return 0;

        stack<int> st; // 存储的是索引!!!
        int rain = 0;
        for (int i = 0; i < height.size(); i++)
        {
            while (!st.empty() && height[i] > height[st.top()])
            {
                int curindex = st.top();
                st.pop();

                if (st.empty())
                    break;

                // l是此次接住雨水的左边界，右边界是i
                // min(height[l], height[i]) - height[curindex]，是能接住的高度
                // i-stTop-1，是能接住的宽度
                int l = st.top();
                int r = i;
                int h = min(height[l], height[r]) - height[curindex];
                int w = r - l - 1;
                rain += h * w;
            }
            st.push(i);
        }
        return rain;
    }
};

int main()
{
    vector<int> height;
    int h;
    while (cin >> h)
    {
        height.push_back(h);
        if (cin.get() == '\n')
            break;
    }

    Solution s;
    cout << s.trap(height) << endl;
    return 0;
}