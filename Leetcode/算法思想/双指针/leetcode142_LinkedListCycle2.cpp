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
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast)
        {
            if (fast->next == NULL)
                return NULL;
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow)
                break;
        }
        if (fast == NULL)
            return NULL;

        fast = head;
        while (fast != slow)
        {
            fast = fast->next;
            slow = slow->next;
        }

        return fast;
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
    }
    head = head->next;

    Solution s;
    ListNode *res = s.detectCycle(head);
    cout << res->val << endl;
    return 0;
}