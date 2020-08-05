#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;  // 左节点
    TreeNode *right; // 右节点
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    // 中序排序是顺序的
    TreeNode *KthNode(TreeNode *pRoot, int k)
    {
        if (pRoot == NULL || k == 0)
            return NULL;
        
        stack<TreeNode *> st;
        TreeNode *p = pRoot;
        int count = 0;
        while (p != NULL || !st.empty())
        {
            while (p)
            {
                st.push(p);
                p = p->left;
            }

            p = st.top();
            st.pop();
            if (p == NULL)
                continue;

            count++;
            if (count == k)
                return p;

            p = p->right;
        }
        return NULL;
    }
};

int main()
{
    return 0;
}