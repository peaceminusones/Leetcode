#include <iostream>
#include <stack>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){};
};

class Solution
{
    int refval;

public:
    Solution(int x) : refval(x){};

    TreeNode *creat()
    {
        TreeNode *t;
        int item;
        cin >> item;
        if (item == refval)
            return NULL;
        else
        {
            t = new TreeNode(item);
            t->left = creat();
            t->right = creat();

            return t;
        }
    }

    void preorder(TreeNode *p)
    {
        if (p)
        {
            cout << p->val << " ";
            preorder(p->left);
            preorder(p->right);
        }
    }

    /*
        递归方法 =========================================================================================================
    */
    bool Symmetrical(TreeNode *left, TreeNode *right)
    {
        if (left == NULL && right == NULL)
            return true;
        if (left == NULL || right == NULL)
            return false;

        return (left->val == right->val) && Symmetrical(left->left, right->right) && Symmetrical(left->right, right->left);
    }

    bool isSymmetrical(TreeNode *pRoot)
    {
        if (pRoot == NULL)
            return true;

        return Symmetrical(pRoot->left, pRoot->right);
    }
    /*
        =====================================================================================================================
    */

    /*
        非递归方法DFS ========================================================================================================
   */
    bool isSymmetrical_DFS(TreeNode *pRoot)
    {
        // DFS用stack来保存成对的节点
        if (pRoot == NULL)
            return true;

        stack<TreeNode *> s;
        s.push(pRoot->left);
        s.push(pRoot->right);

        while (!s.empty())
        {
            TreeNode *right = s.top();
            s.pop();
            TreeNode *left = s.top();
            s.pop();

            if (right == NULL && left == NULL)
                continue;
            if (right == NULL || left == NULL)
                return false;
            if (right->val != left->val)
                return false;

            s.push(left->left);
            s.push(right->right);
            s.push(left->right);
            s.push(right->left);
        }

        return true;
    }

    /*
        非递归方法BFS ========================================================================================================
   */
    bool isSymmetrical_BFS(TreeNode *pRoot)
    {
        // BFS用queue来保存成对的节点
        if (pRoot == NULL)
            return true;

        queue<TreeNode *> q;
        q.push(pRoot->left);
        q.push(pRoot->right);

        while (!q.empty())
        {
            TreeNode *left = q.front();
            q.pop();
            TreeNode *right = q.front();
            q.pop();

            if (left == NULL && right == NULL)
                continue;
            if (left == NULL || right == NULL)
                return false;
            if (left->val != right->val)
                return false;

            q.push(left->left);
            q.push(right->right);
            q.push(left->right);
            q.push(right->left);
        }
        return true;
    }
};

int main()
{
    Solution *s = new Solution(0);
    TreeNode *root = s->creat();
    s->preorder(root);
    cout << endl;
    bool res = s->isSymmetrical(root);
    cout << res << endl;
    return 0;
}