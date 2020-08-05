#include <iostream>
#include <vector>
#include <stack>
#include <queue>
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

    TreeNode *create()
    {
        int item;
        cin >> item;
        if (item == refval)
        {
            return NULL;
        }
        else
        {
            TreeNode *t = new TreeNode(item);
            t->left = create();
            t->right = create();
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

    /**
     * 方法一：递归
    */
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == NULL)
            return root;

        TreeNode *left = invertTree(root->left);
        TreeNode *right = invertTree(root->right);
        root->left = right;
        root->right = left;
        return root;
    }

    /**
     * dfs stack
    */
    TreeNode *invertTree_dfs(TreeNode *root)
    {
        if (root == NULL)
            return root;

        stack<TreeNode *> st;
        st.push(root);
        while (!st.empty())
        {
            TreeNode *node = st.top();
            st.pop();

            if (node == NULL)
                continue;

            st.push(node->left);
            st.push(node->right);

            TreeNode *tmp;
            tmp = node->left;
            node->left = node->right;
            node->right = tmp;
        }

        return root;
    }

    /**
     * bfs queue
    */
    TreeNode *invertTree_bfs(TreeNode *root)
    {
        if (root == NULL)
            return root;

        queue<TreeNode *> que;
        que.push(root);
        while (!que.empty())
        {
            TreeNode *node = que.front();
            que.pop();
            if (node == NULL)
                continue;

            que.push(node->left);
            que.push(node->right);

            TreeNode *tmp;
            tmp = node->left;
            node->left = node->right;
            node->right = tmp;
        }

        return root;
    }
};

int main()
{
    Solution *s = new Solution(0);
    TreeNode *root = s->create();
    s->preorder(root);
    cout << endl;

    TreeNode *res = s->invertTree_bfs(root);
    s->preorder(res);

    return 0;
}