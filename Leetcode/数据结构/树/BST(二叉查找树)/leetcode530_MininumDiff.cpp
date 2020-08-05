#include <iostream>
#include <vector>
#include <algorithm>
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

    int getMinimumDifference(TreeNode *root)
    {
        vector<int> nums;
        inorder(root, nums);
        vector<int> res;
        for (int i = 1; i < nums.size(); i++)
        {
            res.push_back(abs(nums[i] - nums[i - 1]));
        }
        sort(res.begin(), res.end());
        return res[0];
    }

    void inorder(TreeNode *root, vector<int> &nums)
    {
        if (root != NULL)
        {
            inorder(root->left, nums);
            nums.push_back(root->val);
            inorder(root->right, nums);
        }
    }

    int getMinimumDifference_dfs(TreeNode *root)
    {
        int res = INT_MAX, pre = INT_MAX;
        inorder_dfs(root, res, pre);

        return res;
    }

    void inorder_dfs(TreeNode *root, int &res, int &pre)
    {
        if (root != NULL)
        {
            inorder_dfs(root->left, res, pre);
            
            res = min(res, abs(root->val - pre));
            pre = root->val;
            
            inorder_dfs(root->right, res, pre);
        }
    }
};

int main()
{
    Solution *s = new Solution(0);
    TreeNode *root = s->create();
    s->preorder(root);
    cout << endl;

    int res = s->getMinimumDifference_dfs(root);
    cout << res << endl;
    return 0;
}