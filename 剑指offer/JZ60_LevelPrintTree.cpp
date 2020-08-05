#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;  // 左节点
    TreeNode *right; // 右节点
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
    int refval;

public:
    Solution(int x) : refval(x) {}

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

    vector<vector<int>> Print(TreeNode *pRoot)
    {
        vector<vector<int>> res;
        queue<TreeNode *> que;
        que.push(pRoot);
        int level = 0;
        while (!que.empty())
        {
            level++;
            vector<int> tmp;
            int size = que.size();
            for (int i = 0; i < size; i++)
            {

                TreeNode *node = que.front();
                que.pop();
                if (node == NULL)
                    continue;

                tmp.push_back(node->val);

                que.push(node->left);
                que.push(node->right);
            }
            if (!tmp.empty())
                res.push_back(tmp);
        }

        return res;
    }
};

int main()
{
    Solution s(0);
    TreeNode *root = s.create();
    vector<vector<int>> res = s.Print(root);
    for (int i = 0; i < res.size(); i++)
    {
        for (auto r : res[i])
            cout << r << " ";
        cout << endl;
    }
    return 0;
}