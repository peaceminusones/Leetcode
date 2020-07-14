#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// offer 22 ================================================

// struct TreeNode
// {
//     int val;
//     struct TreeNode *left;
//     struct TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

// class Solution
// {
// private:
//     TreeNode *root;
//     int refvalue;

// public:
//     Solution() : root(NULL) {}
//     Solution(int r) : refvalue(r), root(NULL) {}
//     TreeNode *Create()
//     {
//         TreeNode *t, *t1, *t2;
//         int item;
//         cin >> item;
//         if (item == refvalue)
//             return NULL;
//         else
//         {
//             t = new TreeNode(item);
//             t1 = Create();
//             t->left = t1;
//             t2 = Create();
//             t->right = t2;
//             return t;
//         }
//     }

//     vector<int> PrintFromTopToBottom(TreeNode *root)
//     {
//         vector<int> results;
//         if (root == NULL)
//             return results;
//         queue<TreeNode *> q;
//         TreeNode *t;
//         q.push(root);
//         while (!q.empty())
//         {
//             t = q.front();
//             q.pop();
//             results.push_back(t->val);

//             if (t->left != NULL)
//                 q.push(t->left);
//             if (t->right != NULL)
//                 q.push(t->right);
//         }
//         return results;
//     }
// };

// int main()
// {
//     Solution *s = new Solution(-1);
//     TreeNode *t = s->Create();
//     vector<int> r = s->PrintFromTopToBottom(t);
//     for (int i = 0; i < r.size(); i++)
//         cout << r[i] << " ";
//     return 0;
// }

// offer 23 ============================================

class TreeNode // 树结点结构
{
public:
    TreeNode *right;
    TreeNode *left;
    int val;
    TreeNode(int r) : val(r), left(NULL), right(NULL) {}
};

class BinaryTree // 二叉树结构
{
private:
    TreeNode *root; // 根结点
    int refvalue;   //停止条件

public:
    BinaryTree(int ref) : refvalue(ref), root(NULL) {}
    TreeNode *Create() // 创建二叉树
    {
        TreeNode *t, *t1, *t2;
        int item;
        cin >> item;
        if (item == refvalue)
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

    vector<int> PostOrdor(TreeNode *t) // 非递归后序遍历
    {
        vector<int> res; //存储后续遍历结果
        if (t == NULL)
            return res;

        stack<TreeNode *> s; // 存储树的结点
        s.push(t);
        TreeNode *lastpop = NULL; // 记录上次pop的结点
        while (!s.empty())
        {
            while (s.top()->left != NULL) //如果栈顶结点的左子树不空，则压入栈中
                s.push(s.top()->left);

            while (!s.empty())
            {
                if (lastpop == s.top()->right || s.top()->right == NULL)
                {
                    // 如果上次pop的是当前栈顶结点的右子树
                    // 或是当前栈顶结点的右子树为空
                    // 记录当前栈顶结点的值，并出栈，修改lastpop
                    res.push_back(s.top()->val);
                    lastpop = s.top();
                    s.pop();
                }
                else if (s.top()->right != NULL)
                {
                    // 如果当前栈顶结点的右子树不空，则压入栈中
                    // 然后跳出循环，把这个右子树根结点的左结点压入栈中
                    s.push(s.top()->right);
                    break;
                }
            }
        }
        return res;
    }

    bool judge(vector<int> &a, int l, int r)
    {
        // 后序遍历的最后一个结点时树的根结点
        if (l >= r)
            return true;
        int mid = l;
        while (mid < r && a[mid++] < a[r]); // 找到比根节点小的
        int back = mid;
        while (back < r && a[back++] > a[r]); //找到比根结点大的
        if (back < r) // 没有到达根结点
            return false;
        if (mid == l) // 没有比根结点小的
            return judge(a, l, r - 1);
        else // 有比根节点小的结点
            return (judge(a, l, mid - 1) && judge(a, mid, r - 1));
    }

    bool VerifySquenceOfBST(vector<int> sequence)
    {
        if (sequence.size() == 0)
            return false;
        return judge(sequence, 0, sequence.size() - 1);
    }
};

int main()
{
    BinaryTree *tree = new BinaryTree(0);
    TreeNode *t = tree->Create();
    vector<int> m = tree->PostOrdor(t);
    for (int i = 0; i < m.size(); i++)
        cout << m[i] << " ";
    cout << endl;
    bool results = tree->VerifySquenceOfBST(m);
    cout << results << endl;
}