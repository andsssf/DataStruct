#pragma once
#include "DS_HLinkQueue.h"
#include "DS_HTGraph.h"
#include "DS_HMGraph.h"
#include <vector>
#include <iostream>

using namespace std;

// Floyd 最短路径算法
template <class T>
vector<vector<int>> Floyd(const TGraph<T> &graph) {
    vector<T> vexs = graph.getAllVertexs();
    vector<vector<int>> A(vexs.size(), vector<int>(vexs.size()));
    vector<vector<int>> path(vexs.size(), vector<int>(vexs.size(), -1));
    // 初始化
    for (typename vector<T>::size_type i = 0; i < vexs.size(); i++) {
        for (typename vector<T>::size_type j = 0; j < vexs.size(); j++) {
            if (i != j) {
                if (graph.adjacent(vexs[i], vexs[j])) {
                    graph.getEdgeWeight(vexs[i], vexs[j], A[i][j]);
                } else {
                    A[i][j] = GRAPH_INFINITY_DIST;
                }
            } else {
                A[i][j] = 0;
            }
        }
    }

    for (typename vector<T>::size_type k = 0; k < vexs.size(); k++) {
        for (typename vector<T>::size_type i = 0; i < vexs.size(); i++) {
            for (typename vector<T>::size_type j = 0; j < vexs.size(); j++) {
                if (A[i][k] + A[k][j] >0 && A[i][k] + A[k][j] < A[i][j]) {
                    A[i][j] = A[i][k] + A[k][j];
                    path[i][j] = k;
                }
            }
        }
    }

    return path;
}

template <class T>
vector<vector<int>> Floyd(const MGraph<T> &graph) {
    vector<T> vexs = graph.getAllVertexs();
    vector<vector<int>> A(vexs.size(), vector<int>(vexs.size()));
    vector<vector<int>> path(vexs.size(), vector<int>(vexs.size(), -1));
    // 初始化
    for (typename vector<T>::size_type i = 0; i < vexs.size(); i++) {
        for (typename vector<T>::size_type j = 0; j < vexs.size(); j++) {
            if (i != j) {
                if (graph.adjacent(vexs[i], vexs[j])) {
                    graph.getEdgeWeight(vexs[i], vexs[j], A[i][j]);
                } else {
                    A[i][j] = GRAPH_INFINITY_DIST;
                }
            } else {
                A[i][j] = 0;
            }
        }
    }

    for (typename vector<T>::size_type k = 0; k < vexs.size(); k++) {
        for (typename vector<T>::size_type i = 0; i < vexs.size(); i++) {
            for (typename vector<T>::size_type j = 0; j < vexs.size(); j++) {
                if (A[i][k] + A[k][j] >0 && A[i][k] + A[k][j] < A[i][j]) {
                    A[i][j] = A[i][k] + A[k][j];
                    path[i][j] = k;
                }
            }
        }
    }

    return path;
}

// Dijkstra 最短路径算法
template <class T>
vector<T> Dijkstra(const TGraph<T> &graph, const T &start) {
    vector<T> vexs = graph.getAllVertexs();
    vector<int> dist(vexs.size());
    vector<T> path(vexs.size());
    vector<bool> S(vexs.size());

    // 初始化距离
    for (int i = 0; i < vexs.size(); i++) {
        if (vexs[i] != start) {
            if (graph.adjacent(start, vexs[i])) {
                graph.getEdgeWeight(start, vexs[i], dist[i]);
                path[i] = start;
            } else {
                dist[i] = GRAPH_INFINITY_DIST;
            }
        } else {
            S[i] = true;
            dist[i] = 0;
        }
    }

    while (true) {
        int min = GRAPH_INFINITY_DIST, index = -1;
        for (vector<int>::size_type i = 0; i < dist.size(); i++) {
            if (!S[i] && dist[i] < min) {
                min = dist[i];
                index = i;
            }
        }
        if (index == -1) break;
        S[index] = true;
        for (int i = 0; i < vexs.size(); i++) {
            if (graph.adjacent(vexs[index], vexs[i])) {
                int temp;
                graph.getEdgeWeight(vexs[index], vexs[i], temp);
                if (temp + dist[index] < dist[i]) {
                    dist[i] = temp + dist[index];
                    path[i] = vexs[index];
                }
            }
        }
    }
    return path;
}   

