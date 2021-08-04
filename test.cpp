#include <iostream>
#include "DS_HSqQueue.h"
#include "DS_HLinkQueue.h"
#include "DS_HBSTree.h"

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
    // // T.remove('5');
    // // cout << T.preOrder() << endl;

    // 标准输出流测试
    cout << "标准输出" << endl;
    cerr << "标准错误" << endl;
    
    return 0;
}