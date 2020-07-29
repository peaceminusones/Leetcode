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
    Solution(int r) : refval(r) {}

    TreeNode *creat()
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
            t->left = creat();
            t->right = creat();
            return t;
        }
    }

    bool HasSubtree(TreeNode *pRoot1, TreeNode *pRoot2)
    {
        if (pRoot1 == NULL || pRoot2 == NULL)
            return false;

        bool res = 0;
        if (pRoot1->val == pRoot2->val)
        {
            res = HasSubTreeHelper(pRoot1, pRoot2);
        }

        if (!res)
        {
            res = HasSubtree(pRoot1->left, pRoot2);
        }

        if (!res)
        {
            res = HasSubtree(pRoot1->right, pRoot2);
        }
        
        return res;
    }

    bool HasSubTreeHelper(TreeNode *pRoot1, TreeNode *pRoot2)
    {
        if (pRoot2 == NULL)
            return true;
        if (pRoot1 == NULL)
            return false;
        if (pRoot1->val != pRoot2->val)
            return false;

        return HasSubTreeHelper(pRoot1->left, pRoot2->left) && HasSubTreeHelper(pRoot1->right, pRoot2->right);
    }
};

int main()
{
    Solution *s = new Solution(0);

    TreeNode *root1 = s->creat();
    cin.clear();
    cin.ignore();
    TreeNode *root2 = s->creat();

    bool res = s->HasSubtree(root1, root2);
    cout << res << endl;

    return 0;
}
