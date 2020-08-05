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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (headA == NULL || headB == NULL)
            return NULL;

        ListNode *p1 = headA;
        ListNode *p2 = headB;
        while (p1 != p2) // 防止出现头节点就是共同节点
        {
            // 如果当前节点不为NULL，则next，为空，则指向另一个链表的头节点
            // 如果有共同节点，则有p1==p2!=NULL，跳出循环返回p1
            // 如果无共同节点，则有p1==p2==NULL，同样跳出循环，返回p1
            p1 = (p1 == NULL) ? headB : p1->next;
            p2 = (p2 == NULL) ? headA : p2->next;
        }
        return p1;
    }
};

int main()
{

    return 0;
}