#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

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
    void inorder(TreeNode *root)
    {
        if (root != NULL)
        {
            inorder(root->left);
            cout << root->val << " ";
            inorder(root->right);
        }
    }

    ListNode *create()
    {
        ListNode *head = new ListNode(0);
        ListNode *p = head;
        int item;
        while (cin >> item)
        {
            p->next = new ListNode(item);
            p = p->next;
        }
        return head->next;
    }

    TreeNode *sortedListToBST(ListNode *head)
    {
        if (head == NULL)
            return NULL;
        return helper(head, NULL);
    }

    // 区间是左闭右开
    TreeNode *helper(ListNode *head, ListNode *tail)
    {
        if (head == tail)
            return NULL;

        // 找到链表的中间节点mid，头节点为head，尾节点为tail ===================
        ListNode *mid = head;
        ListNode *fast = head;
        while (fast != tail && fast->next != tail)
        {
            mid = mid->next;
            fast = fast->next->next;
        }
        // ==================================================================
        TreeNode *root = new TreeNode(mid->val);
        root->left = helper(head, mid);
        root->right = helper(mid->next, tail);

        return root;
    }
};

int main()
{
    Solution s;
    ListNode *head = s.create();

    TreeNode *res = s.sortedListToBST(head);
    s.inorder(res);

    return 0;
}