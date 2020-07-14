#include <iostream>
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
    vector<ListNode *> splitListToParts(ListNode *root, int k)
    {
        vector<ListNode *> res;
        int count = 0;
        ListNode *p = root;
        while (p)
        {
            p = p->next;
            count++;
        }

        if (count <= k)
        {
            int i = 0;
            while (i++ < k)
            {
                p = root;
                if (p)
                {
                    root = p->next;
                    p->next = NULL;
                    res.push_back(p);
                }
                else
                {
                    res.push_back(NULL);
                }
            }
        }
        else
        {
            int n = count / k; // 分成k部分，每部分有n节点
            cout << n << endl;
            int m = count % k; // 有m个部分需要加1个节点
            cout << m << endl;
            while (k)
            {
                p = root;
                ListNode *head = root;
                int i = 1;
                while (i < n)
                {
                    p = p->next;
                    i++;
                }
                if (m != 0)
                {
                    p = p->next;
                    m--;
                }

                if (p->next)
                {
                    root = p->next;
                    // cout << "root: " << root->val << endl;
                    p->next = NULL;
                    // cout << "p: " << p->val << endl;
                }

                res.push_back(head);
                // cout << "head: " << head->val << endl;
                k--;
            }
        }
        return res;
    }

    /**
     * 把上面分开考虑的思想合并起来
    */
    vector<ListNode *> splitListToParts_main(ListNode *root, int k)
    {
        vector<ListNode *> res;
        // 计算链表中有多少个节点
        ListNode *p = root;
        int count = 0;
        while (p)
        {
            p = p->next;
            count++;
        }

        int size = count / k; // count分为k组，每组元素为n个
        int m = count % k;    // 分为k组，每组n个后，还剩下m个节点，按从前往后按顺序放入

        while (k)
        {
            p = root;
            res.push_back(p);

            int cursize = (m-- > 0) ? (size + 1) : size; // 如果有余数，则从前往后把size加1
            // 走cursize长度
            for (int i = 0; i < cursize - 1; i++)
            {
                p = p->next;
            }
            // 如果p不为NULL，更新root和p->next
            if (p)
            {
                root = p->next;
                p->next = NULL;
            }
            else // 如果p为NULL，更新root也为NULL
            {
                root = p;
            }

            k--;
        }

        return res;
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
    cin.clear();
    cin.ignore();

    int k;
    cin >> k;

    Solution s;
    vector<ListNode *> res = s.splitListToParts_main(head, k);
    cout << res.size() << endl;

    int i = 0;
    while (res[i] && i < res.size())
    {
        ListNode *p = res[i];
        while (p)
        {
            cout << p->val << " ";
            p = p->next;
        }
        cout << endl;
        i++;
    }
    return 0;
}