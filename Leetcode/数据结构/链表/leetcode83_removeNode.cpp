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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *pre = head;
        ListNode *p = head->next;
        while (p)
        {
            if (p->val == pre->val)
                p = p->next;
            else
            {
                pre->next = p;
                pre = p;
                p = p->next;
            }
        }
        pre->next = p;
        return head;
    }
};

int main()
{
    ListNode *head = new ListNode(0);
    ListNode *p = head;
    int item;
    while (cin >> item)
    {
        ListNode *tmp = new ListNode(item);
        p->next = tmp;
        p = p->next;
    }
    head = head->next;

    Solution s;
    ListNode *res = s.deleteDuplicates(head);
    while (res)
    {
        cout << res->val << " ";
        res = res->next;
    }
    return 0;
}