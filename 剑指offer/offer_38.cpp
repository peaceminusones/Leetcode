#include <iostream>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    int valRef;

    TreeNode *create()
    {
        int item;
        cin >> item;
        if (item == valRef)
            return NULL;
        else
        {
            TreeNode *t = new TreeNode(item);
            t->left = create();
            t->right = create();
            return t;
        }
    }

    void preorder(TreeNode *root)
    {
        if (root == NULL)
            return;
        else
        {
            cout << root->val << " ";
            preorder(root->left);
            preorder(root->right);
        }
    }

    // 递归方法
    int TreeDepth(TreeNode *pRoot)
    {
        if (pRoot == NULL)
            return 0;
        else
            return max(1 + TreeDepth(pRoot->left), 1 + TreeDepth(pRoot->right));
    }

    // 非递归(层次遍历)
    int noncurTreeDepth(TreeNode *pRoot)
    {
        if (pRoot == NULL)
            return 0;
        queue<TreeNode *> Q;
        Q.push(pRoot);
        int depth = 0;
        int count = 0; // 已遍历的当前层的节点数
        int nextcount = 1; // 存储的是当前层有多少个结点
        while (!Q.empty())
        {
            count++;
            TreeNode *top = Q.front();
            Q.pop();

            if (top->left != NULL)
                Q.push(top->left);
            if (top->right != NULL)
                Q.push(top->right);

            if (count == nextcount) // 如果当前层的结点全部遍历结束
            {
                nextcount = Q.size();
                count = 0; 
                depth++; // 深度加一
            }
        }
        return depth;
    }
};

int main()
{
    Solution s;
    s.valRef = 0;
    TreeNode *root = s.create();
    s.preorder(root);
    int res = s.TreeDepth(root);
    cout << res << endl;
    res = s.noncurTreeDepth(root);
    cout << res << endl;
    return 0;
}