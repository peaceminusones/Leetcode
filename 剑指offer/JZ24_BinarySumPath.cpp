#include <iostream>
#include <vector>
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
public:
    vector<vector<int>> FindPath(TreeNode *root, int expectNumber)
    {
        vector<vector<int>> res;
        if (root == NULL)
            return res;

        vector<int> cur;
        FindPathHelper(root, expectNumber, res, cur);
        return res;
    }

    void FindPathHelper(TreeNode *root, int expectNumber, vector<vector<int>> &res, vector<int> &cur)
    {
        if (expectNumber < 0)
            return;

        if (root == NULL)
            return;

        if (root->left == NULL && root->right == NULL && expectNumber == root->val)
        {
            cur.push_back(root->val);
            res.push_back(cur);
            cur.pop_back();
            return;
        }

        if (root->left == NULL && root->right == NULL)
            return;

        cur.push_back(root->val);
        FindPathHelper(root->left, expectNumber - root->val, res, cur);
        FindPathHelper(root->right, expectNumber - root->val, res, cur);
        cur.pop_back();
    }
};

int main()
{
    return 0;
}