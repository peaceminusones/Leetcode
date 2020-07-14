/*
    offer 14 -----------------------------------------------
*/

#include <iostream>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *FindKthToTail(ListNode *pListHead, unsigned int k)
    {
        if (pListHead == NULL || k == 0)
        {
            return NULL;
        }
        ListNode *pre = pListHead, *p = pListHead;
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

    ListNode *ReverseList(ListNode *pHead)
    {
        if (pHead == NULL)
        {
            return NULL;
        }
        ListNode *p = pHead;
        ListNode *prev = NULL;
        ListNode *pprev = NULL;
        while (p->next)
        {
            pprev = prev;
            prev = p;
            p = p->next;  // 每个指针都往后移动一步
            prev->next = pprev;  // prev指针指向pprev
        }
        p->next = prev;
        return p;
    }

    ListNode *Merge(ListNode *pHead1, ListNode *pHead2)
    {
        if (pHead1 == NULL && pHead2 == NULL)
            return NULL;
        if (pHead1 != NULL && pHead2 == NULL)
            return pHead1;
        if (pHead1 == NULL && pHead2 != NULL)
            return pHead2;

        ListNode *temp = new ListNode(0);
        ListNode *p = temp;
        while (pHead1 && pHead2)
        {
            if (pHead1->val < pHead2->val)
            {
                temp->next = pHead1;
                pHead1 = pHead1->next;
            }
            else
            {
                temp->next = pHead2;
                pHead2 = pHead2->next;
            }
            temp = temp->next;
        }
        if (pHead1 != NULL)
        {
            temp->next = pHead1;
        }
        if (pHead2 != NULL)
        {
            temp->next = pHead2;
        }
        return p->next;
    }

    ListNode *Merge_recur(ListNode *pHead1, ListNode *pHead2)
    {
        if (pHead1 == NULL && pHead2 == NULL)
            return NULL;
        if (pHead1 != NULL && pHead2 == NULL)
            return pHead1;
        if (pHead1 == NULL && pHead2 != NULL)
            return pHead2;

        if (pHead1->val < pHead2->val)
        {
            pHead1->next = Merge_recur(pHead1, pHead2->next);
            return pHead1;
        }
        else
        {
            pHead1->next = Merge_recur(pHead1->next, pHead2);
            return pHead2;
        }
    }
};

int main()
{
    // int num;
    // ListNode *head = new ListNode(0);
    // ListNode *p = head;
    // while (cin >> num)
    // {
    //     ListNode *q = new ListNode(num);
    //     p->next = q;
    //     p = p->next;
    // }
    // cin.clear();
    // cin.ignore();
    // head = head->next;

    // Solution s;
    // int k;
    // cin >> k;
    // cout << "k = " << k << endl;

    // ListNode *p1;
    // p1 = s.FindKthToTail(head, k);
    // cout << *&p1->val << endl;

    // ListNode *p2;
    // p2 = s.ReverseList(head);
    // cout << *&p2->val << endl;

    // ListNode *m = head;
    // while (m != nullptr)
    // {
    //     cout << m->val << " ";
    //     m = m->next;
    // }

    int num1;
    ListNode *head1 = new ListNode(0);
    ListNode *p1 = head1;
    while (cin >> num1)
    {
        ListNode *q1 = new ListNode(num1);
        p1->next = q1;
        p1 = p1->next;
    }
    cin.clear();
    cin.ignore();
    head1 = head1->next;

    int num2;
    ListNode *head2 = new ListNode(0);
    ListNode *p2 = head2;
    while (cin >> num2)
    {
        ListNode *q2 = new ListNode(num2);
        p2->next = q2;
        p2 = p2->next;
    }
    cin.clear();
    cin.ignore();
    head2 = head2->next;
    
    Solution s;
    ListNode *p;
    p = s.Merge_recur(head1, head2);
    
    while (p != nullptr)
    {
        cout << *&p->val << " ";
        p = p->next;
    }

    return 0;
}