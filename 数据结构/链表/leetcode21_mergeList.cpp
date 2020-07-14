#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *n) : val(x), next(n) {}
};

class Solution
{
public:
    /*
     * 迭代法
    */
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *head = new ListNode(0);
        ListNode *p = head;
        while (l1 && l2)
        {
            if (l1->val <= l2->val)
            {
                p->next = l1;
                p = p->next;
                l1 = l1->next;
            }
            else
            {
                p->next = l2;
                p = p->next;
                l2 = l2->next;
            }
        }

        p->next = (l1 == NULL) ? l2 : l1;

        return head->next;
    }

    /*
     * 递归法
    */
    ListNode *mergeTwoLists_recu(ListNode *l1, ListNode *l2)
    {
        if (l1 == NULL)
            return l2;
        else if (l2 == NULL)
            return l1;
        else if (l1->val <= l2->val)
        {
            l1->next = mergeTwoLists_recu(l1->next, l2);
            return l1; // !!!!!
        }
        else
        {
            l2->next = mergeTwoLists_recu(l1, l2->next);
            return l2; // !!!!!
        }
    }
};

int main()
{
    ListNode *head1 = new ListNode(0);
    ListNode *p1 = head1;
    int item;
    while (cin >> item)
    {
        p1->next = new ListNode(item);
        p1 = p1->next;
    }
    head1 = head1->next;
    cin.clear();
    cin.ignore();

    ListNode *head2 = new ListNode(0);
    ListNode *p2 = head2;
    while (cin >> item)
    {
        p2->next = new ListNode(item);
        p2 = p2->next;
    }
    head2 = head2->next;

    Solution s;
    ListNode *res = s.mergeTwoLists_recu(head1, head2);
    while (res)
    {
        cout << res->val << " ";
        res = res->next;
    }

    return 0;
}