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

    void postorder(TreeNode *root, vector<int> &res)
    {
        if (root != NULL)
        {
            postorder(root->left, res);
            postorder(root->right, res);
            res.push_back(root->val);
        }
    }

    void postorder_iter(TreeNode *root, vector<int> &res)
    {
        stack<TreeNode *> st;
        st.push(root);
        while (!st.empty())
        {
            TreeNode *t = st.top();
            st.pop();
            if (t == NULL)
                continue;
            res.insert(res.begin(), t->val);
            st.push(t->left);
            st.push(t->right);
        }
    }

    void postorder_color(TreeNode *root, vector<int> &res)
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
                st.push({t, 1});
                st.push({t->right, 0});
                st.push({t->left, 0});
            }
            else
            {
                res.push_back(t->val);
            }
        }
    }

    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> res;
        if (root == NULL)
            return res;
        postorder_color(root, res);
        return res;
    }
};

int main()
{
    Solution *s = new Solution(0);
    TreeNode *root = s->create();

    vector<int> res = s->postorderTraversal(root);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";

    return 0;
}