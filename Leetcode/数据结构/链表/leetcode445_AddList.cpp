#include <iostream>
#include <stack>
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
    /*
     * 如果可以对链表进行翻转
    */
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        l1 = reverseList(l1);
        l2 = reverseList(l2);

        ListNode *head = new ListNode(0);
        ListNode *p = head;
        int add = 0;
        int carry = 0;
        while (l1 && l2)
        {
            add = (l1->val + l2->val + carry) % 10;
            carry = (l1->val + l2->val + carry) / 10;
            p->next = new ListNode(add);
            p = p->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1)
        {
            add = (l1->val + carry) % 10;
            carry = (l1->val + carry) / 10;
            p->next = new ListNode(add);
            p = p->next;
            l1 = l1->next;
        }

        while (l2)
        {
            add = (l2->val + carry) % 10;
            carry = (l2->val + carry) / 10;
            p->next = new ListNode(add);
            p = p->next;
            l2 = l2->next;
        }

        if (carry)
            p->next = new ListNode(carry);

        return reverseList(head->next);
    }

    ListNode *reverseList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *pre = NULL;
        ListNode *cur = head;
        ListNode *next = head;

        while (next)
        {
            next = next->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }

        return pre;
    }

    /*
     * 【进阶】：如果不可以对链表进行翻转
     * 【对于逆序处理应该首先想到栈】！！！！！！！
    */
    ListNode *addTwoNumbers_stack(ListNode *l1, ListNode *l2)
    {
        stack<int> s1;
        stack<int> s2;
        while (l1)
        {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2)
        {
            s2.push(l2->val);
            l2 = l2->next;
        }

        int carry = 0;
        ListNode *head = NULL;
        while (!s1.empty() || !s2.empty() || carry != 0)
        {
            int a = (!s1.empty()) ? s1.top() : 0;
            int b = (!s2.empty()) ? s2.top() : 0;
            if (!s1.empty())
                s1.pop();
            if (!s2.empty())
                s2.pop();
            int cur = a + b + carry;
            carry = cur / 10;
            cur = cur % 10;
            ListNode *newnode = new ListNode(cur);
            newnode->next = head;
            head = newnode;
        }
        return head;
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
    ListNode *res = s.addTwoNumbers_stack(head1, head2);
    while (res)
    {
        cout << res->val << " ";
        res = res->next;
    }
    return 0;
}