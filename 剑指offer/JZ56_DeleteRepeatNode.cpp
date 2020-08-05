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
    ListNode *deleteDuplication(ListNode *pHead)
    {
        if (pHead == NULL || pHead->next == NULL)
            return pHead;

        // 防止出现所有节点都相等的情况，所以添加一个表头
        ListNode *head = new ListNode(-1);
        head->next = pHead;

        // pre用来记录当前确定的不重复节点，p用来遍历
        ListNode *pre = head, *p = head->next;
        while (p)
        {
            if (p->next != NULL && (p->val == p->next->val))
            {
                while (p->next != NULL && (p->val == p->next->val))
                {
                    p = p->next;
                }
                pre->next = p->next;
                p = p->next;
            }
            else
            {
                pre = pre->next;
                p = p->next;
            }
        }
        return head->next;
    }
};

int main()
{
    return 0;
}