#include <iostream>
#include <vector>
#include <stack>
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

    TreeNode *Creat()
    {
        TreeNode *t;
        int item;
        cin >> item;
        if (item == refval)
            return NULL;
        else
        {
            t = new TreeNode(item);
            t->left = Creat();
            t->right = Creat();

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
        // 用两个栈，一个存储奇数行的节点，一行存储偶数行的节点
        vector<vector<int>> res;
        if (pRoot == NULL)
            return res;

        stack<TreeNode *> s1, s2; // s1:奇数行节点，s2:偶数行节点
        s1.push(pRoot);

        while (!s1.empty() || !s2.empty())
        {
            vector<int> res1, res2; //res1:奇数行数据，res2:偶数行数据

            while (!s1.empty())  
            {
                // 把栈s1中的节点从上到下取出来
                TreeNode *cur = s1.top();
                s1.pop();
                // 然后按照left、right的顺序，把孩子节点压到栈s2中
                if (cur->left)
                    s2.push(cur->left);
                if (cur->right)
                    s2.push(cur->right);
                // 把栈s1中的数据存下来
                res1.push_back(cur->val);
            }
            if (res1.size())
                res.push_back(res1);

            while (!s2.empty())
            {
                // 把栈s2中的节点从上到下取出来
                TreeNode *cur = s2.top();
                s2.pop();
                // 然后按照right、left的顺序，把孩子节点压到栈s1中
                if (cur->right)
                    s1.push(cur->right);
                if (cur->left)
                    s1.push(cur->left);
                // 把栈s2中的数据存下来
                res2.push_back(cur->val);
            }
            if (res2.size())
                res.push_back(res2);
        }
        return res;
    }
};

int main()
{
    Solution *s = new Solution(0);
    TreeNode *root = s->Creat();
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