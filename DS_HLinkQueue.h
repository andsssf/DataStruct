#pragma once
/*
    链表队列
*/

template <class T>
struct LQueueNode
{
    T data;
    LQueueNode *next;
};


template <class T>
class LQueue {
    public:
    LQueue();
    ~LQueue();
    bool push(T elem);
    bool pop(T &elem);
    bool isEmpty();
    private:
    typedef LQueueNode<T> *pLQueueNode;
    pLQueueNode front, rear;
};

// 针对使用模板的特殊情况，编译器必须能够查看实现以此生成特化代码
#include "DS_HLinkQueue.cpp"