#include <iostream>
#include <vector>
using namespace std;

//Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
    int refval;

public:
    Solution(int x) : refval(x) {}

    TreeNode *creat()
    {
        int item;
        cin >> item;
        if (item == refval)
            return NULL;
        else
        {
            TreeNode *t = new TreeNode(item);
            t->left = creat();
            t->right = creat();
            return t;
        }
    }

    void preorder(TreeNode *t)
    {
        if (t != NULL)
        {
            cout << t->val << " ";
            preorder(t->left);
            preorder(t->right);
        }
    }

    bool isSubtree(TreeNode *s, TreeNode *t)
    {
        if (s == NULL) // 如果s为NULL，直接返回false
            return false;

        if (helper(s, t)) // t是s的子树，则直接返回true
            return true;

        // 否则就继续探索s的左子树和右子树
        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }

    bool helper(TreeNode *s, TreeNode *t)
    {
        if (s == NULL && t == NULL) // 如果两个节点都为空，则返回true
            return true;
        if (s == NULL || t == NULL) // 如果只有一个节点为空，则返回false
            return false;

        // 两个节点都不为空，就需要满足三个条件
        // 当前节点的值相等；左子树相等；右子树相等
        return s->val == t->val && helper(s->left, t->left) && helper(s->right, t->right);
    }
};

int main()
{
    Solution *s = new Solution(0);
    TreeNode *t1 = s->creat();
    TreeNode *t2 = s->creat();
    s->preorder(t1);
    cout << endl;
    s->preorder(t2);
    cout << endl;

    bool res = s->isSubtree(t1, t2);
    cout << res << endl;

    return 0;
}