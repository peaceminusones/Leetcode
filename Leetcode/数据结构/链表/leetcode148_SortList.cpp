#include <iostream>
#include <vector>
#include <queue>
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
    // 方法一：小顶堆
    struct cmp
    {
        bool operator()(ListNode *a, ListNode *b)
        {
            return a->val > b->val;
        }
    };
    ListNode *sortList1(ListNode *head)
    {
        priority_queue<ListNode *, vector<ListNode *>, cmp> que;
        while (head)
        {
            // 一定要注意queue push的是一个独立的节点，要有head->next = NULL操作。不然会造成环的存在
            que.push(head);
            ListNode *tmp = head->next;
            head->next = NULL;
            head = tmp;
        }

        ListNode *newhead = new ListNode(0);
        ListNode *p = newhead;
        while (!que.empty())
        {
            ListNode *node = que.top();
            que.pop();
            p->next = node;
            p = p->next;
        }
        return newhead->next;
    }

    // 归并排序
    ListNode *sortList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *mid = middleNode(head);

        ListNode *l = sortList(head);
        ListNode *r = sortList(mid);

        return mergeTwoList(l, r);
    }

    ListNode *middleNode(ListNode *head)
    {
        ListNode *slow = head, *fast = head;
        ListNode *pre;
        while (fast && fast->next)
        {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = NULL; // 断成两条链表！！！！
        return slow;
    }

    ListNode *mergeTwoList(ListNode *left, ListNode *right)
    {
        if (!left || !right)
            return left ? left : right;

        ListNode *newhead = new ListNode(0);
        ListNode *p = newhead;
        while (left && right)
        {
            if (left->val < right->val)
            {
                p->next = left;
                left = left->next;
                p = p->next;
            }
            else
            {
                p->next = right;
                right = right->next;
                p = p->next;
            }
        }

        p->next = left ? left : right;
        return newhead->next;
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
    ListNode *res = s.sortList(head);
    while (res)
    {
        cout << res->val << " ";
        res = res->next;
    }

    return 0;
}