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

    void preorder(TreeNode *root, vector<int> &res)
    {
        if (root != NULL)
        {
            res.push_back(root->val);
            preorder(root->left, res);
            preorder(root->right, res);
        }
    }

    void preorder_iter(TreeNode *root, vector<int> &res)
    {
        stack<TreeNode *> st;
        st.push(root);
        while (!st.empty())
        {
            TreeNode *t = st.top();
            st.pop();
            if (t == NULL)
                continue;
            res.push_back(t->val);
            // 先右子树入栈，后左子树入栈，保证左子树先被遍历！
            st.push(t->right);
            st.push(t->left);
        }
    }

    void preorder_color(TreeNode *root, vector<int> &res)
    {
        stack<pair<TreeNode *, int>> st;
        st.push({root, 0});
        while (!st.empty())
        {
            TreeNode *t = st.top().first;
            int val = st.top().second;
            st.pop();
            if (t == NULL)
                continue;

            if (val == 0)
            {
                st.push({t->right, 0});
                st.push({t->left, 0});
                st.push({t, 1});
            }
            else
            {
                res.push_back(t->val);
            }
        }
    }

    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> res;
        if (root == NULL)
            return res;
        // preorder(root, res);
        preorder_color(root, res);
        return res;
    }
};

int main()
{
    Solution *s = new Solution(0);
    TreeNode *root = s->create();

    vector<int> res = s->preorderTraversal(root);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";

    return 0;
}