#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
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

    vector<double> averageOfLevels(TreeNode *root)
    {
        vector<double> res;
        if (root == NULL)
            return res;

        queue<TreeNode *> que;
        que.push(root);
        while (!que.empty())
        {
            double size = que.size();
            double sum = 0;
            for (int i = 0; i < size; i++)
            {
                TreeNode *t = que.front();
                que.pop();

                if (t == NULL)
                    continue;
                sum += t->val;
                if (t->left)
                    que.push(t->left);
                if (t->right)
                    que.push(t->right);
            }
            double aver = sum / size;
            res.push_back(aver);
        }
        return res;
    }
};

int main()
{
    Solution *s = new Solution(0);
    TreeNode *root = s->create();
    s->preorder(root);
    cout << endl;

    vector<double> res = s->averageOfLevels(root);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";

    return 0;
}