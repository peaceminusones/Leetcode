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
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        if (preorder.empty() || inorder.empty())
            return NULL;

        TreeNode *root = new TreeNode(preorder[0]);
        int mid = 0;
        for (int i = 0; i < inorder.size(); i++)
        {
            if (inorder[i] == preorder[0])
            {
                mid = i;
                break;
            }
        }

        vector<int> preleft(preorder.begin() + 1, preorder.begin() + mid + 1);
        vector<int> preright(preorder.begin() + mid + 1, preorder.end());
        vector<int> inleft(inorder.begin(), inorder.begin() + mid);
        vector<int> inright(inorder.begin() + mid + 1, inorder.end());

        root->left = buildTree(preleft, inleft);
        root->right = buildTree(preright, inright);

        return root;
    }
};

int main()
{
    
    return 0;
}