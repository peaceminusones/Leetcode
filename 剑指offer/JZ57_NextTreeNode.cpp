#include <iostream>
using namespace std;

struct TreeLinkNode
{
    int val;
    TreeLinkNode *left;  // 左节点
    TreeLinkNode *right; // 右节点
    TreeLinkNode *next;  // 父节点
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeLinkNode *GetNext(TreeLinkNode *pNode) // pNode是二叉树上的某个节点
    {
        if (pNode == NULL)
            return NULL;

        // // 如果右子树不为空，则下一个结点是右子树的最左结点
        if (pNode->right != NULL)
        {
            pNode = pNode->right;
            while (pNode->left)
            {
                pNode = pNode->left;
            }
            return pNode;
        }
        // pNode的右子树为空
        else
        {
            // pNode的父节点不为空
            while (pNode->next != NULL)
            {
                // proot为当前节点的父结点
                TreeLinkNode *proot = pNode->next;
                // 如果父结点的左孩子是当前节点，那么这个父节点proot就是下一个节点
                if (proot->left == pNode)
                    return proot;

                // 如果父结点的左孩子不是当前节点，那么就找他父结点的父结点的父结点……
                // 直到当前节点是它的父节点的左孩子
                // 则就是下一个节点
                pNode = pNode->next;
            }
        }

        // 直到根节点都没有找到，则返回NULL
        return NULL;
    }
};

int main()
{
    return 0;
}