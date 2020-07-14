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
    /*
     * tips:
     * 添加一个哑结点作为辅助，该结点位于列表头部。
     * 哑结点用来简化某些极端情况，例如列表中只含有一个结点，或需要删除列表的头部！！！！！！！
    */
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        // 双指针，让p指针先走n+1步，
        ListNode *pre = dummy;
        ListNode *p = dummy;
        n = n + 1;
        while (n-- && p)
            p = p->next;

        // 然后pre指针和p指针一起走，直到p指针到达链表的最后
        while (p)
        {
            pre = pre->next;
            p = p->next;
        }

        // 然后让pre的next指针跳过下一个节点
        // 返回头节点
        /*
        if (pre == dummy)
            return pre->next->next;
        else
        {
            pre->next = pre->next->next;
            return dummy->next;
        } 这段代码可以合并！
        */
        pre->next = pre->next->next;
        return dummy->next;
    }
};

int main()
{
    ListNode *head = new ListNode(0);
    ListNode *p = head;
    int item;
    while (cin >> item)
    {
        ListNode *tmp = new ListNode(item);
        p->next = tmp;
        p = p->next;
    }
    head = head->next;
    cin.clear();
    cin.ignore();

    int n;
    cin >> n;

    Solution s;
    ListNode *res = s.removeNthFromEnd(head, n);
    while (res)
    {
        cout << res->val << " ";
        res = res->next;
    }

    return 0;
}