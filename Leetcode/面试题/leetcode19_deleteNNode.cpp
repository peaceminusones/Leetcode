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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *left = head;
        ListNode *right = head;
        while ((n + 1) && right)
        {
            right = right->next;
            n--;
        }

        while (right)
        {
            left = left->next;
            right = right->next;
        }

        left->next = left->next->next;
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
        p->next = new ListNode(item);
        p = p->next;
        if (cin.get() == '\n')
            break;
    }
    head = head->next;

    Solution s;
    ListNode *h = s.removeNthFromEnd(head, 3);

    while (h)
    {
        cout << h->val << " ";
        h = h->next;
    }

    return 0;
}