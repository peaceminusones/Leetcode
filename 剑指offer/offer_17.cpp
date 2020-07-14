#include <iostream>
#include <stack> // 栈
#include <queue> // 队列
using namespace std;

template <typename T>
class TreeNode
{
public:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;
    // 无参构造函数
    TreeNode() : left(NULL), right(NULL) {}
    // 带默认值的有参构造参数
    TreeNode(T x, TreeNode<T> *l = NULL, TreeNode<T> *r = NULL) : val(x), left(l), right(r) {}
};

template <typename T>
class BinaryTree
{
private:
    TreeNode<T> *root; //根节点
    T RefValue;        //数据输入停止的标志，需要一个构造函数
public:
    //==========二叉树构造与析构==========//
    // 构造函数
    BinaryTree() : root(NULL) {}
    // 指定结束标志的构造函数
    BinaryTree(T value) : RefValue(value), root(NULL) {}
    // 析构函数
    ~BinaryTree() { Destroy(root); }
    //==========二叉树的创建==========//
    // 创建二叉树
    // void CreateBinTree();
    // 创建一棵二叉树并返回该二叉树的根结点
    TreeNode<T> *Create();
    // 销毁函数
    void Destroy(TreeNode<T> *t);
    // 递归先序遍历并输出以结点t为根结点的子树
    void PreOrder(TreeNode<T> *t);
    // 获得根结点
    TreeNode<T> *getroot() { return root; }
    // 非递归先序遍历
    void NorecPreOrder(TreeNode<T> *t);
    // 递归中序遍历并输出以结点t为根结点的子树
    void InOrder(TreeNode<T> *t);
    // 非递归中序遍历并输出以结点t为根结点的子树
    void NorecInOrder(TreeNode<T> *t);
    // 递归后序遍历并输出以结点t为根结点的子树
    void PostOrder(TreeNode<T> *t);
    // 非递归后序遍历并输出以结点t为根结点的子树
    void NorecPostOrder(TreeNode<T> *t);
    // 层次遍历二叉树
    void LevelOrder(TreeNode<T> *t);
};

// 创建一棵二叉树并返回该二叉树的根结点
template <typename T>
TreeNode<T> *BinaryTree<T>::Create()
{
    TreeNode<T> *t, *t1, *t2;
    T item;
    cin >> item;
    if (item == RefValue)
    {
        t = NULL;
        return t;
    }
    else
    {
        if (!(t = new TreeNode<T>(item, NULL, NULL)))
            return NULL;
        t1 = Create();
        t->left = t1;
        t2 = Create();
        t->right = t2;
        return t;
    }
}

template <typename T>
void BinaryTree<T>::Destroy(TreeNode<T> *t)
{
    if (t != NULL)
    {
        Destroy(t->left);
        Destroy(t->right);
        delete t;
        t = NULL;
    }
}

// 递归先序遍历并输出以结点t为根结点的子树
template <typename T>
void BinaryTree<T>::PreOrder(TreeNode<T> *t)
{
    if (t != NULL)
    {
        cout << t->val << " ";
        PreOrder(t->left);
        PreOrder(t->right);
    }
}

// 非递归先序遍历并输出以结点t为根结点的子树
template <typename T>
void BinaryTree<T>::NorecPreOrder(TreeNode<T> *t)
{
    if (t == NULL)
        return;
    stack<TreeNode<T> *> s;
    while (t != NULL || !s.empty())
    {
        while (t != NULL)
        {
            s.push(t);
            cout << t->val << " ";
            t = t->left;
        }
        if (s.empty())
            return;
        t = s.top();
        s.pop();
        t = t->right;
    }
}

// 递归中序遍历并输出以结点t为根结点的子树
template <typename T>
void BinaryTree<T>::InOrder(TreeNode<T> *t)
{
    if (t != NULL)
    {
        InOrder(t->left);
        cout << t->val << " ";
        InOrder(t->right);
    }
}

// 非递归中序遍历并输出以结点t为根结点的子树
template <typename T>
void BinaryTree<T>::NorecInOrder(TreeNode<T> *t)
{
    if (t == NULL)
        return;
    stack<TreeNode<T> *> s;
    while (!(t == NULL) || !s.empty())
    {
        while (t != NULL)
        {
            s.push(t); // 一路把左孩子压入栈中
            t = t->left;
        }
        if (s.empty())
            return;
        // 拿出栈顶元素，输出值，然后指向该节点的右孩子
        // 然后重新进入循环，压入右节点的左孩子
        t = s.top();
        cout << t->val << " ";
        s.pop();
        t = t->right;
    }
}

// 递归后序遍历并输出以结点t为根结点的子树
template <typename T>
void BinaryTree<T>::PostOrder(TreeNode<T> *t)
{
    if (t != NULL)
    {
        PostOrder(t->left);
        PostOrder(t->right);
        cout << t->val << " ";
    }
}

