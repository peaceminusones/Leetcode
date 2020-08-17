#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
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
    TreeNode *buildTree1(vector<int> &preorder, vector<int> &inorder)
    {
        if (preorder.empty() || inorder.empty())
            return NULL;

        TreeNode *root = new TreeNode(preorder[0]);
        auto it = find(inorder.begin(), inorder.end(), preorder[0]);
        int length = it - inorder.begin();

        vector<int> preleft(preorder.begin() + 1, preorder.begin() + length + 1);
        vector<int> preright(preorder.begin() + length + 1, preorder.end());
        vector<int> inleft(inorder.begin(), inorder.begin() + length);
        vector<int> inright(inorder.begin() + length + 1, inorder.end());

        root->left = buildTree1(preleft, inleft);
        root->right = buildTree1(preright, inright);
        return root;
    }

    // 方法二，不构造四个数组，用四个指针判断边界
    unordered_map<int, int> map;
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        for (int i = 0; i < inorder.size(); i++)
        {
            map[inorder[i]] = i;
        }

        return mybuildTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }

    TreeNode *mybuildTree(vector<int> &preorder, vector<int> &inorder, int pre_left, int pre_right, int in_left, int in_right)
    {
        if (pre_left > pre_right)
            return NULL;

        TreeNode *root = new TreeNode(preorder[pre_left]);
        int inmid = map[preorder[pre_left]];
        int size_left = inmid - in_left;

        root->left = mybuildTree(preorder, inorder, pre_left + 1, pre_left + size_left, in_left, inmid - 1);
        root->right = mybuildTree(preorder, inorder, pre_left + size_left + 1, pre_right, inmid + 1, in_right);

        return root;
    }
};

int main()
{

    return 0;
}