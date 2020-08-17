#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    // 方法一：利用合并两个有序链表，然后顺序合并 ========================================
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *res = NULL; // 必须赋值为NULL
        for (int i = 0; i < lists.size(); i++)
        {
            res = mergeTwoLists(res, lists[i]);
        }
        return res;
    }

    ListNode *mergeTwoLists(ListNode *a, ListNode *b)
    {
        if ((!a) || (!b))
            return a ? a : b;

        ListNode head;
        ListNode *p = &head; // 看ListNode的结构体！！！
        while (a && b)
        {
            if (a->val < b->val)
            {
                p->next = a;
                a = a->next;
                p = p->next;
            }
            else
            {
                p->next = b;
                b = b->next;
                p = p->next;
            }
        }

        p->next = a ? a : b;

        return head.next;
    }

    // 方法二：分治法合并
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        return merge(lists, 0, lists.size() - 1);
    }

    ListNode *merge(vector<ListNode *> &lists, int l, int r)
    {
        if (l == r)
            return lists[l];
        if (l > r)
            return NULL;

        int mid = l + (r - l) / 2;
        return mergeTwoLists(merge(lists, l, mid), merge(lists, mid + 1, r));
    }

    // 方法三：小根堆
    struct cmp
    {
        bool operator()(ListNode *a, ListNode *b)
        {
            return a->val > b->val; // 这是小根堆！！！！！！！！！！！改成小于号就是大根堆了
        }
    };

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<ListNode *, vector<ListNode *>, cmp> que;
        for (auto node : lists)
        {
            if (node)
                que.push(node);
        }

        ListNode head;
        ListNode *p = &head;
        while (!que.empty())
        {
            ListNode *top = que.top();
            que.pop();
            p->next = top;
            p = p->next;
            if (top->next)
                que.push(top->next);
        }
        return head.next;
    }
};

int main()
{
    return 0;
}