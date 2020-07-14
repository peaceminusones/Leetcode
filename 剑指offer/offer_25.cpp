#include <iostream>
using namespace std;

struct RandomListNode
{
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution
{
public:
    /*
        1、复制每个节点，如：复制节点A得到A1，将A1插入节点A后面
        2、遍历链表，A1->random = A->random->next;
        3、将链表拆分成原链表和复制后的链表
    */
    RandomListNode *Clone(RandomListNode *pHead)
    {
        if (pHead == NULL)
            return NULL;

        // 步骤一：复制每个结点
        // eg: 复制结点A得到A',将结点插入到A后面
        RandomListNode *cur = pHead; // 为了不修改头结点指针
        while (cur)
        {
            RandomListNode *node = new RandomListNode(cur->label);
            node->next = cur->next;
            cur->next = node;
            cur = node->next;
        }

        // 步骤二：重新遍历节点，复制random结点
        // eg：如果A有random结点，则有A1->random = A->random->next
        cur = pHead;
        while (cur)
        {
            RandomListNode *node = cur->next;
            if (cur->random)
                node->random = cur->random->next;
            cur = node->next;
        }

        // 步骤三：拆分链表，将链表拆分为原链表和复制后的链表
        // 利用一前一后的两个指针，修改next
        RandomListNode *pCloneHead = pHead->next; // 先把复制后的链表的头指针保存下来！
        RandomListNode *temp;
        cur = pHead;
        while (cur->next)
        {
            temp = cur->next;
            cur->next = temp->next;
            cur = temp;
        }
        return pCloneHead;
    }

    void Display(RandomListNode *pHead)
    {
        RandomListNode *cur = pHead;
        while (cur)
        {
            if (cur->random)
                cout << "(" << cur->label << "," << cur->random->label << "); ";
            else
                cout << "(" << cur->label << "); ";
            cur = cur->next;
        }
        cout << endl;
    }
};

int main()
{
    RandomListNode *a = new RandomListNode(1);
    RandomListNode *b = new RandomListNode(2);
    RandomListNode *c = new RandomListNode(3);
    RandomListNode *d = new RandomListNode(4);
    RandomListNode *e = new RandomListNode(5);
    RandomListNode *f = new RandomListNode(6);
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;
    a->random = d;
    b->random = f;

    Solution s;
    s.Display(a);
    RandomListNode *res = s.Clone(a);
    s.Display(res);

    return 0;
}