#include <iostream>
#include "DS_HSqQueue.h"
#include "DS_HLinkQueue.h"
#include "DS_HBSTree.h"
#include "DS_HHTree.h"
#include <vector>
#include <algorithm> 

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

    // vector<int> arr = {1, 2, 5, 6, 3, 9, 7, 8};

    // sort(arr.begin(), arr.end(), [](int a, int b) -> bool {return a > b;});

    // arr.pop_back();

    // for (int n : arr) {
    //     cout << n << endl;
    // }

    // LHTree<int> H({1, 1, 1, 3, 4, 2, 5, 5, 2, 2, 2, 2, 4});
    // LHTree<int> H({1, 2, 3});
    LHTree<int> H;
    H.build({1, 1, 1, 3, 4, 2, 5, 5, 2, 2, 2, 2, 4});
    cout << H.WPL() << endl;
    return 0;
}

