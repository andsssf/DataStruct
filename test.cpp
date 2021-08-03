#include <iostream>
#include "DS_HSqQueue.h"
#include "DS_HLinkQueue.h"
#include "DS_HBiTree.h"

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
    LBiTree<char> T;
    cout << T.preOrder() << endl;
    return 0;
}