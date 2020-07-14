#include <iostream>
#include <vector>
#include <queue>
#include <stack>
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

    void inorder(TreeNode *root, vector<int> &res)
    {
        if (root != NULL)
        {
            inorder(root->left, res);
            res.push_back(root->val);
            inorder(root->right, res);
        }
    }

    void inorder_iter(TreeNode *root, vector<int> &res)
    {
        stack<TreeNode *> st;
        TreeNode *cur = root;
        while (cur != NULL || !st.empty())
        {
            while (cur != NULL)
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

    // 左中右
    void inorder_color(TreeNode *root, vector<int> &res)
    {
        // white表示没访问过，black表示访问过了
        int white = 0, black = 1;
        stack<pair<TreeNode *, int>> st;
        st.push({root, white});
        while (!st.empty())
        {
            TreeNode *t = st.top().first;
            int color = st.top().second;
            st.pop();
            if (t == NULL)
                continue;

            if (color == white)
            {
                st.push({t->right, white});
                st.push({t, black});
                st.push({t->left, white});
            }
            else
            {
                res.push_back(t->val);
            }
        }
    }

    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> res;
        if (root == NULL)
            return res;
        inorder_color(root, res);
        return res;
    }

    // 二叉搜索树的最小绝对值差
    int getMinimumDifference(TreeNode *root);
    // 二叉搜索树的第k小元素
    int kthSmallest(TreeNode *root, int k);
    // 二叉搜索树的范围和
    int rangeSumBST(TreeNode *root, int L, int R);
    // 二叉搜索树和为k的两个节点
    vector<int> findTarget(TreeNode *root, int k);
    // 验证二叉搜索树
    bool isValidBST(TreeNode *root);
    // 二叉搜索树的众数
    vector<int> findMode(TreeNode *root);
};

// 二叉搜索树的最小绝对值差 =============================================
void getMinimumHelper(TreeNode *root, int &pre, int &res)
{
    if (root != NULL)
    {
        getMinimumHelper(root->left, pre, res);
        res = min(res, abs(pre - root->val));
        pre = root->val;
        getMinimumHelper(root->right, pre, res);
    }
}
int Solution::getMinimumDifference(TreeNode *root)
{
    if (root == NULL)
        return 0;
    int pre = 0, res = INT_MAX;
    getMinimumHelper(root, pre, res);
    return res;
}
// ====================================================================

// 二叉搜索树的第k小元素 =================================================
void kthSamllesthelper(TreeNode *root, int &k, int &res)
{
    if (root != NULL)
    {
        kthSamllesthelper(root->left, k, res);
        k--;
        if (k == 0)
        {
            res = root->val;
            return;
        }
        kthSamllesthelper(root->right, k, res);
    }
}
int Solution::kthSmallest(TreeNode *root, int k)
{
    if (root == NULL)
        return 0;
    int res;
    kthSamllesthelper(root, k, res);
    return res;
}
// =======================================================================

// 二叉搜索树的范围和 ======================================================
void rangeSumHelper(TreeNode *root, int L, int R, int &sum)
{
    if (root != NULL)
    {
        rangeSumHelper(root->left, L, R, sum);
        if (root->val >= L && root->val <= R)
            sum += root->val;
        if (root->val > R)
            return;
        rangeSumHelper(root->right, L, R, sum);
    }
}
int Solution::rangeSumBST(TreeNode *root, int L, int R)
{
    if (root == NULL)
        return 0;
    int sum = 0;
    rangeSumHelper(root, L, R, sum);
    return sum;
}
// =========================================================================

// 二叉搜索树和为k的两个节点 =================================================
void findTargetHelper(TreeNode *root, int &k, vector<int> &res, vector<int> &nums)
{
    if (root != NULL)
    {
        findTargetHelper(root->left, k, res, nums);
        nums.push_back(root->val);
        vector<int>::iterator it = find(nums.begin(), nums.end(), k - root->val);
        if (it != nums.end())
        {
            res.push_back(k - root->val);
            res.push_back(root->val);
        }
        findTargetHelper(root->right, k, res, nums);
    }
}
vector<int> Solution::findTarget(TreeNode *root, int k)
{
    vector<int> res;
    if (root == NULL || (root->left == NULL & root->right == NULL))
        return res;
    vector<int> nums;
    findTargetHelper(root, k, res, nums);
    return res;
}
// ==========================================================================

// 验证二叉搜索树 ============================================================
TreeNode *pre = NULL;
bool Solution::isValidBST(TreeNode *root)
{
    if (root != NULL)
    {
        if (!isValidBST(root->left))
            return false;

        if (pre && pre->val > root->val)
            return false;
        pre = root;

        if (!isValidBST(root->right))
            return false;
    }
    return true;
}
// ============================================================================
// 二叉搜索树的众数 ============================================================
void findModeHelper(TreeNode *root, TreeNode *&pre, int curn, int maxn, vector<int> &res)
{
    if (root != NULL)
    {
        findModeHelper(root->left, pre, curn, maxn, res);
        if (pre)
            curn = (pre->val == root->val) ? curn + 1 : 1;
        if (curn == maxn)
            res.push_back(root->val);
        else if (curn > maxn)
        {
            res.clear();
            maxn = curn;
            res.push_back(root->val);
        }
        pre = root;
        findModeHelper(root->right, pre, curn, maxn, res);
    }
}
vector<int> Solution::findMode(TreeNode *root)
{
    vector<int> res;
    if (root == NULL)
        return res;
    int curn = 0, maxn = 0;
    TreeNode *pre = NULL;
    findModeHelper(root, pre, curn, maxn, res);
    return res;
}
// ============================================================================

int main()
{
    Solution *s = new Solution(0);
    TreeNode *root = s->create();

    // vector<int> res = s->inorderTraversal(root);
    // for (int i = 0; i < res.size(); i++)
    //     cout << res[i] << " ";

    // int res = s->getMinimumDifference(root);
    // cout << res << endl;

    // int res = s->kthSmallest(root, 3);
    // cout << res << endl;

    // int L, R;
    // cin >> L >> R;
    // int res = s->rangeSumBST(root, L, R);
    // cout << res << endl;

    // int k;
    // cin >> k;
    // vector<int> res = s->findTarget(root, k);
    // cout << res[0] << res[1] << endl;

    // bool res = s->isValidBST(root);
    // cout << res << endl;

    vector<int> res = s->findMode(root);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";

    return 0;
}