#pragma once

#define GRAPH_INFINITY_DIST 2147483647

template <class T>
class Graph {
    public:
    std::vector<T> getAllVertexs() const;
    bool adjacent(const T &a, const T &b) const;  // 判断是否存在边<a,b>或(a,b)
    bool neighbors(const T &vex, std::vector<T> &out) const; // 得到与节点vex连接的边
    bool insertVertex(const T &vex); // 插入节点 vex
    bool deleteVertex(const T &vex); // 删除节点 vex
    bool addEdge(const T &a, const T &b, int weight=1);   // 添加<a,b>边
    bool addEdge2(const T &a, const T &b, int weight=1);   // 添加(a,b)边
    bool removeEdge(const T &a, const T &b);    // 删除<a,b>边
    bool removeEdge2(const T &a, const T &b);    // 删除(a,b)边 
    bool getEdgeWeight(const T &a, const T &b, int &out) const; //得到(a,b)边权重
    bool setEdgeWeight(const T &a, const T &b, int weight); //设置(a,b)边权重
};