template <class T>
vector<T> Dijkstra(const MGraph<T> &graph, const T &start) {
    vector<T> vexs = graph.getAllVertexs();
    vector<int> dist(vexs.size());
    vector<T> path(vexs.size());
    vector<bool> S(vexs.size());

    // 初始化距离
    for (int i = 0; i < vexs.size(); i++) {
        if (vexs[i] != start) {
            if (graph.adjacent(start, vexs[i])) {
                graph.getEdgeWeight(start, vexs[i], dist[i]);
                path[i] = start;
            } else {
                dist[i] = GRAPH_INFINITY_DIST;
            }
        } else {
            S[i] = true;
            dist[i] = 0;
        }
    }

    while (true) {
        int min = GRAPH_INFINITY_DIST, index = -1;
        for (vector<int>::size_type i = 0; i < dist.size(); i++) {
            if (!S[i] && dist[i] < min) {
                min = dist[i];
                index = i;
            }
        }
        if (index == -1) break;
        S[index] = true;
        for (int i = 0; i < vexs.size(); i++) {
            if (graph.adjacent(vexs[index], vexs[i])) {
                int temp;
                graph.getEdgeWeight(vexs[index], vexs[i], temp);
                if (temp + dist[index] < dist[i]) {
                    dist[i] = temp + dist[index];
                    path[i] = vexs[index];
                }
            }
        }
    }
    return path;
}   

template <class T>
int localVertex(const vector<T> &vexs, const T &elem) {
    int i = -1;
    for (typename vector<T>::size_type i = 0; i < vexs.size(); i++) {
        if (vexs[i] == elem) return i;
    }
    return i;
}

template <class T>
ostream& BreadthFirstPrint(const TGraph<T> &graph, ostream &out) {
    vector<T> vexs = graph.getAllVertexs();
    vector<bool> vistied(vexs.size()); 
    for (int i = 0; i < vexs.size(); i++) {
        if (!vistied[i]) {
            LQueue<T> Q;
            Q.push(vexs[i]);
            vistied[i] = true;
            while (!Q.isEmpty()) {
                T temp;
                Q.pop(temp);
                out << temp << " ";
                vector<T> nbs;
                graph.neighbors(temp, nbs);
                for (int j = 0; j < nbs.size(); j++) {
                    int loc = localVertex(vexs, nbs[j]);
                    if (!vistied[loc]) {
                        Q.push(nbs[j]);
                        vistied[loc] = true;
                    }
                }
            }
        }
    }
    return out;
}

template <class T>
ostream& BreadthFirstPrint(const MGraph<T> &graph, ostream &out) {
    vector<T> vexs = graph.getAllVertexs();
    vector<bool> vistied(vexs.size()); 
    for (int i = 0; i < vexs.size(); i++) {
        if (!vistied[i]) {
            LQueue<T> Q;
            Q.push(vexs[i]);
            vistied[i] = true;
            while (!Q.isEmpty()) {
                T temp;
                Q.pop(temp);
                out << temp << " ";
                vector<T> nbs;
                graph.neighbors(temp, nbs);
                for (int j = 0; j < nbs.size(); j++) {
                    int loc = localVertex(vexs, nbs[j]);
                    if (!vistied[loc]) {
                        Q.push(nbs[j]);
                        vistied[loc] = true;
                    }
                }
            }
        }
    }
    return out;
}

template <class T>
ostream& DFS(const TGraph<T> &graph, ostream &out, const T &vex, const vector<T> &vexs, vector<bool> &vistied) {
    out << vex << " ";
    vistied[localVertex(vexs, vex)] = true;
    vector<T> nbs;
    graph.neighbors(vex, nbs);
    for (T &elem : nbs) {
        if (!vistied[localVertex(vexs, elem)]) {
            DFS(graph, out, elem, vexs, vistied);
        }
    }
    return out;
}

template <class T>
ostream& DFS(const MGraph<T> &graph, ostream &out, const T &vex, const vector<T> &vexs, vector<bool> &vistied) {
    out << vex << " ";
    vistied[localVertex(vexs, vex)] = true;
    vector<T> nbs;
    graph.neighbors(vex, nbs);
    for (T &elem : nbs) {
        if (!vistied[localVertex(vexs, elem)]) {
            DFS(graph, out, elem, vexs, vistied);
        }
    }
    return out;
}

template <class T>
ostream& DepthFirstPrint(const TGraph<T> &graph, ostream &out) {
    vector<T> vexs = graph.getAllVertexs();
    vector<bool> vistied(vexs.size());

    for (typename vector<T>::size_type i = 0; i < vexs.size(); i++) {
        if (!vistied[i]) {
            DFS(graph, out, vexs[i], vexs, vistied);
        }
    }

    return out;
}

template <class T>
ostream& DepthFirstPrint(const MGraph<T> &graph, ostream &out) {
    vector<T> vexs = graph.getAllVertexs();
    vector<bool> vistied(vexs.size());

    for (typename vector<T>::size_type i = 0; i < vexs.size(); i++) {
        if (!vistied[i]) {
            DFS(graph, out, vexs[i], vexs, vistied);
        }
    }

    return out;
}