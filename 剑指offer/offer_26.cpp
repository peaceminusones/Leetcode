#include <iostream>
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
    int refval;

public:
    BinaryTree(int r) : refval(r), root(NULL) {}

    TreeNode *Create()
    {
        TreeNode *t, *t1, *t2;
        int item;
        cin >> item;
        if (item == refval)
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

    /*
        二叉搜索树的中序遍历就是从小到大排列的
        中序遍历对节点的访问顺序和转换完链表从左到右的顺序是一样的。
        所以在中序遍历时完成相邻两个节点的互指即可。具体做法是把前
        一个节点记录下来然后pre->right=cur;cur->left=pre。
    */
    TreeNode *Convert(TreeNode *pRootOfTree)
    {
        if (pRootOfTree == NULL)
            return NULL;
        TreeNode *pre = NULL;

        convertInOrder(pRootOfTree, pre);

        TreeNode *res = pRootOfTree;
        while (res->left)
            res = res->left;
        return res;
    }

    // “TreeNode *&pre”是指针引用
    // 其中TreeNode *是个整体，表示变量类型是TreeNode类指针，
    // &pre中的&表明引用实参，即代表实参的一个别名。
    // 操作引用变量就相当于操作实参变量
    void convertInOrder(TreeNode *cur, TreeNode *&pre)
    {
        if (cur == NULL)
            return;

        convertInOrder(cur->left, pre); // 遍历左子树

        cur->left = pre; // 当前结点的左指针指向前结点
        if (pre)         // 如果前结点不是NULL，则把前结点的右指针指向当前节点
            pre->right = cur;
        pre = cur; // 更新前结点指针的位置

        convertInOrder(cur->right, pre); // 遍历右子树
    }

    /*
        中序遍历的非递归方法
    */
    TreeNode *norecConvert(TreeNode *pRootOfTree)
    {
        if (pRootOfTree == NULL)
            return NULL;
        TreeNode *cur = pRootOfTree;
        TreeNode *pre = NULL;
        stack<TreeNode *> s;
        while (cur != NULL || !s.empty())
        {
            while (cur != NULL)
            {
                s.push(cur); // 把左孩子都压入栈中
                cur = cur->left;
            }
            if (s.empty())
                return NULL;

            cur = s.top(); // 取出当前栈顶结点
            s.pop();

            cur->left = pre; // 把当前结点的左指针指向前一个结点
            if (pre)         // 如果前一个结点不是空指针，则也把前一个结点的右指针指向当前结点
                pre->right = cur;
            pre = cur; // 更新pre指针的位置

            cur = cur->right; // 更新cur指针的位置
        }

        TreeNode *t = pRootOfTree;
        while (t->left)
            t = t->left;
        return t;
    }
};

int main()
{
    BinaryTree *tree = new BinaryTree(0);
    TreeNode *t = tree->Create();
    // TreeNode *res = tree->Convert(t);      // 递归方法
    TreeNode *res = tree->norecConvert(t); //非递归方法

    cout << res->val << endl;
    while (res)
    {
        cout << res->val << " ";
        res = res->right;
    }

    return 0;
}