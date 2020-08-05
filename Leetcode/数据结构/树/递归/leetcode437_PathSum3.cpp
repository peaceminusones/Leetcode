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
    int refval;

public:
    Solution(int x) : refval(x) {}

    TreeNode *creat()
    {
        int item;
        cin >> item;
        if (item == refval)
            return NULL;
        else
        {
            TreeNode *t = new TreeNode(item);
            t->left = creat();
            t->right = creat();
            return t;
        }
    }

    void preorder(TreeNode *t)
    {
        if (t != NULL)
        {
            cout << t->val << " ";
            preorder(t->left);
            preorder(t->right);
        }
    }

    int res = 0;
    int pathSum(TreeNode *root, int sum)
    {
        if (root == NULL)
            return 0;

        pathSum(root->left, sum);
        pathSum(root->right, sum);
        helper(root, sum);
        return res;
    }

    void helper(TreeNode *root, int sum)
    {
        if (root == NULL)
            return;
        if (sum - root->val == 0)
        {
            // 这里不能return！！因为树的值有正有负，当前得到了一个结果，接着往下遍历可能还有结果
            res++;
        }

        helper(root->left, sum - root->val);
        helper(root->right, sum - root->val);
    }
};

int main()
{
    Solution *s = new Solution(0);
    TreeNode *t = s->creat();
    s->preorder(t);
    cout << endl;

    int sum;
    cin >> sum;

    int res = s->pathSum(t, sum);
    cout << res << endl;
    return 0;
}