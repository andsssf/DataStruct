#pragma once
template <class T>
struct LStackNode{
    T data;
    LStackNode<T> *next;
};

template <class T>
class LStack {
    public:
    LStack();
    ~LStack();
    bool push(T elem);
    bool pop(T &elem);
    bool isEmpty();
    private:
    typedef LStackNode<T> *pLStackNode;
    pLStackNode top;
};

// 针对使用模板的特殊情况，编译器必须能够查看实现以此生成特化代码
#include "DS_HLinkStack.cpp"