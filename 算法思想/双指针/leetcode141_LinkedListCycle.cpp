#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    /*
     * 判断链表是否有环
     * 一个low指针（每次走一步），一个fast（每次走两步）
     * 如果有环，low和fast最终会相遇
     * 如果没环，则走到结尾NULL
    */
    bool hasCycle(ListNode *head)
    {
        if (head == NULL)
            return false;

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast)
        {
            if (fast->next == NULL)
                return false;

            slow = slow->next;
            fast = fast->next->next;

            if (fast == slow)
                return true;
        }

        // 速度更快========================
        // while (fast)
        // {
        //     fast = fast->next;
        //     if (fast)
        //         fast = fast->next;

        //     if (fast == slow)
        //         return true;

        //     slow = slow->next;
        // }
        // ================================

        return false;
    }
};

int main()
{
    return 0;
}