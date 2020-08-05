#include <iostream>
#include <vector>
#include <queue>
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

    TreeNode *create()
    {
        int item;
        cin >> item;
        if (item == refval)
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
        if (root != NULL)
        {
            cout << root->val << " ";
            preorder(root->left);
            preorder(root->right);
        }
    }

    int findBottomLeftValue(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int left = root->val;
        queue<TreeNode *> que;
        que.push(root);
        TreeNode *t;
        while (!que.empty())
        {
            int size = que.size();
            for (int i = 0; i < size; i++)
            {
                t = que.front();
                que.pop();

                if (t == NULL)
                    continue;

                // 从右往左存，那么最后一行的最左边的节点就会在最后出列！
                if (t->right)
                    que.push(t->right);
                if (t->left)
                    que.push(t->left);
            }
        }
        return t->val;
    }
};

int main()
{
    Solution *s = new Solution(0);
    TreeNode *root = s->create();
    s->preorder(root);
    cout << endl;

    int res = s->findBottomLeftValue(root);
    cout << res << " ";

    return 0;
}