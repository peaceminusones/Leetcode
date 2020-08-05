#include <iostream>
#include <vector>
#include <map>
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

    vector<int> findMode(TreeNode *root)
    {
        vector<int> res;
        if (root == NULL)
            return res;
        int curn = 1, maxn = 0;
        TreeNode *pre = NULL;
        inorder(root, pre, curn, maxn, res);
        return res;
    }

    // !!!!!TreeNode *&pre
    void inorder(TreeNode *root, TreeNode *&pre, int &curn, int &maxn, vector<int> &res)
    {
        if (root != NULL)
        {
            inorder(root->left, pre, curn, maxn, res);

            if (pre)
                curn = (root->val == pre->val) ? curn + 1 : 1;

            if (curn == maxn)
                res.push_back(root->val);
            else if (curn > maxn)
            {
                res.clear();
                res.push_back(root->val);
                maxn = curn;
            }
            pre = root;

            inorder(root->right, pre, curn, maxn, res);
        }
    }

};

int main()
{
    Solution *s = new Solution(0);
    TreeNode *root = s->create();
    // s->preorder(root);
    // cout << endl;

    vector<int> res = s->findMode(root);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;

    return 0;
}