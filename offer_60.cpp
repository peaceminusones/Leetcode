#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
    int refval;

public:
    Solution(int x) : refval(x) {}

    TreeNode *creat()
    {
        TreeNode *t;
        int item;
        cin >> item;
        if (item == refval)
            return NULL;
        else
        {
            t = new TreeNode(item);
            t->left = creat();
            t->right = creat();

            return t;
        }
    }

    void preorder(TreeNode *p)
    {
        if (p)
        {
            cout << p->val << " ";
            preorder(p->left);
            preorder(p->right);
        }
    }

    vector<vector<int>> Print(TreeNode *pRoot)
    {
        vector<vector<int>> res;
        if (pRoot == NULL)
            return res;

        queue<TreeNode *> q;
        q.push(pRoot);

        while (!q.empty())
        {
            vector<int> r; // 用于存储当前一层的数据
            int i = 0;
            int len = q.size(); // 当前层的节点个数
            while (i++ < len)
            {
                TreeNode *cur = q.front();
                q.pop();
                if (cur->left) // 把当前层的子节点push到队列中
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);

                r.push_back(cur->val);
            }

            res.push_back(r);
        }
        return res;
    }
};

int main()
{
    Solution *s = new Solution(0);
    TreeNode *root = s->creat();
    s->preorder(root);
    cout << endl;

    vector<vector<int>> res = s->Print(root);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << endl;
    }

    return 0;
}