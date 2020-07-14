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

    TreeNode *KthNode(TreeNode *pRoot, int k)
    {
        if (pRoot == NULL || k == 0)
            return NULL;

        stack<TreeNode *> s;
        int count = 0;
        TreeNode *p = pRoot;

        // 非递归中序遍历，搜索二叉树，中序遍历就是从小到大
        while (p != NULL || !s.empty())
        {
            if (p != NULL)
            {
                s.push(p);
                p = p->left;
            }
            else
            {
                p = s.top();
                s.pop();
                count++;
                if (count == k)
                    return p;
                p = p->right;
            }
        }

        return NULL;
    }
};

int main()
{
    int k;
    cin >> k;

    Solution *s = new Solution(0);
    TreeNode *root = s->creat();
    s->preorder(root);
    cout << endl;

    TreeNode *res = s->KthNode(root, k);
    cout << res->val << endl;

    return 0;
}