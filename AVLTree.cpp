#include <iostream>
#include <iomanip>
using namespace std;

/*
    手写AVL树（平衡二叉查找树）
    AVL树，本质上是带了平衡功能的二叉查找树（二叉排序树，二叉搜索树）
    增加和删除可能需要通过一次或多次树旋转来重新平衡这个树
    ==================================================================================================
    平衡二叉搜索树（Self-balancing binary search tree）又被称为AVL树（有别于AVL算法）
    具有以下性质：它是一棵空树或它的左右两个子树的高度差的绝对值不超过1，并且左右两个子树都是一棵平衡二叉树
    ==================================================================================================
    AVL树的旋转类型有4种:
    LL(left-left)旋转、LR(left-right)旋转、RR(right-right)旋转和RL(right-left)旋转。
    ==================================================================================================
    设x代表刚插入AVL树中的结点，设A为离x最近且平衡因子更改为2的祖先节点
    LL旋转：当x位于A的左子树的左子树上时，执行LL旋转
    LR旋转：x位于A的左子树的右子树上时，执行LR旋转
    RR旋转：当x位于A的右子树的右子树上时，执行RR旋转
    RL旋转：当x位于A的右子树的左子树上时，执行RL旋转
*/

/*
        LL旋转（左左）
        x表示刚插入AVL树中的节点，设t为离x最近且平衡因子更改为2的祖先节点
        当x位于t的左子树的左子树上时：
        1、将t的左指针指向t->left(k)的右子节点
        2、t->left(k)的右指针指向t
        3、将原来指向t的指针指向t->left(k)
    */

struct TreeNode
{
    int val;
    int height; // 以此节点为根的树高
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), height(0), left(NULL), right(NULL) {}
};

class AVLTree
{
    TreeNode *root;

public:
    // 构造函数
    AVLTree();
    // 析构函数
    ~AVLTree();
    // 获取树的高度
    int Height();
    // 比较两个数的大小
    int max(int a, int b);

    // 前序遍历“AVL树”
    void preOrder();
    // 中序遍历“AVL树”
    void inOrder();
    // 后序遍历“AVL树”
    void postOrder();

    // 查找AVL树中键值为key的节点（递归实现）
    TreeNode *search(int key);
    // 查找AVL树中键值为key的节点（非递归实现，即迭代）
    TreeNode *search_iterate(int key);

    // 查找最小结点：返回最小结点的键值
    int minimum();
    // 查找最大结点：返回最大结点的键值
    int maximum();

    // 将节点（值为key）插入到AVL树中
    void insert(int key);
    // 删除节点（值为key）
    void remove(int key);

    // 销毁AVL树
    void destroy();
    // 打印AVL树
    void print();

private:
    // 获取树的高度（以节点node为根）
    int Height(TreeNode *node);
    // 前序遍历“AVL树”（以节点node为根）
    void preOrder(TreeNode *node);
    // 中序遍历“AVL树”（以节点node为根）
    void inOrder(TreeNode *node);
    // 后序遍历“AVL树”（以节点node为根）
    void postOrder(TreeNode *node);
    // 查找AVL树中键值为key的节点（递归实现）（以节点node为根）
    TreeNode *search(TreeNode *node, int key);
    // 查找AVL树中键值为key的节点（非递归实现，即迭代）（以节点node为根）
    TreeNode *search_iterate(TreeNode *node, int key);
    // 查找最小结点：返回最小结点的键值（以节点node为根）
    TreeNode *minimum(TreeNode *node);
    // 查找最大结点：返回最大结点的键值（以节点node为根）
    TreeNode *maximum(TreeNode *node);

    // LL：左左（左单旋转）
    TreeNode *rotate_LL(TreeNode *k2);
    // RR：右右（右单旋转）
    TreeNode *rotate_RR(TreeNode *k1);
    // LR：左右（左双情况）
    TreeNode *rotate_LR(TreeNode *k3);
    // RL：右左（右双情况）
    TreeNode *rotate_RL(TreeNode *k1);

