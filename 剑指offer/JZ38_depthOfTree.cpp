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
    Solution(int x) : refval(x) {}

    TreeNode *creat()
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
            t->left = creat();
            t->right = creat();
            return t;
        }
    }

    int TreeDepth(TreeNode *pRoot)
    {
        if (pRoot == NULL)
            return 0;
        queue<TreeNode *> que;
        que.push(pRoot);
        int level = 0;
        while (!que.empty())
        {
            level++;
            int size = que.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = que.front();
                que.pop();
                if (node == NULL)
                    continue;
                if (node->left)
                    que.push(node->left);
                if (node->right)
                    que.push(node->right);
            }
        }
        return level;
    }

    void preOrder(TreeNode *pRoot)
    {
        vector<int> res;
        stack<TreeNode *> st;
        st.push(pRoot);
        while (!st.empty())
        {
            TreeNode *t = st.top();
            st.pop();
            if (t == NULL)
                continue;
            res.push_back(t->val);
            cout << t->val << " ";
            // 右子树先入栈后遍历
            st.push(t->right);
            st.push(t->left);
        }
    }

    void inOrder(TreeNode *pRoot)
    {
        vector<int> res;
        stack<TreeNode *> st;
        TreeNode *cur = pRoot;
        while (!st.empty() || cur != NULL)
        {
            while (cur)
            {
                st.push(cur);
                cur = cur->left;
            }

            cur = st.top();
            st.pop();
            if (cur == NULL)
                continue;
            res.push_back(cur->val);

            cur = cur->right;
        }
    }

    void postOrder(TreeNode *pRoot)
    {
        vector<int> res;
        stack<TreeNode *> st;
        st.push(pRoot);
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
};


int main()
{
    Solution *s = new Solution(0);
    TreeNode *root = s->creat();

    cout << s->TreeDepth(root) << endl;

    s->preOrder(root);
    s->inOrder(root);
    s->postOrder(root);

    return 0;
}