#include <iostream>
#include <stack>
#include <vector>
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
    * 堆栈
    */
    bool isPalindrome(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return true;

        stack<ListNode *> st;
        ListNode *p = head;
        int count = 0;
        while (p)
        {
            st.push(p);
            p = p->next;
            count++;
        }

        count = count / 2; // 只需要对比一半
        p = head;
        while (!st.empty() && count)
        {
            if (p->val == st.top()->val)
            {
                st.pop();
                p = p->next;
                count--;
            }
            else
                return false;
        }
        return true;
    }

    /**
     * 复制到数组中用双指针
    */
    bool isPalindrome_num(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return true;

        vector<int> num;
        ListNode *p = head;
        while (p)
        {
            num.push_back(p->val);
            p = p->next;
        }

        int i = 0, j = num.size() - 1;
        while (num[i] == num[j] && i <= j)
        {
            i++;
            j--;
        }
        if (i < j)
            return false;
        else
            return true;
    }

    /**
     * 快慢指针(slow fast p)+翻转
     * 时间复杂度：O(1)！！！！！！！！！！！！！！！！
    */
    bool isPalindrome_sfp(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return true;

        // slow每次走一步，fast每次走两步， 当fast到达结尾时，slow到达中间
        ListNode *slow = head;
        ListNode *fast = head;

        // slow边走边翻转
        ListNode *pre = NULL;
        ListNode *p = head;

        while (fast && fast->next)
        {
            // 快慢指针遍历
            slow = slow->next;
            fast = fast->next->next;

            // 翻转
            p->next = pre;
            pre = p;
            p = slow;
        }

        if (fast) // 奇数个节点
            slow = slow->next;

        while (pre)
        {
            if (pre->val == slow->val)
            {
                pre = pre->next;
                slow = slow->next;
            }
            else
                return false;
        }

        return true;
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
    bool res = s.isPalindrome_sfp(head);
    cout << res << endl;

    return 0;
}