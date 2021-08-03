#pragma once
#include <string>
/*
    链式二叉树，不完善的数据结构。为二叉搜索树打基础。
*/

template <class T>
struct LBiTreeNode
{
    T data;
    LBiTreeNode *left;
    LBiTreeNode *right;
};

template <class T>
class LBiTree {
    public:
    typedef LBiTreeNode<T> *pLBiTreeNode;
    LBiTree();
    ~LBiTree();

    int deep();
    
    // 以下是屎一样的代码
    std::string preOrder();
    std::string midOrder();
    std::string afterOrder();

    bool getNode(const T &elem, pLBiTreeNode p);
    
    private:
    bool clear(pLBiTreeNode pNode);
    int getDeep(pLBiTreeNode pNode);
    pLBiTreeNode root;
};

#include "DS_HBiTree.cpp"