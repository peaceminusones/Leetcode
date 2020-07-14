#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL){};
};

class Solution
{
public:
    ListNode *EntryNodeOfLoop(ListNode *pHead)
    {
        ListNode *low = pHead, *fast = pHead;

        while (fast && fast->next)
        {
            low = low->next;
            fast = fast->next->next;
            if (low == fast)
                break;
        }

        if (!fast || !fast->next)
            return NULL;

        low = pHead;
        while (low != fast)
        {
            low = low->next;
            fast = fast->next;
        }

        return low;
    }
};

int main()
{
    ListNode *head = new ListNode(0);
    ListNode *p = head;
    int item;
    while (cin >> item)
    {
        ListNode *q = new ListNode(item);
        p->next = q;
        p = p->next;
    }
    head = head->next;

    Solution s;
    ListNode *res = s.EntryNodeOfLoop(head);
    cout << res << endl;

    return 0;
}