#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        if (s.empty())
            return true;
        stack<char> st;
        for (char ch : s)
        {
            if (ch == '(' || ch == '[' || ch == '{')
                st.push(ch);
            else
            {
                if (st.empty())
                    return false;
                bool b1 = st.top() == '(' && ch == ')';
                bool b2 = st.top() == '[' && ch == ']';
                bool b3 = st.top() == '{' && ch == '}';
                if (b1 || b2 || b3)
                {
                    st.pop();
                }
                else
                {
                    st.push(ch);
                }
            }
        }

        return st.empty();
    }
};

int main()
{
    string s = "[{()]";
    Solution sol;
    cout << sol.isValid(s) << endl;
    return 0;
}