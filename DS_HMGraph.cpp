#include "DS_HMGraph.h"

using namespace std;

template <class T>
vector<T> MGraph<T>::getAllVertexs() const {
    return vexs;
}

template <class T>
bool MGraph<T>::adjacent(const T &a, const T &b) const {
    int locA, locB;
    if (!localVertex2(a, b, locA, locB)) return false;

    return edges[locA][locB] != GRAPH_INFINITY_DIST;
}

template <class T>
bool MGraph<T>::neighbors(const T &vex, vector<T> &out) const {
    if (vexs.size() == 0) return false;
    int loc = -1;
    
    // 元素定位
    for (typename vector<T>::size_type i = 0; i < vexs.size(); i++) {
        if (vexs[i] == vex) {
            loc = i;
            break;
        }
    }

    // 定位失败
    if (loc == -1) return false;

    vector<T> result;
    for (typename vector<T>::size_type i = 0; i < edges[loc].size(); i++) {
        if (edges[loc][i] != GRAPH_INFINITY_DIST && i != loc) result.push_back(vexs[i]);
    }
    out = result;
    return true;
}

template <class T>
bool MGraph<T>::insertVertex(const T &vex) {
    for (T v : vexs) {
        if (v == vex) return false; // 不能重复插入同个元素
    }

    vexs.push_back(vex);
    if (vexs.size() > 1) {
        vector<int> temp(vexs.size() - 1, GRAPH_INFINITY_DIST);
        edges.push_back(temp);
        for (vector<int> &arr : edges) {
            arr.push_back(GRAPH_INFINITY_DIST);
        }
    } else {
        vector<int> temp(1, GRAPH_INFINITY_DIST);
        edges.push_back(temp);
    }
    return true;
}

template <class T>
bool MGraph<T>::deleteVertex(const T &vex) {
    if (vexs.size() == 0) return false;
    int loc = -1;
    bool is_find = false;
    for (typename vector<T>::iterator it = vexs.begin(); it != vexs.end(); it++) {
        loc++;
        if (*it == vex) {
            vexs.erase(it);
            is_find = true;
            break;
        }
    }
    if (!is_find) return false;
    typename vector<vector<int>>::iterator edges_it = edges.begin();
    for (int i=0; i < loc; i++) edges_it++;
    edges.erase(edges_it);
    for (vector<int> &arr : edges) {
        typename vector<int>::iterator arrs_it = arr.begin();
        for (int i=0; i < loc; i++) arrs_it++;
        arr.erase(arrs_it);
    }
    return true;
}

template <class T>
bool MGraph<T>::addEdge(const T &a, const T &b, int weight) {
    int locA, locB;
    if (!localVertex2(a, b, locA, locB)) return false;

    if (edges[locA][locB] != GRAPH_INFINITY_DIST) return false;
    edges[locA][locB] = weight;
    return true;
}

template <class T>
bool MGraph<T>::addEdge2(const T &a, const T &b, int weight) {
    return addEdge(a, b, weight) && addEdge(b, a, weight);
}

template <class T>
bool MGraph<T>::removeEdge(const T &a, const T &b) {
    int locA, locB;
    if (!localVertex2(a, b, locA, locB)) return false;
    
    if (edges[locA][locB] == GRAPH_INFINITY_DIST) return false;

    edges[locA][locB] = GRAPH_INFINITY_DIST;
    return true;
}

template <class T>
bool MGraph<T>::removeEdge2(const T &a, const T &b) {
    return removeEdge(a, b) && removeEdge(b, a);
}

template <class T>
bool MGraph<T>::getEdgeWeight(const T &a, const T &b, int &out) const {
    int locA, locB;
    if (!localVertex2(a, b, locA, locB)) return false;
    if (edges[locA][locB] == GRAPH_INFINITY_DIST) return false;
    out = edges[locA][locB];
    return true;
}

template <class T>
bool MGraph<T>::setEdgeWeight(const T &a, const T &b, int weight) {
    int locA, locB;
    if (!localVertex2(a, b, locA, locB)) return false;
    if (edges[locA][locB] == GRAPH_INFINITY_DIST) return false;
    edges[locA][locB] = weight;
    return true;
}

template <class T>
bool MGraph<T>::localVertex2(const T &a, const T &b, int &outLocA, int &outLocB) const {
    if (edges.size() == 0) return false;
    int locA = -1, locB = -1;
    bool breakFlagA = false, breakFlagB = false;

    // 元素定位
    for (typename vector<T>::size_type i = 0; i < vexs.size(); i++) {
        if (breakFlagA && breakFlagB) break;
        if (vexs[i] == a) {
            locA = i;
            breakFlagA = true;
        } else if (vexs[i] == b) {
            locB = i;
            breakFlagB = true;
        }
    }

    //定位失败
    if (locA == -1 || locB == -1) return false;

    outLocA = locA;
    outLocB = locB;
    return true;
}