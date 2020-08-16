#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution
{
public:
    int longestValidParentheses(string s)
    {
        if (s.empty())
            return 0;

        vector<int> dp(s.size(), 0);
        int res = 0;
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] == ')')
            {
                if (s[i - 1] == '(')
                {
                    int tmp = i >= 2 ? dp[i - 2] : 0;
                    dp[i] = tmp + 2;
                }
                else if (i - dp[i - 1] >= 1 && s[i - dp[i - 1] - 1] == '(')
                {
                    int tmp = (i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0;
                    dp[i] = dp[i - 1] + tmp + 2;
                }
            }
            cout << i << " " << dp[i] << endl;
            res = max(res, dp[i]);
        }
        return res;
    }

    int longestValidParentheses_stack(string s)
    {
        if (s.empty())
            return 0;

        stack<int> st;
        st.push(-1);
        int res = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                st.push(i);
            else if (s[i] == ')')
            {
                st.pop();
                if (st.empty())
                {
                    st.push(i);
                }
                else
                {
                    res = max(res, i - st.top());
                }
            }
        }
        return res;
    }
};

int main()
{
    string str;
    cin >> str;
    Solution s;
    cout << s.longestValidParentheses_stack(str) << endl;
    return 0;
}