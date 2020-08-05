#include <iostream>
#include <vector>
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
    void inorder(TreeNode *root)
    {
        if (root != NULL)
        {
            inorder(root->left);
            cout << root->val << " ";
            inorder(root->right);
        }
    }

    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        if (nums.empty())
            return NULL;
        return helper(nums, 0, nums.size() - 1);
    }

    TreeNode *helper(vector<int> &nums, int l, int r)
    {
        if (l > r)
            return NULL;
        int mid = l + (r - l) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = helper(nums, l, mid - 1);
        root->right = helper(nums, mid + 1, r);

        return root;
    }
};

int main()
{
    vector<int> nums;
    int item;
    while (cin >> item)
    {
        nums.push_back(item);
    }

    Solution s;
    TreeNode *res = s.sortedArrayToBST(nums);
    s.inorder(res);

    return 0;
}