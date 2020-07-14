#include <iostream>
#include <string>
#include <cstring>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
    int refval;

public:
    Solution(int x) : refval(x) {}

    TreeNode *creat()
    {
        TreeNode *t;
        int item;
        cin >> item;
        if (item == refval)
            return NULL;
        else
        {
            t = new TreeNode(item);
            t->left = creat();
            t->right = creat();

            return t;
        }
    }

    void preorder(TreeNode *p)
    {
        if (p)
        {
            cout << p->val << " ";
            preorder(p->left);
            preorder(p->right);
        }
    }

    void SerializeHelper(TreeNode *node, string &s)
    {
        if (node == NULL)
        {
            s.push_back('#');
            return;
        }

        s += to_string(node->val);
        s += '!';

        SerializeHelper(node->left, s);
        SerializeHelper(node->right, s);
    }

    char *Serialize(TreeNode *root) // 序列化 二叉树-->字符串
    {
        if (root == NULL)
            return NULL;
        string s = "";
        SerializeHelper(root, s);

        char *res = new char[s.length() + 1]; // !!!!!!!!!!!!!!!!!!!!!!!!!!!!
        strcpy(res, s.c_str());               // !!!!!!!!!!!!!!!!!!!!!!!!!!!!

        return res;
    }

    TreeNode *DeserializeHelper(string &s)
    {
        if (s.empty())
            return NULL;

        if (s[0] == '#')
        {
            s = s.substr(1); // 删除字符串中这个位置的字符
            return NULL;
        }
        else
        {
            TreeNode *t = new TreeNode(stoi(s));    // 'stoi()':例如s ="1!2!3!"，则stoi(s) = 1
            s = s.substr(s.find_first_of('!') + 1); // s.find_first_of('!'): 找到第一个！的位置，并从下一个位置开始截取字符串

            t->left = DeserializeHelper(s);
            t->right = DeserializeHelper(s);

            return t;
        }
    }

    TreeNode *Deserialize(char *str) // 反序列化 字符串-->二叉树
    {
        if (str == NULL)
            return NULL;

        string s(str);
        return DeserializeHelper(s);
    }
};

int main()
{
    Solution *s = new Solution(0);
    TreeNode *root = s->creat();
    s->preorder(root);
    cout << endl;

    char *res = s->Serialize(root);
    for (int i = 0; i < strlen(res); i++)
        cout << *(res + i);
    cout << endl;

    TreeNode *proot = s->Deserialize(res);
    s->preorder(proot);
    cout << endl;

    return 0;
}