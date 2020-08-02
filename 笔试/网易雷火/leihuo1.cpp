#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
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
    Solution(int f) : refval(f) {}

    TreeNode *create(int n, int &i)
    {
        TreeNode *t = new TreeNode(i);
        queue<TreeNode *> que;
        que.push(t);
        while (i < pow(2, n) - 1)
        {
            TreeNode *node = que.front();
            que.pop();
            i++;
            node->left = new TreeNode(i);
            que.push(node->left);
            i++;
            node->right = new TreeNode(i);
            que.push(node->right);
        }
        return t;
        // if (i < pow(n, 2))
        // {
        //     TreeNode *t = new TreeNode(i);
        //     i++;
        //     t->left = create(n, i);
        //     i++;
        //     t->right = create(n, i);
        //     return t;
        // }
        // return NULL;
    }

    void inorder(TreeNode *root)
    {
        if (root != NULL)
        {
            cout << root->val << " ";
            inorder(root->left);
            inorder(root->right);
        }
    }

    void Mirror(TreeNode *root, int val)
    {
        if (root == NULL)
            return;
        if (root->val != val)
        {
            Mirror(root->left, val);
            Mirror(root->right, val);
        }
        else
            MirrorHelper(root);
    }

    void MirrorHelper(TreeNode *root)
    {
        if (root == NULL)
            return;
        TreeNode *tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        // MirrorHelper(root->left);
        // MirrorHelper(root->right);
    }

    void order(TreeNode *root, vector<int> &res)
    {
        queue<TreeNode *> que;
        que.push(root);
        while (!que.empty())
        {
            TreeNode *node = que.front();
            que.pop();
            if (node == NULL)
                continue;
            res.push_back(node->val);
            que.push(node->left);
            que.push(node->right);
        }
    }
};

int main()
{
    Solution *s = new Solution(0);
    int n;
    cin >> n;
    int i = 1;
    TreeNode *root = s->create(n, i);

    s->inorder(root);
    s->Mirror(root, 1);
    cout << endl;
    s->inorder(root);
    cout << endl;
    vector<int> res;
    s->order(root, res);
    for (auto r : res)
        cout << r << " ";
    return 0;
}