#pragma once
#include "DS_HLinkQueue.h"
#include "DS_HTGraph.h"
#include "DS_HMGraph.h"
#include <vector>
#include <iostream>

using namespace std;

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