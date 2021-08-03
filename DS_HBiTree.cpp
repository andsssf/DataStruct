#include "DS_HBiTree.h"
#include "DS_HLinkStack.h"
#include <math.h>

using namespace std;

LBiTreeNode<char>* initNode(char a) {
    LBiTreeNode<char>* p = new LBiTreeNode<char>;
    p->data = a;
    p->left = nullptr;
    p->right = nullptr;
    return p;
}

template <class T>
LBiTree<T>::LBiTree() {
    root = nullptr;
    // 在没有为这个普通二叉树制定应用前，是在无法制定插入和删除操作，只能用下面愚笨的方法进行遍历测试。
    // root = initNode('A');
    // root->left = initNode('B');
    // root->right = initNode('C');

    // root->left->left = initNode('D');
    // root->left->right = initNode('E');
    // root->left->left->right = initNode('G');

    // root->right->left = initNode('F');
}

template <class T>
LBiTree<T>::~LBiTree() {
    clear(root);
}

template <class T>
int LBiTree<T>::deep() {
    return getDeep(root);
}

template <class T>
string LBiTree<T>::preOrder() {
    string out = "";
    LStack<pLBiTreeNode> S;
    pLBiTreeNode temp = root;
    while (temp || !S.isEmpty()) {
        if (temp != nullptr) {
            S.push(temp);
            out += temp->data;
            temp = temp->left;
        } else {
            S.pop(temp);
            temp = temp->right;
        }
    }
    return out;
}

template <class T>
string LBiTree<T>::midOrder() {
    string out = "";
    LStack<pLBiTreeNode> S;
    pLBiTreeNode temp = root;
    while (temp || !S.isEmpty()) {
        if (temp != nullptr) {
            S.push(temp);
            temp = temp->left;
        } else {
            S.pop(temp);
            out += temp->data;
            temp = temp->right;
        }
    }
    return out;
}

template <class T>
bool LBiTree<T>::clear(pLBiTreeNode pNode) {
    if (pNode == nullptr) return false;
    // 实际上利用是递归的后序遍历
    clear(pNode->left);
    clear(pNode->right);
    delete pNode;

    return true;
}

template <class T>
int LBiTree<T>::getDeep(pLBiTreeNode pNode) {
    if (pNode == nullptr) return 0;
    return max(getDeep(pNode->left), getDeep(pNode->right)) + 1;
}