#include "DS_HSqQueue.h"

template <class T>
SQueue<T>::SQueue() {
    front =  0;
    rear = 0;
}

template <class T>
bool SQueue<T>::push(T elem) {
    if (local(rear + 1) == front) return false;
    data[rear] = elem;
    rear = local(rear + 1);
    return true;
}

template <class T>
bool SQueue<T>::pop(T &elem) {
    if (isEmpty()) return false;
    elem = data[front];
    front = local(front + 1);
    return true;
}

template <class T>
bool SQueue<T>::isEmpty() {
    return rear ==  front;
}

template <class T>
int SQueue<T>::local(int index) {
    return index % SQUEUE_MAX_SIZE;
}