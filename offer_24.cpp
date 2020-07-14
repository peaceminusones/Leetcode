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

class BinaryTree
{
private:
    TreeNode *root;
    int refvalue;

public:
    BinaryTree(int r) : refvalue(r), root(NULL) {}

    TreeNode *Create()
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

    void Preordor(TreeNode *t)
    {
        if (t != NULL)
        {
            cout << t->val << " ";
            Preordor(t->left);
            Preordor(t->right);
        }
    }

    /*
    递归方法==========================================================
    1.递归先序遍历树， 把结点加入路径。
    2.若该结点是叶子结点则比较当前路径和是否等于期待和。
    3.弹出结点，每一轮递归返回到父结点时，当前路径也应该回退一个结点
    */
    vector<vector<int>> FindPath(TreeNode *root, int expectNumber)
    {
        vector<vector<int>> res;
        vector<int> trace;
        if (root)
            dfs(root, expectNumber, res, trace);
        return res;
    }

    void dfs(TreeNode *root, int expectNumber, vector<vector<int>> &res, vector<int> &trace)
    {
        // 不管在FindPath还是在dfs中都对root是否为NULL进行了判断
        // 所以可以直接push
        trace.push_back(root->val);
        // 当前结点是叶子节点，且最后一个结点的值等于expectNumber
        if (root->left == NULL && root->right == NULL)
        {
            if (expectNumber == root->val)
                //将该路径加入res结果集中
                res.push_back(trace);
        }
        //如果左子树非空，递归左子树
        if (root->left)
        {
            dfs(root->left, expectNumber - root->val, res, trace);
            trace.pop_back();
        }
        //如果右子树非空，递归右子树
        if (root->right)
        {
            dfs(root->right, expectNumber - root->val, res, trace);
            trace.pop_back();
        }
        // 无论当前路径是否加出了target，必须去掉最后一个，
        // 然后返回父节点，去查找另一条路径，最终的trace肯定为null
    }
    /*
    =================================================================
    */

    /*
   非递归方法=========================================================
   思路：
    1.按先序遍历把当前节点cur的左孩子依次入栈同时保存当前节点，
    每次更新当前路径的和sum；
    2.判断当前节点是否是叶子节点以及sum是否等于expectNumber，
    如果是，把当前路径放入结果中。
    3.遇到叶子节点cur更新为NULL，此时看栈顶元素，如果栈顶元素的把栈顶元素
    保存在last变量中，同时弹出栈顶元素，当期路径中栈顶元素弹出，sum减掉栈顶元素，
    这一步骤不更改cur的值；
    4.如果步骤3中的栈顶元素的右孩子存在且右孩子之前没有遍历过，当前节点cur更新
    为栈顶的右孩子，此时改变cur=NULL的情况。
   */

    vector<vector<int>> nonrecur_FindPath(TreeNode *root, int expectNumber)
    {
        vector<vector<int>> res;
        if (root == NULL)
            return res;
        stack<TreeNode *> s;
        s.push(root);
        int cur_sum = 0;       //当前和
        vector<int> cur_path;  //当前路径
        TreeNode *cur = root;  //当前结点
        TreeNode *last = NULL; //保存上一个结点
        while (!s.empty())
        {
            if (cur == NULL) // 当前结点为NULL
            {
                TreeNode *temp = s.top();
                // 如果右子树不为空且没有遍历
                if (temp->right != NULL && temp->right != last)
                    // 转向未遍历过的右子树
                    cur = temp->right;
                else
                {
                    // 如果右子树为空，或者上一个结点时右子树结点
                    last = temp; // 保存上一个已遍历的结点
                    s.pop();
                    cur_path.pop_back(); // 从当前路径删除
                    cur_sum -= temp->val;
                }
            }
            else
            {
                // 当前结点不为NULL，压入栈
                s.push(cur);
                cur_sum += cur->val;
                cur_path.push_back(cur->val);
                // 如果值的和等于expectNumber且到达了叶子结点
                // 把该路径存下来
                if (cur_sum == expectNumber && cur->left == NULL && cur->right == NULL)
                    res.push_back(cur_path);

                // 先序遍历，左子树先于右子树
                cur = cur->left;
            }
        }
        return res;
    }
};

int main()
{
    BinaryTree *tree = new BinaryTree(0);
    TreeNode *t = tree->Create();
    tree->Preordor(t);
    cout << endl;

    cout << "method 1: " << endl;
    vector<vector<int>> res1 = tree->FindPath(t, 9);
    for (int i = 0; i < res1.size(); i++)
    {
        for (int j = 0; j < res1[0].size(); j++)
            cout << res1[i][j] << " ";
        cout << endl;
    }
    
    cout << "method 2: " << endl;
    vector<vector<int>> res2 = tree->nonrecur_FindPath(t, 9);
    for (int i = 0; i < res2.size(); i++)
    {
        for (int j = 0; j < res2[0].size(); j++)
            cout << res2[i][j] << " ";
        cout << endl;
    }
}