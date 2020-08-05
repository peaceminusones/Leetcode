#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    /*
     * 迭代法
    */
    ListNode *reverseList(ListNode *head)
    {
        // if (head == NULL || head->next == NULL)
        //     return head;

        // ListNode *prev = NULL;
        // ListNode *p = head;
        // while (p)
        // {
        //     ListNode *temp = p->next; // 先把下一个节点存储下来
        //     p->next = prev;           // 当前节点的指针指向前面
        //     prev = p;                 // 更新prev
        //     p = temp;                 // 更新当前节点
        // }

        // return prev;
        
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *prev = NULL;
        ListNode *cur = head;
        ListNode *p = head;
        while (p)
        {
            p = p->next;
            cur->next = prev; // 当前节点的指针指向前面
            prev = cur;       // 更新prev
            cur = p;          // 更新当前节点
        }

        return prev;
    }
};

int main()
{
    ListNode *head = new ListNode(0);
    ListNode *p = head;
    int item;
    while (cin >> item)
    {
        p->next = new ListNode(item);
        p = p->next;
    }
    head = head->next;

    Solution s;
    ListNode *res = s.reverseList(head);
    while (res)
    {
        cout << res->val << " ";
        res = res->next;
    }

    return 0;
}