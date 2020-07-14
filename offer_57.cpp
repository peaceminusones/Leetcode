#include <iostream>
using namespace std;

struct TreeLinkNode
{
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next; // 父节点
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL){};
};

class Solution
{
    TreeLinkNode *root;
    int refval;

public:
    Solution(int r) : refval(r), root(NULL){};

    TreeLinkNode *create(TreeLinkNode *parent) // 构造一个带有指向父结点指针的二叉树
    {
        TreeLinkNode *t, *t1, *t2;
        TreeLinkNode *leaf;
        int item;
        cin >> item;
        if (item == refval)
            return NULL;
        else
        {
            t = new TreeLinkNode(item);
            t->next = parent; // 指向父结点

            t1 = create(t);
            t->left = t1;

            t2 = create(t);
            t->right = t2;

            root = t;
            return root;
        }
    }

    void preorder(TreeLinkNode *p) // 先序遍历
    {
        if (p)
        {
            cout << p->val << " ";
            preorder(p->left);
            preorder(p->right);
        }
    }

    void Inorder(TreeLinkNode *p)
    {
        if (p)
        {
            Inorder(p->left);
            cout << p->val << " ";
            Inorder(p->right);
        }
    }

    TreeLinkNode *GetNext(TreeLinkNode *pNode) // 中序遍历的pNode的下一个结点
    {
        if (pNode == NULL)
            return NULL;

        // 如果右子树不为空，则下一个结点是右子树的最左结点
        if (pNode->right != NULL)
        {
            pNode = pNode->right;
            while (pNode->left != NULL)
                pNode = pNode->left;
            return pNode;
        }

        // 如果右子树为空
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

        // 直到根节点都没有找到，则返回NULL
        return NULL;
    }
};

int main()
{
    Solution *s = new Solution(0);
    TreeLinkNode *root = s->create(NULL);
    s->preorder(root);
    cout << endl;
    s->Inorder(root);
    cout << endl;
    TreeLinkNode *res = s->GetNext(root->right);
    if (!res)
        cout << "NULL" << endl;
    else
        cout << res->val << endl;

    return 0;
}