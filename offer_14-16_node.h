#ifndef _NODE_H_
#define _NODE_H_

template <typename T>
class ListNode
{
public:
    ListNode<T> *next;
    ListNode<T> *prev;
    T val;
};

#endif
