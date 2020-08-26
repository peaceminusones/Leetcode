#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (head == NULL)
            return head;

        // 遍历链表：复制每个节点，插入到相应节点的后面
        Node *p = head;
        while (p)
        {
            Node *newnode = new Node(p->val);
            newnode->next = p->next;
            p->next = newnode;
            p = p->next->next;
        }

        // 重新遍历链表：如果被复制的链表有random指针，则复制random指针
        p = head;
        while (p)
        {
            if (p->random != NULL)
            {
                Node *q = p->next;
                q->random = p->random->next;
            }
            p = p->next->next;
        }

        // 把两个链表拆开
        Node *newhead = head->next;
        Node *q = newhead;
        p = head;
        while (p && q)
        {
            p->next = q->next;
            p = p->next;
            if (p)
            {
                q->next = p->next;
                q = q->next;
            }
        }

        return newhead;
    }

    Node *copyRandomList2(Node *head)
    {
        if (head == NULL)
            return head;

        unordered_map<Node *, Node *> map;
        Node *newhead = new Node(head->val);
        Node *newp = newhead;
        Node *p = head;
        while (p)
        {
            // 复制不考虑随机节点的整个链表
            if (p->next)
                newp->next = new Node(p->next->val);
            else
                newp->next = NULL;

            // 记录被复制链表节点和复制链表节点的对应关系
            map[p] = newp;
            p = p->next;
            newp = newp->next;
        }

        p = head;
        newp = newhead;
        while (p)
        {
            // 考虑随机节点
            newp->random = map[p->random];
            p = p->next;
            newp = newp->next;
        }

        return newhead;
    }
};

int main()
{
}