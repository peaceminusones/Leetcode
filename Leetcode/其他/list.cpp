#include <iostream>
#include <vector>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Soltuion
{
public:
    ListNode *FindKthToTail(ListNode *pListHead, int k)
    {
        if (pListHead == NULL || k == 0)
            return NULL;
        ListNode *pre = pListHead;
        ListNode *p = pListHead;
        while (k > 1)
        {
            if (p->next != NULL)
            {
                p = p->next;
                k--;
            }
            else
            {
                return NULL;
            }
        }

        while (p->next != NULL)
        {
            pre = pre->next;
            p = p->next;
        }

        return pre;
    }

    ListNode *Merge(ListNode *phead1, ListNode *phead2)
    {
        if (phead1 == NULL && phead2 == NULL)
            return NULL;
        if (phead1 != NULL && phead2 == NULL)
            return phead1;
        if (phead1 == NULL && phead2 != NULL)
            return phead2;

        ListNode *head = new ListNode(0);
        ListNode *p = head;
        while (phead1 && phead2)
        {
            if (phead1->val < phead2->val)
            {
                p->next = phead1;
                phead1 = phead1->next;
                p = p->next;
            }
            else
            {
                p->next = phead2;
                phead2 = phead2->next;
                p = p->next;
            }
        }

        if (phead1 != NULL)
            p->next = phead1;
        if (phead2 != NULL)
            p->next = phead2;

        return head->next;
    }
};

int main()
{
    // ListNode *head = new ListNode(0);
    // ListNode *p = head;
    // int item;
    // while (cin >> item)
    // {
    //     ListNode *l = new ListNode(item);
    //     p->next = l;
    //     p = p->next;
    // }
    // cin.clear();
    // cin.ignore();
    // head = head->next;

    // int k;
    // cin >> k;

    // Soltuion s;
    // ListNode *res = s.FindKthToTail(head, k);
    // cout << res->val << endl;

    ListNode *head1 = new ListNode(0);
    ListNode *p1 = head1;
    int item;
    while (cin >> item)
    {
        ListNode *l = new ListNode(item);
        p1->next = l;
        p1 = p1->next;
    }
    cin.clear();
    cin.ignore();
    head1 = head1->next;

    ListNode *head2 = new ListNode(0);
    ListNode *p2 = head2;
    while (cin >> item)
    {
        ListNode *l = new ListNode(item);
        p2->next = l;
        p2 = p2->next;
    }
    cin.clear();
    cin.ignore();
    head2 = head2->next;

    Soltuion s;
    ListNode *res = s.Merge(head1, head2);
    while (res)
    {
        cout << res->val << " ";
        res = res->next;
    }

    return 0;
}