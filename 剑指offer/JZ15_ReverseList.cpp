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
    ListNode *ReverseList(ListNode *pHead)
    {
        if (pHead == NULL || pHead->next == NULL)
            return pHead;

        ListNode *pre = NULL;
        ListNode *cur = pHead;
        ListNode *p = pHead;

        while (p)
        {
            p = p->next;
            cur->next = pre;
            pre = cur;
            cur = p;
        }
        return pre;
    }
};

int main()
{

    return 0;
}
