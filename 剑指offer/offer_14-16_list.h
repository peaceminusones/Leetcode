#ifndef _LINK_H_
#define _LINK_H_
#include <iostream>
#include "offer_14-16_node.h"

template <typename T>
class ListLink
{
private:
    ListNode<T> *head;
    ListNode<T> *tail;
    int length;

public:
    ListLink();                   // 默认构造函数
    ListLink(const ListLink &ln); //拷贝构造函数
    ~ListLink();                  //析构函数
    void add(T e);                //向链表添加数据
    void ascSort();               //升序排序
    void remove(T index);         //移除某个结点
    T find(int index);            //查找结点
    bool isEmpty();               //判断是否为空
    int size();                   //链表长度
    void show();                  //显示链表
    void resShow();               //反向显示
    void removeall();             //删除全部结点
};

//////////////////////////////////////////////////////
// 默认构造函数
template <typename T>
ListLink<T>::ListLink()
{
    head = new ListNode<T>;
    tail = new ListNode<T>;
    head->next = tail;
    head->prev = nullptr;
    tail->next = nullptr;
    tail->prev = head;
    length = 0;
}
// 拷贝构造函数
template <typename T>
ListLink<T>::ListLink(const ListLink &ln)
{
    head = new ListNode<T>;
    tail = new ListNode<T>;
    head->prev = nullptr;
    head->next = tail;
    tail->prev = head;
    length = 0;
    ListNode<T> *temp = ln.head;
    while(temp->next != ln.tail)
    {
        temp = temp->next;
        tail->data = temp->data;
        ListNode<T> *p = new ListNode<T>;
        p->prev = tail;
        tail.next = p;
        tail = p;
        length++;
    }
    tail->next = nullptr;
}

#endif