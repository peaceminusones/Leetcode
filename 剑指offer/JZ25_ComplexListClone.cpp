#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct RandomListNode
{
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution
{
public:
    // RandomListNode *Clone(RandomListNode *pHead)
    // {
    //     if (pHead == NULL)
    //         return pHead;
    //     // 1、遍历链表
    //     // 复制每个节点，插入到相应节点的后面
    //     RandomListNode *cur = pHead;
    //     while (cur)
    //     {
    //         RandomListNode *tmp = new RandomListNode(cur->label);
    //         tmp->next = cur->next;
    //         cur->next = tmp;
    //         cur = cur->next->next;
    //     }

    //     // 2、重新遍历链表
    //     // 如果被复制的链表有random指针，则复制random指针
    //     cur = pHead;
    //     while (cur)
    //     {
    //         // 如果当前的random指针不为空
    //         if (cur->random != NULL)
    //         {
    //             // 取出这个节点的复制节点
    //             RandomListNode *tmp = cur->next;
    //             // 指向当前节点的random节点的复制节点
    //             tmp->random = cur->random->next;
    //         }
    //         cur = cur->next->next; // 需要跳过被复制的节点
    //     }

    //     // 3、把两个链表拆开
    //     // 采用交叉指向
    //     RandomListNode *pclone = pHead->next; // 使用pclone指向复制链表的链表头
    //     RandomListNode *pclonehead = pclone;  // 复制链表的链表头存下来
    //     cur = pHead;                          // 被复制链表的链表头
    //     while (cur && pclone)
    //     {
    //         cur->next = pclone->next;
    //         cur = cur->next;
    //         if (cur)
    //         {
    //             pclone->next = cur->next;
    //             pclone = pclone->next;
    //         }
    //     }
    //     return pclonehead;
    // }

    RandomListNode *Clone(RandomListNode *pHead)
    {
        if (pHead == NULL)
            return pHead;

        // 一个map，把两个链表的节点对应起来
        unordered_map<RandomListNode *, RandomListNode *> map;
        // 复制链表头
        RandomListNode *pclone = new RandomListNode(pHead->label);
        RandomListNode *pc = pclone; //指向复制链表的表头指针
        // 指向表头的指针
        RandomListNode *p = pHead;
        // 循环遍历被复制的链表，然后一步一步复制节点信息，创建新的链表pclone
        // 然后把节点关系也存储下来
        while (p)
        {
            if (p->next)
                pc->next = new RandomListNode(p->next->label);
            else
                pc->next = NULL;
            map[p] = pc;

            p = p->next;
            pc = pc->next;
        }

        // 根据map中存储的节点关系，更新pclone链表中的random节点
        p = pHead;
        pc = pclone;
        while (p)
        {
            pc->random = map[p->random];
            p = p->next;
            pc = pc->next;
        }

        return pclone;
    }
};

int main()
{
    return 0;
}