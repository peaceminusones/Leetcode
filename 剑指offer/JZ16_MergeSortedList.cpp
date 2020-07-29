#include <iostream>
#include <vector>
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
    ListNode *Merge(ListNode *pHead1, ListNode *pHead2)
    {
        if (pHead1 == NULL)
            return pHead2;
        if (pHead2 == NULL)
            return pHead1;
        
        ListNode *head = new ListNode(0);
        ListNode *p = head;
        while (pHead1 && pHead2)
        {
            if (pHead1->val <= pHead2->val)
            {
                p->next = pHead1;
                pHead1 = pHead1->next;
            }
            else
            {
                p->next = pHead2;
                pHead2 = pHead2->next;
            }
            p = p->next;
        }

        if (pHead1)
            p->next = pHead1;

        if (pHead2)
            p->next = pHead2;

        return head->next;
    }
};

int main()
{

    return 0;
}
