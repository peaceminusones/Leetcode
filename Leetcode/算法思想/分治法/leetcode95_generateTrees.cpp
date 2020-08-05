#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {}
};

class Solution
{
public:
    vector<TreeNode *> generateTrees(int n)
    {
        vector<TreeNode *> res;
        if (n == 0)
            return res;

        return generateSubtrees(1, n);
    }

    vector<TreeNode *> generateSubtrees(int l, int r)
    {
        vector<TreeNode *> res;
        if (l > r)
        {
            res.push_back(NULL);
            return res;
        }

        // pick a root 选择一个根节点m
        for (int m = l; m <= r; m++)
        {
            // 如果m被选为根节点，所有可能的左子树
            vector<TreeNode *> leftsub = generateSubtrees(l, m - 1);
            // 如果m被选为根节点，所有可能的右子树
            vector<TreeNode *> rightsub = generateSubtrees(m + 1, r);

            // 把左右子树连接到root上
            for (int i = 0; i < leftsub.size(); i++)
                for (int j = 0; j < rightsub.size(); j++)
                {
                    TreeNode *root = new TreeNode(m);
                    root->left = leftsub[i];
                    root->right = rightsub[j];

                    res.push_back(root);
                }
        }
        return res;
    }

    /*
     * 动态规划 ===================================
    */
    vector<TreeNode *> generateTrees_dp(int n)
    {
        if (n == 0)
            return {};

        vector<vector<vector<TreeNode *>>> dp(n + 1);

        for (int i = 0; i <= n; i++)
            dp[i].resize(n + 1);

        for (int i = 1; i <= n; i++)
            dp[i][i].push_back(new TreeNode(i));

        for (int r = 2; r <= n; r++)
        {
            // 起始点
            for (int i = 1; i <= n; i++)
            {
                // 结束点
                int j = i + r - 1;
                if (j > n)
                    break;

                // 计算dp[i][j] ===============================================
                vector<TreeNode *> res;
                // 以i为根节点，[]为左子树，[i+1][j]为右子树
                vector<TreeNode *> res2 = dp[i + 1][j];
                for (int q = 0; q < res2.size(); q++)
                {
                    TreeNode *root = new TreeNode(i); // 必须放在循环里！因为每个root的子树不一样
                    root->left = NULL;
                    root->right = res2[q];
                    res.push_back(root);
                }
                // 以k为根节点，分为左子树右子树
                for (int k = i + 1; k < j; k++)
                {
                    vector<TreeNode *> res1 = dp[i][k - 1];
                    vector<TreeNode *> res2 = dp[k + 1][j];
                    for (int p = 0; p < res1.size(); p++)
                    {
                        for (int q = 0; q < res2.size(); q++)
                        {
                            TreeNode *root = new TreeNode(k); // 必须放在循环里
                            root->left = res1[p];
                            root->right = res2[q];
                            res.push_back(root);
                        }
                    }
                }
                // 以j为根节点，[i][j-1]为左子树，[]为右子树
                vector<TreeNode *> res1 = dp[i][j - 1];
                for (int p = 0; p < res1.size(); p++)
                {
                    TreeNode *root = new TreeNode(j); // 必须放在循环里
                    root->left = res1[p];
                    root->right = NULL;
                    res.push_back(root);
                }

                dp[i][j] = res;
                // ============================================================
            }
        }

        return dp[1][n];
    }
};

int main()
{
    int n;
    cin >> n;

    Solution s;
    vector<TreeNode *> res = s.generateTrees_dp(n);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i]->val << " ";
    }

    return 0;
}