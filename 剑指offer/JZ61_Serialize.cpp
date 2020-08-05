#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <string.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;  // 左节点
    TreeNode *right; // 右节点
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
    int refval;

public:
    Solution(int x) : refval(x) {}

    TreeNode *create()
    {
        int item;
        cin >> item;
        if (item == refval)
            return NULL;
        else
        {
            TreeNode *t = new TreeNode(item);
            t->left = create();
            t->right = create();
            return t;
        }
    }

    char *Serialize(TreeNode *root) // 序列化 二叉树-->字符串
    {
        if (root == NULL)
            return NULL;
        string s = "";
        SerializeHelper(root, s);

        char *res = new char(s.size() + 1);
        strcpy(res, s.c_str());
        return res;
    }

    void SerializeHelper(TreeNode *root, string &s)
    {
        if (root == NULL)
        {
            s.push_back('#');
            return;
        }

        s += to_string(root->val);
        s += '!';

        SerializeHelper(root->left, s);
        SerializeHelper(root->right, s);
    }

    TreeNode *Deserialize(char *str) // 反序列化 字符串-->二叉树
    {
        if (str == NULL)
            return NULL;

        string s(str);

        return DeserializeHelper(s);
    }

    TreeNode *DeserializeHelper(string s)
    {
        if (s.empty())
            return NULL;

        if (s[0] == '#')
        {
            s.substr(1);
            return NULL;
        }
        else
        {
            TreeNode *t = new TreeNode(stoi(s));
            s = s.substr(s.find_first_of('!') + 1);

            t->left = DeserializeHelper(s);
            t->right = DeserializeHelper(s);
            return t;
        }
    }
};

int main()
{
    Solution s(0);
    char *str = new char(20);
    cin >> str;
    TreeNode *root = s.Deserialize(str);
    str = s.Serialize(root);

    string st(str);
    cout << st << endl;

    return 0;
}