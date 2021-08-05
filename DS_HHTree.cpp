#include "DS_HHTree.h"
#include <algorithm> 
#include <map>
using namespace std;

template <class T>
LHTree<T>::LHTree() {
    root = nullptr;
}

template <class T>
LHTree<T>::LHTree(const vector<T> &data) {
    root = nullptr;
    build(data);
}

template <class T>
LHTree<T>::~LHTree() {
    clear(root);
    root = nullptr;
}

template <class T>
bool LHTree<T>::clear(pLHTreeNode pNode) {
    if (pNode == nullptr) return false;
    clear(pNode->left);
    clear(pNode->right);
    delete pNode;
    return true;
}

template <class T>
LHTreeNode<T>* LHTree<T>::createNode(T elem, int weight) {
    pLHTreeNode p = new LHTreeNode<T>;
    p->data = elem;
    p->weight = weight;
    return p;
}

template <class T>
LHTreeNode<T>* LHTree<T>::createPath(pLHTreeNode left, pLHTreeNode right) {
    pLHTreeNode p = new LHTreeNode<T>;
    p->weight = left->weight + right->weight;
    p->left = left;
    p->right = right;
    return p;
}

template <class T>
bool LHTree<T>::build(const vector<T> &data) {
    if (root != nullptr) return false;  // 一棵树只能构建一次
    map<T, int> localData;
    // 频次统计
    for (T elem : data) {
        typename map<T, int>::iterator itr = localData.find(elem);
        if (itr == localData.end()) {
            localData[elem] = 1;
        } else {
            itr->second++;
        }
    }
    // 初始化节点集合
    vector<pLHTreeNode> nodes;
    for (typename map<T, int>::const_iterator itr = localData.begin(); itr != localData.end(); itr++) {
        nodes.push_back(createNode(itr->first, itr->second));
    }

    while (nodes.size() > 1) {
        sort(nodes.begin(), nodes.end(), [](pLHTreeNode a, pLHTreeNode b) -> bool {return a->weight > b->weight;});
        pLHTreeNode min1 = nodes.back();
        nodes.pop_back();
        pLHTreeNode min2 = nodes.back();
        nodes.pop_back();
        nodes.push_back(createPath(min1, min2));
    }

    root = nodes.back();
    return true;
}

template <class T>
int LHTree<T>::WPL() {
    return WPL(root, 0);
}

template <class T>
int LHTree<T>::WPL(pLHTreeNode pNode, int deep) {
    if (pNode == nullptr) return 0;
    if (pNode->left == pNode->right) return pNode->weight * deep;
    return WPL(pNode->left, deep + 1) + WPL(pNode->right, deep + 1);
}