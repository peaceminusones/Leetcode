#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV)
    {
        stack<int> st;
        int i = 0, j = 0;
        while (i < pushV.size())
        {
            if (pushV[i] != popV[j]) //先找到与popV第一个数相等的栈顶
            {
                st.push(pushV[i++]);
            }
            else
            {
                i++, j++;                                  // 如果栈顶和popV相等了，直接跳过
                while (!st.empty() && st.top() == popV[j]) // 再一次对比栈顶和popV，如果相等，都弹出
                {
                    st.pop();
                    j++;
                }
            }
        }
        return st.empty(); // 到最后，栈里还有元素，说明不是弹出顺序
    }
};

int main()
{
    vector<int> pushV;
    vector<int> popV;
    return 0;
}