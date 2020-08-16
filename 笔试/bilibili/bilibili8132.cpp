#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution
{
public:
    bool isValidExp(string s)
    {
        if (s.size() % 2 != 0)
            return false;
        if (s.size() == 0)
            return true;

        stack<char> st;
        for (char c : s)
        {
            switch (c)
            {
            case '(':
            case '{':
            case '[':
                st.push(c);
                break;
            case ')':
                if (st.empty() || st.top() != '(')
                    return false;
                else
                    st.pop();
                break;
            case '}':
                if (st.empty() || st.top() != '{')
                    return false;
                else
                    st.pop();
                break;
            case ']':
                if (st.empty() || st.top() != '[')
                    return false;
                else
                    st.pop();
                break;
            default:;
            }
        }
        return st.empty();
    }

    bool isValid(string s)
    {
        if (s.empty())
            return true;

        stack<char> st;
        for (auto ch : s)
        {
            if (ch == '(' || ch == '{' || ch == '[')
                st.push(ch);
            else
            {
                if (st.empty())
                    return false;
                bool b1 = st.top() != '(' && ch == ')';
                bool b2 = st.top() != '{' && ch == '}';
                bool b3 = st.top() != '[' && ch == ']';
                st.pop();
                if (b1 || b2 || b3)
                {
                    return false;
                }
            }
        }
        return st.empty();
    }
};

int main()
{
    string str;
    cin >> str;
    Solution s;
    cout << s.isValidExp(str) << endl;
    return 0;
}