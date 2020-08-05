#include <iostream>
#include <vector>
#include <string>
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
    Solution(int ref) : refval(ref) {}

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

    void preorder(TreeNode *root)
    {
        if (root)
        {
            cout << root->val << " ";
            preorder(root->left);
            preorder(root->right);
        }
    }

    /**
     * 方法一：
     * 注意！！！先把路径以vector<int>的形式保存下来，然后再转换为输出格式
     * 不然因为数字可能不止个位数，pop_back()时会出问题
     * ==================================================================================================
    */
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> res;
        if (root == NULL)
            return res;

        vector<int> cur;
        backtracking(root, res, cur);
        return res;
    }

    // 这里的cur是引用传递，所以需要回溯！！！！！
    void backtracking(TreeNode *root, vector<string> &res, vector<int> &cur)
    {
        if (root == NULL)
            return;

        cur.push_back(root->val);

        if (root->left == NULL && root->right == NULL)
        {
            res.push_back(buildpath(cur));
        }
        else
        {
            backtracking(root->left, res, cur);
            backtracking(root->right, res, cur);
        }

        cur.pop_back();
    }

    string buildpath(vector<int> cur)
    {
        string res = "";
        for (int i = 0; i < cur.size(); i++)
        {
            res += to_string(cur[i]);
            if (i != cur.size() - 1)
                res += "->";
        }
        return res;
    }

    /**
     * 方法二：
     * 递归方法  =============================================================================
     * 与上面思路的区别！cur是值传递，而不是引用传递
    */
    vector<string> binaryTreePaths_recur(TreeNode *root)
    {
        vector<string> res;
        if (root == NULL)
            return res;

        string cur = "";
        buildpath(root, cur, res);
        return res;
    }

    // 这里的cur是值传递，不需要回溯！！
    void buildpath(TreeNode *root, string cur, vector<string> &res)
    {
        if (root != NULL)
        {
            cur += to_string(root->val);
            if (root->left == NULL && root->right == NULL)
            {
                res.push_back(cur);
            }
            else
            {
                cur += "->";
                buildpath(root->left, cur, res);
                buildpath(root->right, cur, res);
            }
        }
    }

    /**
     * 方法三：
     * bfs
    */
    vector<string> binaryTreePaths_iter(TreeNode *root)
    {
        vector<string> res;
        if (root == NULL)
            return res;

        queue<pair<TreeNode *, string>> st;
        st.push({root, to_string(root->val)});
        while (!st.empty())
        {
            TreeNode *node = st.front().first;
            string cur = st.front().second;
            if (node->left == NULL && node->right == NULL)
                res.push_back(cur);
            if (node->left)
            {
                st.push({node->left, cur + "->" + to_string(node->left->val)});
            }
            if (node->right)
            {
                st.push({node->right, cur + "->" + to_string(node->right->val)});
            }
            st.pop();
        }

        return res;
    }
};

int main()
{
    Solution *s = new Solution(0);
    TreeNode *root = s->creat();

    s->preorder(root);

    cout << endl;
    vector<string> res = s->binaryTreePaths_iter(root);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";

    return 0;
}