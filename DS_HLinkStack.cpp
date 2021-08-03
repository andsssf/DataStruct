#include "DS_HLinkStack.h"

template <class T>
LStack<T>::LStack() {
    top = nullptr;
}

template <class T>
LStack<T>::~LStack() {
    while (top != nullptr) {
        pLStackNode temp = top;
        top = top->next;
        delete temp;
    }
}

template <class T>
bool LStack<T>::push(T elem) {
    pLStackNode pNode = new LStackNode<T>;
    pNode->data = elem;
    pNode->next = top;
    top = pNode;
    return true;
}

template <class T>
bool LStack<T>::pop(T &elem) {
    if (top == nullptr) return false;
    pLStackNode temp = top;
    top = top->next;
    elem = temp->data;
    delete temp;
    return true;
}

template <class T>
bool LStack<T>::isEmpty() {
    return top == nullptr;
}