#include "DS_HTGraph.h"

using namespace std;

template <class T>
TGraph<T>::TGraph() {
    for (int i = 0; i < NTABLE_GRAPH_MAX_SIZE; i++) {
        vexs[i].onUse = false;
    }
    vexs_num = 0;
}

template <class T>
TGraph<T>::~TGraph() {
    for (int i = 0; i < NTABLE_GRAPH_MAX_SIZE; i++) {
        if (vexs[i].onUse) {
            clear(vexs[i]);
            vexs[i].onUse = false;
            vexs[i].next = nullptr;
        }
    }
}

template <class T>
vector<T> TGraph<T>::getAllVertexs() const {
    vector<T> result;
    int temp = 0;
    if (vexs_num == 0) return result;
    for (int i = 0; i < NTABLE_GRAPH_MAX_SIZE; i++) {
        if (vexs[i].onUse) {
            result.push_back(vexs[i].data);
            temp++;
            if (temp == vexs_num) break;
        }
    }
    return result;
}

template <class T>
bool TGraph<T>::adjacent(const T &a, const T &b) const {
    int loc;
    if (!localVertex(a, loc)) return false;
    pNTableEdgeNode temp = vexs[loc].next;

    while (temp != nullptr) {
        if (vexs[temp->index].data == b) return true;
        temp = temp->next;
    }
    return false;
}

template <class T>
bool TGraph<T>::neighbors(const T &vex, std::vector<T> &out) const {
    int loc;
    if (!localVertex(vex, loc)) return false;
    pNTableEdgeNode temp = vexs[loc].next;
    vector<T> result;
    while (temp != nullptr) {
        result.push_back(vexs[temp->index].data);
        temp = temp->next;
    }
    out = result;
    return true;
}

template <class T>
bool TGraph<T>::insertVertex(const T &vex) {
    int temp;
    if (localVertex(vex, temp)) return false;
    if (vexs_num == NTABLE_GRAPH_MAX_SIZE) return false;
    for (int i = 0; i < NTABLE_GRAPH_MAX_SIZE; i++) {
        if (!vexs[i].onUse) {
            vexs[i].data = vex;
            vexs[i].onUse = true;
            vexs[i].next = nullptr;
            vexs_num++;
            return true;
        }
    }
    return false;   // 未知情况
}

template <class T>
bool TGraph<T>::deleteVertex(const T &vex) {
    int loc;
    if (!localVertex(vex, loc)) return false;

    // 删除与其联系的边
    for (int i = 0; i < vexs_num;) {
        if (vexs[i].onUse) {
            if (i != loc) removeEdge(vexs[i].data, vexs[loc].data);
            i++;
        }
    }

    clear(vexs[loc]);
    vexs[loc].onUse = false;
    vexs[loc].next = nullptr;
    vexs_num--;
    return true;
}

template <class T>
bool TGraph<T>::addEdge(const T &a, const T &b, int weight) {
    int locA, locB;
    if (adjacent(a, b)) return false;
    if (!localVertex(a, locA) || !localVertex(b, locB)) return false;
    pNTableEdgeNode temp = new NTableEdgeNode;
    temp->index = locB;
    temp->weight = weight;
    temp->next = nullptr;
    if (vexs[locA].next == nullptr) {
        vexs[locA].next = temp;
        return true;
    }
    pNTableEdgeNode pLoc = vexs[locA].next;
    while (pLoc->next != nullptr) pLoc = pLoc->next;
    pLoc->next = temp;
    return true;

}

template <class T>
bool TGraph<T>::addEdge2(const T &a, const T &b, int weight) {
    return addEdge(a, b, weight) && addEdge(b, a, weight);
}

template <class T>
bool TGraph<T>::removeEdge(const T &a, const T &b) {
    int loc;
    if (!localVertex(a, loc)) return false;
    if (vexs[loc].next == nullptr) return false;
    pNTableEdgeNode temp = vexs[loc].next;
    if (vexs[temp->index].data == b) {
        vexs[loc].next = temp->next;
        delete temp;
        return true;
    }
    while (temp->next != nullptr) {
        if (vexs[temp->next->index].data == b) {
            pNTableEdgeNode p = temp->next;
            temp->next = p->next;
            delete p;
            return true;
        }
        temp = temp->next;
    }
    return false;
}

template <class T>
bool TGraph<T>::removeEdge2(const T &a, const T &b) {
    return removeEdge(a, b) && removeEdge(b, a);
}

template <class T>
bool TGraph<T>::getEdgeWeight(const T &a, const T &b, int &out) const {
    int loc;
    if (!localVertex(a, loc)) return false;
    pNTableEdgeNode temp = vexs[loc].next;
    while (temp != nullptr) {
        if (vexs[temp->index].data == b) {
            out = temp->weight;
            return true;
        }
        temp = temp->next;
    }
    return false;
}

template <class T>
bool TGraph<T>::setEdgeWeight(const T &a, const T &b, int weight) {
    int loc;
    if (!localVertex(a, loc)) return false;
    pNTableEdgeNode temp = vexs[loc].next;
    while (temp != nullptr) {
        if (vexs[temp->index].data == b) {
            temp->weight = weight;
            return true;
        }
        temp = temp->next;
    }
    return false;
}

template <class T>
bool TGraph<T>::localVertex(const T &vex, int &outLoc) const {
    if (vexs_num == 0) return false;
    int loc = -1;
    for (int i = 0; i < NTABLE_GRAPH_MAX_SIZE; i++) {
        if (vexs[i].onUse) {
            if (vexs[i].data == vex) {
                loc = i;
                break;
            }
        }
    }
    if (loc == -1) return false;
    outLoc = loc;
    return true;
}

template <class T>
void TGraph<T>::clear(NTableNode<T> node) {
    pNTableEdgeNode temp = node.next;
    while (temp != nullptr) {
        pNTableEdgeNode p = temp;
        temp = temp->next;
        delete p;
    }
}