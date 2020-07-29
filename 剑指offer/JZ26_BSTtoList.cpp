#include <iostream>
#include <stack>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    // 先序遍历
    TreeNode *Convert(TreeNode *pRootOfTree)
    {
        if (pRootOfTree == NULL)
            return NULL;
        TreeNode *cur = pRootOfTree;
        TreeNode *pre = NULL;
        stack<TreeNode *> s;
        while (cur != NULL || !s.empty())
        {
            while (cur != NULL)
            {
                s.push(cur); // 把左孩子都压入栈中
                cur = cur->left;
            }
            if (s.empty())
                return NULL;

            cur = s.top(); // 取出当前栈顶结点
            s.pop();

            cur->left = pre; // 把当前结点的左指针指向前一个结点
            if (pre)         // 如果前一个结点不是空指针，则也把前一个结点的右指针指向当前结点
                pre->right = cur;
            pre = cur; // 更新pre指针的位置

            cur = cur->right; // 更新cur指针的位置
        }

        // 找到头节点
        TreeNode *t = pRootOfTree;
        while (t->left)
            t = t->left;
        return t;
    }
};

int main()
{
    return 0;
}