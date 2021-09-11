#pragma once
#include <vector>
using namespace std;
// 5阶B数
struct BTreeNode
{
    // 约定0存放节点数量, 1、3、5、7、9存放指针, 2、4、6、8存放数据
    long long data[10];
};

class BTree {
    public:
    typedef BTreeNode *pBTreeNode;
    BTree() {root = new BTreeNode;}
    // ~BTree();
    bool insert(int num);
    bool remove(int num);
    private:
    bool insert(pBTreeNode *p, int num, bool &needI, int &value, pBTreeNode &right);
    pBTreeNode root;
};

bool BTree::insert(int num) {
    bool need;
    int value;
    pBTreeNode right;
    bool flag = insert(&root, num, need, value, right);
    if (!flag) return false;
    if (need) {
        pBTreeNode p = root;
        root = new BTreeNode;
        root->data[0] = 1;
        root->data[1] = (long long)p;
        root->data[2] = value;
        root->data[3] = (long long)right;
    }
    return true;
}

bool BTree::insert(pBTreeNode *p, int num, bool &needI, int &value, pBTreeNode &right) {
    int n = (*p)->data[0];
    bool isTernimal = true;
    for (int i = 0; i < n; i++) {
        if ((pBTreeNode)((*p)->data[2*i+1]) != nullptr) {
            isTernimal = false;
            break;
        }
    }
    if (!isTernimal) {
        int pLoc = 1;
        for (int i = 2; i / 2 - 1 < n; i+=2) {
            if ((*p)->data[i] == num) return false;
            else if ((*p)->data[i] < num) pLoc+=2;
            else break; 
        }
        bool need;
        int r_value;
        pBTreeNode r_right;
        bool flag = insert((pBTreeNode*)((*p)->data + pLoc), num, need, r_value, r_right);
        if (!flag) {
            needI = false;
            return false;
        }
        if (!need) {
            needI = false;
            return true;
        }

        if (n != 4) {
            // 腾空
            for (int i = 7; i != pLoc; i--) {
                (*p)->data[i+2] = (*p)->data[i];
            }
            // 塞入
            (*p)->data[pLoc + 1] = r_value;
            (*p)->data[pLoc + 2] = (long long)r_right;
            needI = false;
            return true;
        } else {
            needI = true;
            int temp[12];
            for (int i = 0; i < 12; i++) {
                temp[i] = (*p)->data[i];
            }
            for (int i = 9; i != pLoc; i--) {
                (*p)->data[i+2] = (*p)->data[i];
            }
            temp[pLoc + 1] = r_value;
            temp[pLoc + 1] = (long long)r_right;

            (*p)->data[0] = 2;
            for (int i = 1; i < 12; i++) {
                if (i < 6) (*p)->data[i] = temp[i];
                else (*p)->data[i] = 0;
            }
            value = temp[6];
            right = new BTreeNode;
            right->data[0] = 2;
            for (int i = 1; i < 6; i++) {
                right->data[i] = temp[i+6];
            }
            return true;
        }

    } else {
        if (n != 4) {
            int temp[4];
            int k = 2;
            if (n != 0) {
                bool finish = false;
                for (int i = 0; i < n + 1; i++) {
                    if (num ==  (*p)->data[k]) return false;
                    else if (!finish && num <  (*p)->data[k]) {
                        temp[i] = num;
                        finish = true;
                    }
                    else if (k == 2*n + 2) {
                        temp[i] = num;
                    }
                    else {
                        temp[i] = (*p)->data[k];
                        k += 2;
                    }
                }

                (*p)->data[0] = n + 1;
                for (int i = 0; i < n + 1; i++) {
                    (*p)->data[2*i + 2] = temp[i];
                }
            } else {
                (*p)->data[0] = 1;
                (*p)->data[2] = num;
            }
            
            needI = false;
            return true;
        } else {
            int temp[5];
            int k = 2;
            bool finish = false;
            for (int i = 0; i < n + 1; i++) {
                if (num ==  (*p)->data[k]) return false;
                else if (!finish && num <  (*p)->data[k]) {
                    temp[i] = num;
                    finish = true;
                }
                else if (k == 2*n + 2) {
                    temp[i] = num;
                }
                else {
                    temp[i] = (*p)->data[k];
                    k += 2;
                }
            }
            needI = true;
            value = temp[2];
            right = new BTreeNode;
            right->data[0] = 2;
            right->data[2] = temp[3];
            right->data[4] = temp[4];
            (*p)->data[0] = 2;
            (*p)->data[2] = temp[0];
            (*p)->data[4] = temp[1];
            return true;
        }
    }
}