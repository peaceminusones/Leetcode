#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int count = 0;
    void leavesNumber(vector<int> &pre, vector<int> &in)
    {
        if (pre.empty() || in.empty())
            return;

        if (pre.size() == 1 || in.size() == 1)
        {
            count++;
            return;
        }

        int rooti = pre[0];
        auto it = find(in.begin(), in.end(), rooti);
        int left = it - in.begin();

        vector<int> preleft(pre.begin() + 1, pre.begin() + 1 + left);
        vector<int> preright(pre.begin() + 1 + left, pre.end());
        vector<int> inleft(in.begin(), it);
        vector<int> inright(it + 1, in.end());

        leavesNumber(preleft, inleft);
        leavesNumber(preright, inright);
    }
};

int main()
{
    int n;
    cin >> n;
    int item;
    vector<int> pre;
    for (int i = 0; i < n; i++)
    {
        cin >> item;
        pre.push_back(item);
    }
    vector<int> in;
    for (int i = 0; i < n; i++)
    {
        cin >> item;
        in.push_back(item);
    }

    Solution s;
    s.leavesNumber(pre, in);
    cout << s.count << endl;
    return 0;
}

// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

// TreeNode *leavesNumber1(vector<int> pre, vector<int> in)
// {
//     if (pre.empty() || in.empty())
//     {
//         return NULL;
//     }
//     if (pre.size() == 1 || in.size() == 1)
//     {
//         count++;
//     }

//     int rooti = pre[0];
//     auto it = find(in.begin(), in.end(), rooti);
//     int left = it - in.begin();

//     vector<int> preleft(pre.begin() + 1, pre.begin() + 1 + left);
//     vector<int> preright(pre.begin() + 1 + left, pre.end());
//     vector<int> inleft(in.begin(), it);
//     vector<int> inright(it + 1, in.end());
//     TreeNode *root = new TreeNode(pre[0]);
//     root->left = leavesNumber1(preleft, inleft);
//     root->right = leavesNumber1(preright, inright);
//     return root;
// }

// void preorder(TreeNode *root)
// {
//     if (root)
//     {
//         cout << root->val << " ";
//         preorder(root->left);
//         preorder(root->right);
//     }
// }