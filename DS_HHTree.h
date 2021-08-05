#pragma once
/*
    哈夫曼树
*/
#include <vector>

template <class T>
struct LHTreeNode
{
    T data;
    int weight = 0; //节点权重
    bool isPath = false;
    LHTreeNode *left = nullptr;
    LHTreeNode *right = nullptr;

};

template <class T>
class LHTree {
    public:
    typedef LHTreeNode<T> *pLHTreeNode;
    LHTree();
    LHTree(const std::vector<T> &data);     // 构造时完成树的构建
    ~LHTree();
    bool build(const std::vector<T> &data);  // 通过给定数据集构造哈夫曼树
    int WPL();  // 树的带权路径长度
    private:
    int WPL(pLHTreeNode pNode, int deep);
    bool clear(pLHTreeNode pNode);
    LHTreeNode<T>* createNode(T elem, int weight);
    LHTreeNode<T>* createPath(pLHTreeNode left, pLHTreeNode right);
    pLHTreeNode root;
};

#include "DS_HHTree.cpp"