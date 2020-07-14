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
    int refval;

public:
    Solution(int r) : refval(r) {}

    TreeNode *create()
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
            t->left = create();
            t->right = create();
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

    /**
     * 子问题：（爷爷+孙子）vs（父亲）
     * 超时！！！！
    */
    int rob(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        // val1表示root层偷了，所以跳过下一层，直接考虑下下层（爷爷+孙子）
        int val1 = root->val;
        if (root->left != NULL)
        {
            val1 += (rob(root->left->left) + rob(root->left->right));
        }
        if (root->right != NULL)
        {
            val1 += (rob(root->right->left) + rob(root->right->right));
        }
        // val2表示root层没有偷（父亲）
        int val2 = rob(root->left) + rob(root->right);
        return max(val1, val2);
    }

    // int rob(TreeNode *root)
    // {
    //     if (root == NULL)
    //         return 0;

    //     return dfs(root, 0);
    // }

    /**
     * 方法一：递归！
     * 分三种情况：
     * 1、父节点偷了，则本层节点不偷
     * 2、父节点没偷，且本层节点偷
     * 3、父节点没偷，且本节点也不偷
     * 超时了！！！！
    */
    // status记录父节点的是否被偷，0表示没偷，1表示偷了
    int dfs(TreeNode *t, int status)
    {
        if (t == NULL)
            return 0;

        int a = 0, b = 0; // 分别记录三种情况的值
        //情况1＋情况3：不管父节点偷没偷，本层节点都不偷
        a = dfs(t->left, 0) + dfs(t->right, 0);
        // 情况2，父节点没偷，本层节点偷
        if (status == 0)
        {
            b = dfs(t->left, 1) + dfs(t->right, 1) + t->val;
        }

        return max(a, b);
    }

    /**
     * 上面方法缺陷就是对于同一个节点，可能要递归计算多次，毕竟一层就有4个递归调用
     * 所以需要对于重复的计算，需要记下来
     * 所以对每个节点来说，只需要计算“偷”和“不偷”两种状态下的最大值，那么它的父节点在计算时，可以直接拿这个值，不用再遍历这个节点的子树了
    */

    /**
     * 错误原因：不是只能隔一层，还可以隔多层
    */
    // int bfs(TreeNode *t)
    // {
    //     vector<int> res(2);
    //     queue<pair<TreeNode *, int>> que;
    //     que.push({t, 0});
    //     while (!que.empty())
    //     {
    //         int size = que.size();
    //         for (int i = 0; i < size; i++)
    //         {
    //             TreeNode *node = que.front().first;
    //             int flag = que.front().second;
    //             que.pop();
    //             if (node == NULL)
    //                 continue;

    //             res[flag] += node->val;
    //             que.push({node->left, !flag});
    //             que.push({node->right, !flag});
    //         }
    //     }

    //     return max(res[0], res[1]);
    // }
};

int main()
{
    Solution *s = new Solution(0);
    TreeNode *t = s->create();
    s->preorder(t);
    cout << endl;

    int res = s->rob(t);
    cout << res << endl;
    return 0;
}