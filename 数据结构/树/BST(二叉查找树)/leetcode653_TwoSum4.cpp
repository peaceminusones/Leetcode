#include <iostream>
#include <vector>
#include <algorithm>
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

    bool findTarget(TreeNode *root, int k)
    {
        vector<int> nums;
        return findHelper(root, k, nums);
    }

    bool findHelper(TreeNode *root, int k, vector<int> &nums)
    {
        if (root == NULL)
            return false;

        // nums中存储遍历过的节点值，如果在其中可以找到k-root->val的值，则返回true
        // 否则把当前节点值放入nums，继续遍历
        vector<int>::iterator it;
        it = find(nums.begin(), nums.end(), k - root->val);
        if (it != nums.end())
            return true;

        // 当前节点值放入nums中
        nums.push_back(root->val);
        // 继续遍历
        return findHelper(root->left, k, nums) || findHelper(root->right, k, nums);
    }

    bool findTarget_bfs(TreeNode *root, int k)
    {
        if (root == NULL || (root->left == NULL && root->right == NULL))
            return false;
        queue<TreeNode *> que;
        que.push(root);
        vector<int> nums;
        vector<int>::iterator it;
        while (!que.empty())
        {
            TreeNode *node = que.front();
            que.pop();
            if (node == NULL)
                continue;

            it = find(nums.begin(), nums.end(), k - node->val);
            if (it != nums.end())
                return true;
            nums.push_back(node->val);

            que.push(node->left);
            que.push(node->right);
        }
        return false;
    }

    bool findTarget_inorder(TreeNode *root, int k)
    {
        vector<int> nums;
        inorder(root, nums);
        int i = 0, j = nums.size() - 1;
        while (i < j)
        {
            if (nums[i] + nums[j] == k)
                return true;
            if (nums[i] + nums[j] < k)
                i++;
            else
                j--;
        }
        return false;
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
};

int main()
{
    Solution *s = new Solution(0);
    TreeNode *root = s->create();
    s->preorder(root);
    cout << endl;

    int k;
    cin >> k;

    bool res = s->findTarget_bfs(root, k);
    cout << res << endl;

    return 0;
}