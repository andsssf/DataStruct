#include "DS_HLinkQueue.h"

template <class T>
LQueue<T>::LQueue() {
    front = new LQueueNode<T>;
    front->next = nullptr;
    rear = front;
}

template <class T>
LQueue<T>::~LQueue() {
    while (!isEmpty()) {
        pLQueueNode temp = front->next;
        front->next = temp->next;
        if (rear == temp) rear = front;
        delete temp;
    }
}

template <class T>
bool LQueue<T>::push(T elem) {
    pLQueueNode pNode = new LQueueNode<T>;
    pNode->data = elem;
    pNode->next = nullptr;
    rear->next = pNode;
    rear = pNode;
    return true;
}

template <class T>
bool LQueue<T>::pop(T &elem) {
    if (isEmpty()) return false;
    pLQueueNode temp = front->next;
    elem = temp->data;
    front->next = temp->next;
    if (rear == temp) rear = front;
    delete temp;
    return true;
}

template <class T>
bool LQueue<T>::isEmpty() {
    return rear == front;
}