#include <iostream>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;
    TreeNode() : left(NULL), right(NULL) {}
    TreeNode(T x, TreeNode<T> *l = NULL, TreeNode<T> *r = NULL) : val(x), left(l), right(r) {}
};

template <typename T>
class BinaryTree
{
private:
    TreeNode<T> *root;
    T Refvalue; //数据输入停止的标志，需要一个构造函数

public:
    BinaryTree() : root(NULL) {}
    BinaryTree(T ref, TreeNode<T> *r = NULL) : root(r), Refvalue(ref) {}
    TreeNode<T> *Create();
    void PreOrder(TreeNode<T> *t);
    void Mirror(TreeNode<T> *pRoot);
};

template <typename T>
TreeNode<T> *BinaryTree<T>::Create()
{
    if (root = NULL)
        return NULL;
    TreeNode<T> *t, *t1, *t2;
    T item;
    cin >> item;
    if (item == Refvalue)
        return NULL;
    else
    {
        t = new TreeNode<T>(item, NULL, NULL);
        if (!t)
            return NULL;
        t1 = Create();
        t->left = t1;
        t2 = Create();
        t->right = t2;
        return t;
    }
}

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

template <typename T>
void BinaryTree<T>::Mirror(TreeNode<T> *pRoot)
{
    TreeNode<T> *t;
    if (pRoot != NULL)
    {
        t = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = t;
        Mirror(pRoot->left);
        Mirror(pRoot->right);
    }
}

int main()
{
    BinaryTree<char> *tree = new BinaryTree<char>('#');
    TreeNode<char> *t = tree->Create();
    tree->Mirror(t);
    tree->PreOrder(t);
    return 0;
}