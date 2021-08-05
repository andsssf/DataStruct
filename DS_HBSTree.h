#pragma once
#include <string>
/*
    链式二叉树、二叉搜索树、AVL树。
*/

template <class T>
struct LBiTreeNode
{
    T data;
    LBiTreeNode *left;
    LBiTreeNode *right;
};

template <class T>
class LBSTree {
    public:
    typedef LBiTreeNode<T> *pLBiTreeNode;
    LBSTree();
    ~LBSTree();
    int deep();
    bool insert(T elem);
    bool remove(const T &elem);
    
    // 以下是屎一样的代码
    std::string preOrder();
    std::string midOrder();
    // std::string afterOrder();
    std::string layerOrder();
    std::string prettyShow();
    
    private:
    bool clear(pLBiTreeNode pNode);
    int getDeep(pLBiTreeNode pNode);
    bool insert(pLBiTreeNode &pNode, T elem);
    bool remove(pLBiTreeNode &pNode, const T &elem);
    bool getMax(pLBiTreeNode pNode, T &elem);
    // 执行平衡操作
    bool makeBalance();
    // 获得树的平衡因子
    int getBalanceValue(pLBiTreeNode pNode);
    // 检测是否平衡
    bool checkBalance();
    bool checkBalance(pLBiTreeNode pNode);
    // 递归检测是否都平衡
    bool checkBalanceR(pLBiTreeNode pNode);
    pLBiTreeNode root;
};

#include "DS_HBSTree.cpp"