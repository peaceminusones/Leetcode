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
    ListNode *FindKthToTail(ListNode *pListHead, unsigned int k)
    {
        if (pListHead == NULL || k == 0)
        {
            return NULL;
        }

        ListNode *p = pListHead;
        while (--k)
        {
            if (p->next)
                p = p->next;
            else
                return NULL;
        }
        
        ListNode *pre = pListHead;
        while (p->next)
        {
            p = p->next;
            pre = pre->next;
        }

        return pre;
    }
};

int main()
{
    ListNode *head = new ListNode(0)
        ListNode *p = head;
    int item;
    while (cin >>)
        return 0;
}
