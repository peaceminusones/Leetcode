#include <iostream>
#include <vector>
#include <cstring>
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
    // 直接倒叙插入vector
    vector<int> printListFromTailToHead(ListNode *head)
    {
        vector<int> res;
        while (head)
        {
            res.insert(res.begin(), head->val);
            head = head->next;
        }

        return res;
    }

    // 递归
    vector<int> printListFromTailToHead(ListNode *head)
    {
        vector<int> res;
        if (head == NULL)
            return res;

        res = printListFromTailToHead(head->next);
        res.push_back(head->val);
        return res;
    }

    // 翻转链表
    ListNode *reverseList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *pre = NULL;
        ListNode *cur = head;
        ListNode *p = head;
        while (p)
        {
            p = p->next;
            cur->next = pre;
            pre = cur;
            cur = p;
        }

        return pre;
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
    // vector<int> res = s.printListFromTailToHead(head);
    // for (auto r : res)
    // {
    //     cout << r << " ";
    // }
    // cout << endl;

    ListNode *pres = s.reverseList(head);
    while (pres)
    {
        cout << pres->val << " ";
        pres = pres->next;
    }
    cout << endl;

    delete head;
    delete p;

    return 0;
}