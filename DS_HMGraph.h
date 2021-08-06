#pragma once
#include <vector>
#define GRAPH_INFINITY_DIST 2147483647
/*
    图的邻接矩阵存储实现
*/

template <class T>
class MGraph {
    public:
    MGraph(const std::vector<T> &vexs, const std::vector<std::vector<int>> &edges): vexs{vexs}, edges{edges} {}
    
    private:
    std::vector<T> vexs;    // 定点集
    std::vector<std::vector<int>> edges; // 边集
};