#include <iostream>
#include <vector>
#include <cstring>
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
    TreeNode *root;

public:
    TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin)
    {
        if (pre.size() == 0 || vin.size() == 0)
            return NULL;

        TreeNode *root = new TreeNode(pre[0]);
        int mid = 0;
        for (int i = 0; i < vin.size(); i++)
        {
            if (vin[i] == root->val)
            {
                mid = i;
                break;
            }
        }

        vector<int> preleft(pre.begin() + 1, pre.begin() + mid + 1);
        vector<int> prerigh(pre.begin() + mid + 1, pre.end());
        vector<int> vinleft(vin.begin(), vin.begin() + mid);
        vector<int> vinright(vin.begin() + mid + 1, vin.end());
        root->left = reConstructBinaryTree(preleft, vinleft);
        root->right = reConstructBinaryTree(prerigh, vinright);

        return root;
    }

    void preorder(TreeNode *head)
    {
        if (head)
        {
            cout << head->val << " ";
            preorder(head->left);
            preorder(head->right);
        }
    }
};

int main()
{
    vector<int> pre;
    int item;
    while (cin >> item)
    {
        pre.push_back(item);
        if (cin.get() == '\n')
            break;
    }
    vector<int> vin;
    while (cin >> item)
    {
        vin.push_back(item);
        if (cin.get() == '\n')
            break;
    }

    Solution s;
    TreeNode *root = s.reConstructBinaryTree(pre, vin);
    s.preorder(root);
    return 0;
}