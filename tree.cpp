#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
private:
    TreeNode *root;
    int ref;

public:
    TreeNode *Create()
    {
        TreeNode *t, *t1, *t2;
        int item;
        cin >> item;
        if (item == ref)
            return NULL;
        else
        {
            t = new TreeNode(item);
            t1 = Create();
            t->left = t1;
            t2 = Create();
            t->right = t2;
            return t;
        }
    }

    void level(TreeNode *head)
    {
        queue<TreeNode *> Q;
        Q.push(head);
        while (!Q.empty())
        {
            TreeNode *temp = Q.front();
            cout << temp->val << " ";
            Q.pop();

            if (head->left != NULL)
                Q.push(head->left);
            if (head->right != NULL)
                Q.push(head->right);
        }
    }

    
};

int main()
{

    return 0;
}