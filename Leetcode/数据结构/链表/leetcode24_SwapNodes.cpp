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
    ListNode *swapPairs(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *newhead = new ListNode(0);
        newhead->next = head;

        ListNode *pre = newhead;
        while (pre->next != NULL && pre->next->next != NULL)
        {
            ListNode *first = pre->next;
            ListNode *second = pre->next->next;

            // 外部指针变化
            pre->next = second;
            first->next = second->next;

            // 内部指针变化
            second->next = first;

            // 更新pre
            pre = pre->next->next;
        }
        return newhead->next;
    }

    /*
     * 递归
    */
    ListNode *swapPairs_recu(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *first = head;
        ListNode *second = head->next;

        first->next = swapPairs_recu(second->next);
        second->next = first;

        return second;
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
    ListNode *res = s.swapPairs_recu(head);
    while (res)
    {
        cout << res->val << " ";
        res = res->next;
    }

    return 0;
}