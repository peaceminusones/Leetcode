#include <iostream>
#include <vector>
#include <queue>
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
    int refval;

public:
    Solution(int r) : refval(r) {}

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

    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int res = 0;
        // dfs(root, res, 0);
        bfs(root, res);
        return res;
    }

    void dfs(TreeNode *t, int &res, int dep)
    {
        if (t == NULL)
        {
            res = max(res, dep);
            return;
        }
        dep++;
        dfs(t->left, res, dep);
        dfs(t->right, res, dep);
    }

    void bfs(TreeNode *t, int &res)
    {
        queue<TreeNode *> que;
        que.push(t);
        while (!que.empty())
        {
            int size = que.size();
            res++;
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = que.front();
                que.pop();
                if (node->left)
                    que.push(node->left);
                if (node->right)
                    que.push(node->right);
            }
        }
    }

    int maxDepth_recur(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int leftheight = 0, rightheight = 0;
        leftheight += maxDepth(root->left) + 1;
        rightheight += maxDepth(root->right) + 1;
        return max(leftheight, rightheight);
    }
};

int main()
{
    Solution *s = new Solution(0);
    TreeNode *root = s->creat();
    s->preorder(root);
    cout << endl;
    int res = s->maxDepth(root);
    cout << res << endl;
    return 0;
}