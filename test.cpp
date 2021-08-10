#include <iostream>
// #include "DS_HSqQueue.h"
// #include "DS_HLinkQueue.h"
// #include "DS_HBSTree.h"
// #include "DS_HHTree.h"
// #include <vector>
// #include <algorithm> 
// #include "DS_HMGraph.h"
#include "DS_HTGraph.h"
#include "DS_HComGraphAlgorithms.h"

using namespace std;

int main() {
    // 循环队列测试代码
    // SQueue<int> Q;
    // for (int i=0; i < 30; i++) {
    //     Q.push(i);
    // }
    // for (int i=0; i < 30; i++) {
    //     int temp;
    //     if (Q.pop(temp))
    //         cout << temp << endl;
    // }

    // 链队列测试代码
    // LQueue<int> Q;
    // for (int i=0; i < 30; i++) {
    //     Q.push(i);
    // }
    // for (int i=0; i < 30; i++) {
    //     int temp;
    //     if (Q.pop(temp))
    //         cout << temp << endl;
    // }

    //二叉树测试代码
    // LBSTree<char> T;
    // char csets[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    // for (char c : csets) {
    //     T.insert(c);
    // }
    // // T.insert('4');
    // // T.insert('5');
    // // T.insert('2');
    // // T.insert('1');
    // // T.insert('3');
    // cout << T.midOrder() << endl;
    // cout << T.layerOrder() << endl;
    // T.remove('0');
    // T.remove('2');
    // cout << T.midOrder() << endl;
    // cout << T.layerOrder() << endl;
    // // cout << T.preOrder() << endl;

    // 标准输出流测试
    // cout << "标准输出" << endl;
    // cerr << "标准错误" << endl;

    // 排序算法和lambda表达式测试
    // vector<int> arr = {1, 2, 5, 6, 3, 9, 7, 8};

    // sort(arr.begin(), arr.end(), [](int a, int b) -> bool {return a > b;});

    // arr.pop_back();

    // for (int n : arr) {
    //     cout << n << endl;
    // }

    // 哈夫曼树测试
    // LHTree<int> H({1, 1, 1, 3, 4, 2, 5, 5, 2, 2, 2, 2, 4});
    // LHTree<int> H({1, 2, 3});
    // LHTree<int> H;
    // H.build({1, 1, 1, 3, 4, 2, 5, 5, 2, 2, 2, 2, 4});
    // cout << H.WPL() << endl;
    
    // 图邻接矩阵存储结构测试
    // MGraph<char> G({'a', 'b', 'c', 'd'}, {{0, 12, 4, GRAPH_INFINITY_DIST}, {12, 0, 44, 32}, {GRAPH_INFINITY_DIST, 23, 0, 33}, {GRAPH_INFINITY_DIST, GRAPH_INFINITY_DIST, 44, 0}});
    // MGraph<char> G;
    // cout << G.insertVertex('a') << endl;
    // cout << G.insertVertex('b') << endl;
    // cout << G.addEdge2('a', 'b', 10) << endl;
    // cout << G.insertVertex('c') << endl;
    // cout << G.addEdge2('c', 'b', 20) << endl;
    // vector<char> nbs;
    // cout << G.neighbors('b', nbs) << endl;
    // cout << G.deleteVertex('b') << endl;

    // 图邻接表存储结构测试
    MGraph<char> G;
    G.insertVertex('a');
    G.insertVertex('b');
    G.insertVertex('c');
    G.insertVertex('d');
    G.insertVertex('e');
    G.insertVertex('f');
    G.insertVertex('g');
    G.insertVertex('h');

    G.addEdge2('a', 'b');
    G.addEdge2('a', 'c');
    G.addEdge2('b', 'd');
    G.addEdge2('e', 'b');
    G.addEdge2('c', 'f');
    G.addEdge2('c', 'g');
    G.addEdge2('e', 'h');

    // cout << G.insertVertex('a') << endl;
    // cout << G.insertVertex('b') << endl;
    // cout << G.addEdge2('a', 'b', 10) << endl;
    // cout << G.insertVertex('c') << endl;
    // cout << G.addEdge2('c', 'b', 20) << endl;
    // vector<char> nbs;
    // cout << G.neighbors('b', nbs) << endl;
    // cout << G.deleteVertex('b') << endl;
    // cout << G.insertVertex('d') << endl;
    // cout << G.addEdge2('a', 'c', 10) << endl;
    // cout << G.addEdge2('a', 'd', 21) << endl;
    // cout << G.removeEdge2('a', 'c') << endl;
    // DepthFirstPrint(G, cout) << endl;
    
    vector<vector<int>> paths = Floyd(G);

    return 0;
}

