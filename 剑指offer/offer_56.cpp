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
    ListNode *deleteDuplication(ListNode *pHead)
    {
        if (pHead == NULL)
            return NULL;
        if (pHead->next == NULL)
            return pHead;

        ListNode *head = new ListNode(0); //防止出现第一个第二个结点就相同的情况
        head->next = pHead;

        ListNode *pre = head, *p = head->next; // pre用于记录当前确定的不重复的节点，p用于往后遍历
        while (p)
        {
            // 如果p和p->next都不空，且大小不等，则p和pre都可以往后移动一个位置
            if (p->next != NULL && p->val == p->next->val)
            {
                while (p->next != NULL && p->val == p->next->val)
                {
                    p = p->next;
                }
                pre->next = p->next;
                p = p->next;
            }
            // 如果p和p->next都不空，且大小相同，则移动p，找到p和p->next不相同的位置，更新pre->next
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
    ListNode *res = s.deleteDuplication(head);

    if (res == NULL)
        cout << "NULL";

    while (res)
    {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;

    return 0;
}