    // 将节点插入到AVL树中
    TreeNode *insert(TreeNode *&tree, int key);
    // 删除AVL树中的节点，并返回被删除的节点
    TreeNode *remove(TreeNode *&tree, TreeNode *t);

    // 销毁AVL树
    void destroy(TreeNode *&tree);
    // 打印AVL树
    void print(TreeNode *tree, int key, int direction);
};

// 构造函数
AVLTree::AVLTree() : root(NULL) {}

// 析构函数
AVLTree::~AVLTree()
{
    destroy(root);
}

// 获取树的高度
int AVLTree::Height()
{
    return Height(root);
}
int AVLTree::Height(TreeNode *node)
{
    if (node != NULL)
        return node->height;
    return 0;
}

// 比较两个数的大小
int AVLTree::max(int a, int b)
{
    return a > b ? a : b;
}

// 前序遍历
void AVLTree::preOrder()
{
    return preOrder(root);
}
void AVLTree::preOrder(TreeNode *node)
{
    if (node)
    {
        cout << node->val << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

// 中序遍历
void AVLTree::inOrder()
{
    return inOrder(root);
}
void AVLTree::inOrder(TreeNode *node)
{
    if (node)
    {
        inOrder(node->left);
        cout << node->val << " ";
        inOrder(node->right);
    }
}

// 后序遍历
void AVLTree::postOrder()
{
    return postOrder(root);
}
void AVLTree::postOrder(TreeNode *node)
{
    if (node)
    {
        postOrder(node->left);
        postOrder(node->right);
        cout << node->val << " ";
    }
}

// 查找AVL树中键值为key的节点（递归实现）
TreeNode *AVLTree::search(int key)
{
    return search(root, key);
}
TreeNode *AVLTree::search(TreeNode *node, int key)
{
    if (node == NULL || node->val == key)
        return node;

    if (key < node->val)
        return search(node->left, key);
    else
        return search(node->right, key);
}

// 查找AVL树中键值为key的节点（非递归实现）
TreeNode *AVLTree::search_iterate(int key)
{
    return search_iterate(root, key);
}
TreeNode *AVLTree::search_iterate(TreeNode *node, int key)
{
    while (node != NULL && node->val != key)
    {
        if (key < node->val)
            node = node->left;
        else
            node = node->right;
    }
    return node;
}

// 查找最小结点：返回最小结点的键值
int AVLTree::minimum()
{
    TreeNode *p = minimum(root);
    if (p)
        return p->val;
    return (int)NULL;
}
TreeNode *AVLTree::minimum(TreeNode *node)
{
    if (node == NULL)
        return NULL;

    while (node->left)
        node = node->left;
    return node;
}

// 查找最大结点：返回最大结点的键值
int AVLTree::maximum()
{
    TreeNode *p = maximum(root);
    if (p)
        return p->val;
    return (int)NULL;
}
TreeNode *AVLTree::maximum(TreeNode *node)
{
    if (node == NULL)
        return NULL;

    while (node->right)
        node = node->right;
    return node;
}

// LL旋转
TreeNode *AVLTree::rotate_LL(TreeNode *k2)
{
    TreeNode *k1 = k2->left;

    // if (k1->right)
    k2->left = k1->right;
    k1->right = k2;

    k2->height = max(Height(k2->left), Height(k2->right)) + 1;
    k1->height = max(Height(k1->left), k2->height) + 1;

    return k1;
}

// RR旋转
TreeNode *AVLTree::rotate_RR(TreeNode *k1)
{
    TreeNode *k2 = k1->right;

    // if (k2->left)
    k1->right = k2->left;
    k2->left = k1;

    k1->height = max(Height(k1->left), Height(k1->right)) + 1;
    k2->height = max(Height(k2->right), k1->height) + 1;

    return k2;
}

// LR旋转
TreeNode *AVLTree::rotate_LR(TreeNode *k3)
{
    // 第一次是围绕k1进行的RR旋转，第二次是围绕k3进行的LL旋转
    k3->left = rotate_RR(k3->left);
    return rotate_LL(k3);
}

// RL旋转
TreeNode *AVLTree::rotate_RL(TreeNode *k1)
{
    // 第一次是围绕k3进行的LL旋转，第二次是围绕K1进行的RR旋转
    k1->right = rotate_LL(k1->right);
    return rotate_RR(k1);
}

/*
    将结点插入到AVL树中，并返回根节点

    参数说明：
        tree：AVL树的根节点
        key：插入结点的键值
    返回值：
        根节点
*/
void AVLTree::insert(int key)
{
    insert(root, key);
}
TreeNode *AVLTree::insert(TreeNode *&tree, int key)
{
    if (tree == NULL)
    {
        tree = new TreeNode(key);
        if (tree == NULL)
        {
            cout << "error: create avltree node failed!" << endl;
            return NULL;
        }
    }
    else if (key < tree->val) // key插入到左子树
    {
        tree->left = insert(tree->left, key);
        // 如果AVL树失去平衡
        if (Height(tree->left) - Height(tree->right) == 2)
        {
            if (key < tree->left->val) // LL
            {
                cout << "LL"
                     << " ";
                tree = rotate_LL(tree);
            }
            else //LR
            {
                cout << "LR"
                     << " ";
                tree = rotate_LR(tree);
            }
        }
    }
    else if (key > tree->val) // 将key插入到tree的右子树
    {
        tree->right = insert(tree->right, key);
        // 如果AVL树失去平衡
        if (Height(tree->right) - Height(tree->left) == 2)
        {
            if (key > tree->right->val) //RR
            {
                cout << "RR"
                     << " ";
                tree = rotate_RR(tree);
            }
            else //RL
            {
                cout << "RL"
                     << " ";
                tree = rotate_RL(tree);
            }
        }
    }
    else
    {
        cout << "add fail: same key node is not permited" << endl;
    }

    tree->height = max(Height(tree->left), Height(tree->right)) + 1;

    return tree;
}

/*
 * 删除节点t，返回根节点
 * 
 * 参数说明：
 *     tree：AVL树的根节点
 *     t：待删除节点
 * 返回值：
 *     根节点
*/
void AVLTree::remove(int key)
{
    TreeNode *t;
    if ((t = search(root, key)) != NULL)
        remove(root, t);
}
TreeNode *AVLTree::remove(TreeNode *&tree, TreeNode *t)
{
    if (tree == NULL || t == NULL)
        return NULL;

    if (t->val < tree->val) // 要删除的节点在左子树
    {
        tree->left = remove(tree->left, t);
        // 如果AVL树失去平衡
        if (Height(tree->right) - Height(tree->left) == 2)
        {
            if (Height(tree->right->left) > Height(tree->right->right)) // RL
                tree = rotate_RL(tree);
            else //RR
                tree = rotate_RR(tree);
        }
    }
    else if (t->val > tree->val) // 要删除的节点在右子树
    {
        tree->right = remove(tree->right, t);
        // 如果AVL树失去平衡
        if (Height(tree->left) - Height(t->right) == 2)
        {
            if (Height(tree->left->left) > Height(tree->left->right)) // LL
                tree = rotate_LL(tree);
            else // LR
                tree = rotate_LR(tree);
        }
    }
    else // tree是对应要删除的节点
    {
        // tree的左右孩子都非空
        if (tree->left != NULL && tree->right != NULL)
        {
            if (Height(tree->left) > Height(tree->right))
            {
                /*
                * 如果tree的左子树比右子树高
                *     找出tree的左子树的值最大值节点
                *     将该最大节点的值赋值为tree
                *     删除该最大节点
                * 类似于用“tree的左子树的最大值节点”做“tree节点”的替身
                * 这种方法的好处是：删除“tree的左子树中最大值节点”之后，AVL树仍然是平衡的
                */
                TreeNode *max = maximum(tree->left);
                tree->val = max->val;
                tree->left = remove(tree->left, max);
            }
            else
            {
                /*
                * 如果tree的左子树不必右子树高（左子树高度等于右子树，或右子树高度比左子树高）
                *     找出tree的右子树的最小值节点
                *     将该最小节点的值赋值为tree
                *     删除该节点
                * 类似于用“tree的有司署的最小值节点”做“tree节点”的替身
                * 这种方法的好处是：删除“tree的右子树中最小值节点”之后，AVL树仍然是平衡的
                */
                TreeNode *min = minimum(tree->right);
                tree->val = min->val;
                tree->right = remove(tree->right, min);
            }
        }
        // // tree的左右孩子有一个为空
        // else if ((tree->left != NULL && tree->right == NULL) || (tree->left == NULL && tree->right != NULL))
        // {
        //     tree = (tree->left != NULL) ? tree->left : tree->right;
        // }
        // // tree节点是叶子节点
        // else if (tree->left == NULL && tree->right == NULL)
        // {
        //     delete tree;
        // }
        else
        {
            TreeNode *tmp = tree;
            tree = (tree->left != NULL) ? tree->left : tree->right;
            delete tmp;
        }
    }
    return tree;
}

// 销毁AVL树
void AVLTree::destroy()
{
    destroy(root);
}
void AVLTree::destroy(TreeNode *&tree)
{
    if (tree == NULL)
        return;

    if (tree->left != NULL)
        destroy(tree->left);
    if (tree->right != NULL)
        destroy(tree->right);

    delete tree;
}

/*
 * 打印“二叉查找树”
 *     key：节点的键值
 *     direction：0---该节点是根节点
 *               -1---该节点是左孩子
 *                1---该节点是右孩子
*/
void AVLTree::print()
{
    if (root != NULL)
        print(root, root->val, 0);
}
void AVLTree::print(TreeNode *tree, int key, int direction)
{
    if (tree != NULL)
    {
        if (direction == 0) // 根节点
            cout << tree->val << " is root" << endl;
        else
            cout << tree->val << " is " << setw(2) << key << "'s " << setw(2) << (direction == 1 ? "right child" : "left child") << endl;

        print(tree->left, tree->val, -1);
        print(tree->right, tree->val, 1);
    }
}

static int arr[] = {3, 2, 1, 4, 5, 6, 7, 16, 15, 14, 13, 12, 11, 10, 8, 9}; //
#define TBL_SIZE(a) (sizeof(a) / (sizeof(a[0])))

// main函数
int main()
{
    AVLTree *tree = new AVLTree();

    cout << "===adding:";
    int ilen = TBL_SIZE(arr);
    for (int i = 0; i < ilen; i++)
    {
        cout << arr[i] << " ";
        tree->insert(arr[i]);
    }
    cout << endl;

    cout << "===preOrder:";
    tree->preOrder();
    cout << endl;

    cout << "===inOrder:";
    tree->inOrder();
    cout << endl;

    cout << "===postOrder:";
    tree->postOrder();
    cout << endl;

    cout << endl;
    cout << "===height:" << tree->Height() << endl;
    cout << "===maximum:" << tree->maximum() << endl;
    cout << "===minimum:" << tree->minimum() << endl;
    cout << "===print tree:" << endl;
    tree->print();

    cout << endl;
    int i = 8;
    cout << "===delete node:" << i;
    tree->remove(i);
    cout << endl;

    cout << "===height:" << tree->Height() << endl;
    cout << "===inOrder:";
    tree->inOrder();
    cout << endl;
    cout << "===print tree:" << endl;
    tree->print();

    tree->destroy();

    return 0;
}