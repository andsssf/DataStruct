#pragma once
/*
    循环队列
*/
#define SQUEUE_MAX_SIZE 21

template <class T>
class SQueue {
    public:
    SQueue();
    bool push(T elem);
    bool pop(T &elem);
    bool isEmpty();
    private:
    int local(int index);
    T data[SQUEUE_MAX_SIZE];
    int front, rear;
};

// 针对使用模板的特殊情况，编译器必须能够查看实现以此生成特化代码
#include "DS_HSqQueue.cpp"