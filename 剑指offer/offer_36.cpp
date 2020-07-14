#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2)
    {
        ListNode *p1 = pHead1;
        ListNode *p2 = pHead2;
        while (p1 != p2)
        {
            if (p1 != NULL)
                p1 = p1->next;
            if (p2 != NULL)
                p2 = p2->next;
            if (p1 != p2)
            {
                if (p1 == NULL)
                    p1 = pHead2;
                if (p2 == NULL)
                    p2 = pHead1;
            }
        }
        return p1;
    }
};

int main()
{
    int item;
    ListNode *head1 = new ListNode(0);
    ListNode *p1 = head1;
    while (cin >> item)
    {
        ListNode *node = new ListNode(item);
        p1->next = node;
        p1 = p1->next;
    }
    cin.clear();
    cin.ignore();

    head1 = head1->next;

    ListNode *head2 = new ListNode(0);
    ListNode *p2 = head2;
    while (cin >> item)
    {
        ListNode *node = new ListNode(item);
        p2->next = node;
        p2 = p2->next;
    }
    cin.clear();
    cin.ignore();
    head2 = head2->next;

    ListNode *head3 = new ListNode(0);
    ListNode *p3 = head3;
    while (cin >> item)
    {
        ListNode *node = new ListNode(item);
        p3->next = node;
        p3 = p3->next;
    }
    cin.clear();
    cin.ignore();
    head3 = head3->next;

    p1->next = head3;
    p2->next = head3;

    // ListNode *p = head1;
    // while (p)
    // {
    //     cout << p->val << " ";
    //     p = p->next;
    // }
    // cout << endl;
    // p = head2;
    // while (p)
    // {
    //     cout << p->val << " ";
    //     p = p->next;
    // }
    // cout << endl;

    Solution s;
    ListNode *res = s.FindFirstCommonNode(head1, head2);
    cout << res->val << endl;

    return 0;
}