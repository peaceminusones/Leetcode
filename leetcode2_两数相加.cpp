#include <iostream>
#include <vector>
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
    ListNode *create(int nums)
    {
        ListNode *head = new ListNode(0);
        ListNode *p = head;
        while (nums)
        {
            int x = nums % 10;
            nums /= 10;
            ListNode *temp = new ListNode(x);
            p->next = temp;
            p = p->next;
        }
        return head->next;
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *head = new ListNode(0);
        ListNode *p = head;

        int v1, v2;    // 两个链表当前位的值
        int sum;       // 当前位的和
        int carry = 0; // 进位

        while (l1 || l2)
        {
            v1 = (l1 != NULL) ? l1->val : 0; // 如果链表l1的当前位不为空，则取出值，否则置0
            v2 = (l2 != NULL) ? l2->val : 0; // 如果链表l2的当前位不为空，则取出值，否则置0

            sum = carry + v1 + v2; // 当前位的和
            carry = sum / 10;      // 如果和超过10，需要取出进位

            p->next = new ListNode(sum % 10);
            p = p->next;

            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }

        if (carry > 0)
            p->next = new ListNode(1);

        return head->next;
    }
};

int main()
{
    Solution s;
    int item;

    int nums1, nums2;
    cin >> nums1 >> nums2;
    ListNode *l1 = s.create(nums1);
    ListNode *l2 = s.create(nums2);

    ListNode *res = s.addTwoNumbers(l1, l2);
    while (res)
    {
        cout << res->val << " ";
        res = res->next;
    }

    return 0;
}