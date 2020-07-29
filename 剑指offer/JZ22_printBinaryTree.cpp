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
    vector<int> PrintFromTopToBottom(TreeNode *root)
    {
        vector<int> res;
        queue<TreeNode *> que;
        que.push(root);

        while (!que.empty())
        {
            int size = que.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = que.front();
                que.pop();
                if (node == NULL)
                    continue;
                res.push_back(node->val);
                que.push(node->left);
                que.push(node->right);
            }
        }

        return res;
    }
};

int main()
{
    return 0;
}