// 非递归后序遍历并输出以结点t为根结点的子树
template <typename T>
void BinaryTree<T>::NorecPostOrder(TreeNode<T> *t)
{
    /*
    1、如果栈顶元素非空且左节点存在,将其压入栈中，如果栈顶元素存在左节点，
    将其左节点压栈，重复该过程。直到左结点不存在则进入第2步
    2、判断上一次出栈节点是否是当前栈顶结点的右节点，
    或者当前栈顶结点不存在右结点，将当前节点输出，并出栈。
    否则将当前栈顶结点右孩子节点压栈，再进入第1步
    */
    if (t == NULL)
        return;
    stack<TreeNode<T> *> s;
    s.push(t);
    TreeNode<T> *lastpop = NULL;
    while (!s.empty())
    {
        while (s.top()->left != NULL)
            s.push(s.top()->left);
        while (!s.empty())
        {
            if (lastpop == s.top()->right || s.top()->right == NULL)
            {
                cout << s.top()->val << " ";
                lastpop = s.top();
                s.pop();
            }
            else if (s.top()->right != NULL)
            {
                s.push(s.top()->right);
                break;
            }
        }
    }
}

// 层次遍历二叉树
template <typename T>
void BinaryTree<T>::LevelOrder(TreeNode<T> *t)
{
    queue<TreeNode<T> *> Q;
    Q.push(t);
    while (!Q.empty())
    {
        t = Q.front();
        Q.pop();
        cout << t->val << " ";

        if (t->left != NULL)
            Q.push(t->left);
        if (t->right != NULL)
            Q.push(t->right);
    }
}

template <typename T>
class Solution
{
public:
    bool HasSubtree(TreeNode<T> *pRoot1, TreeNode<T> *pRoot2)
    {
        if (pRoot1 == NULL || pRoot2 == NULL)
            return false;

        bool results = false;
        if (pRoot1->val == pRoot2->val)
        {
            //根结点相同，判断以该根结点为节点是否包含Tree2
            results = Tree2inTree1(pRoot1, pRoot2);
        }
        if (!results)
        {
            //判断左儿子是否相同
            results = HasSubtree(pRoot1->left, pRoot2);
        }
        if (!results)
        {
            //判断右儿子是否相同
            results = HasSubtree(pRoot1->right, pRoot2);
        }
        return results;
    }

    bool Tree2inTree1(TreeNode<T> *pRoot1, TreeNode<T> *pRoot2)
    {
        if (pRoot2 == NULL)
            // 如果Tree2都遍历完了，说明是子结构
            return true;
        if (pRoot1 == NULL)
            // 如果Tree2还没有遍历完，Tree1确遍历完了，说明不是子结构
            return false;

        // 如果对当前结点对的上，继续道子节点里找
        return ((pRoot1->val == pRoot2->val) && Tree2inTree1(pRoot1->left, pRoot2->left) && Tree2inTree1(pRoot1->right, pRoot2->right));
    }
};

int main()
{
    // BinaryTree<char> *tree1 = new BinaryTree<char>('#');
    // cout << "create tree1:" << endl;
    // TreeNode<char> *t1 = tree1->Create();

    // BinaryTree<char> *tree2 = new BinaryTree<char>('#');
    // cout << "create tree2:" << endl;
    // TreeNode<char> *t2 = tree2->Create();

    // Solution<char> s;
    // bool results = s.HasSubtree(t1, t2);
    // cout << results << endl;


    BinaryTree<int> *tree = new BinaryTree<int>(0);
    cout << "create tree:" << endl;
    TreeNode<int> *t = tree->Create();
    cout << "root val: " << t->val << endl;
    cout << "recursion pre order" << endl;
    tree->PreOrder(t);
    cout << endl;
    // cout << "nonrecursion pre order" << endl;
    // tree->NorecPreOrder(t);
    // cout << endl;
    // cout << "recursion mid order" << endl;
    // tree->InOrder(t);
    // cout << endl;
    // cout << "nonrecursion mid order" << endl;
    // tree->NorecInOrder(t);
    // cout << endl;
    cout << "recursion post order" << endl;
    tree->PostOrder(t);
    // cout << endl;
    // cout << "nonrecursion post order" << endl;
    // tree->NorecPostOrder(t);
    // cout << endl;
    // cout << "level order" << endl;
    // tree->LevelOrder(t);
    return 0;
}

// template <typename T>
// int main()
// {
//     Solution<T> s;
//     TreeNode<T> *pRoot1, *pRoot2;
//     pRoot1 = TreeNode('D', TreeNode('B', TreeNode('A'), TreeNode('C')),
//                       TreeNode('E', right = TreeNode('G', TreeNode('F'))));
//     pRoot2 = TreeNode('D', TreeNode('B'), TreeNode('E'));
//     bool flag = s->HasSubtree(pRoot1, pRoot2);
//     cout << flag << endl;
//     return 0;
// }