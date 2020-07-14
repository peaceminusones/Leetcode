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
    /**
     * 没有使用dummy节点
    */
    ListNode *oddEvenList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        // 奇数链表，p1为遍历指针，last保存p1的上一个指针
        ListNode *p1 = head;
        ListNode *last = p1;
        // 偶数链表，p2为遍历指针，head2保存偶数链表的头节点
        ListNode *p2 = head->next;
        ListNode *head2 = p2;
        while (p1 && p2)
        {
            if (p2) // p2不为空，则p1指向p2的next
            {
                p1->next = p2->next;
                last = p1;
                p1 = p1->next;
            }
            if (p1) // p1不为空，则p2指向p1的next
            {
                p2->next = p1->next;
                p2 = p2->next;
            }
        }
        
        if (p1) // p1不为空，则直接让p1指向偶数链表的头节点
        {
            p1->next = head2;
        }
        else // p1为空，则让p1的上一个节点指向偶数链表的头节点
        {
            last->next = head2;
        }

        return head;
    }

    /**
     * 使用dummy节点
    */
    ListNode *oddEvenList_dummy(ListNode *head)
    {
        ListNode *odd = new ListNode(-1);  // 奇数头节点
        ListNode *even = new ListNode(-1); // 偶数头节点
        ListNode *curodd = odd, *cureven = even;

        while (head)
        {
            // 更新奇数链表
            // 这里的好处！！：如果head为NULL，则不会往后更新，curodd即为单数
            curodd->next = head;
            curodd = curodd->next;
            head = head->next;

            // 更新偶数链表
            if (head)
            {
                cureven->next = head;
                cureven = cureven->next;
                head = head->next;
            }
            else
            {
                cureven->next = NULL;
            }
        }

        curodd->next = even->next;
        return odd->next;
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
    ListNode *res = s.oddEvenList(head);
    while (res)
    {
        cout << res->val << " ";
        res = res->next;
    }
    return 0;
}