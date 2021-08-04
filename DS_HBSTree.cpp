#include "DS_HBSTree.h"
#include "DS_HLinkStack.h"
#include "DS_HLinkQueue.h"
#include <math.h>

using namespace std;

// LBiTreeNode<char>* initNode(char a) {
//     LBiTreeNode<char>* p = new LBiTreeNode<char>;
//     p->data = a;
//     p->left = nullptr;
//     p->right = nullptr;
//     return p;
// }

template <class T>
LBSTree<T>::LBSTree() {
    root = nullptr;
    // 在没有为这个普通二叉树制定应用前，是在无法制定插入和删除操作，只能用下面愚笨的方法进行遍历测试。
    // root = initNode('A');
    // root->left = initNode('B');
    // root->right = initNode('C');

    // root->left->left = initNode('D');
    // root->left->right = initNode('E');
    // root->left->left->right = initNode('G');

    // root->right->left = initNode('F');
}

template <class T>
LBSTree<T>::~LBSTree() {
    clear(root);
}

template <class T>
int LBSTree<T>::deep() {
    return getDeep(root);
}

template <class T>
bool LBSTree<T>::insert(T elem) {
    bool flag = insert(root, elem);
    if (!checkBalanceR(root)) makeBalance();
    return flag;
}

template <class T>
bool LBSTree<T>::insert(pLBiTreeNode &pNode, T elem) {
    if (pNode == nullptr) {
        pNode = new LBiTreeNode<T>;
        pNode->data = elem;
        pNode->left = nullptr;
        pNode->right = nullptr;
        return true;
    }
    if (pNode->data == elem) return false;
    if (pNode->data > elem) return insert(pNode->left, elem);
    else return insert(pNode->right, elem);
}

template <class T>
bool LBSTree<T>::remove(const T &elem) {
    bool flag = remove(root, elem);
    if (!checkBalanceR(root)) makeBalance();
    return flag;
}

template <class T>
bool LBSTree<T>::remove(pLBiTreeNode &pNode, const T &elem) {
    if (pNode == nullptr) return false;
    if (pNode->data == elem) {
        if (pNode->left == nullptr) {
            pLBiTreeNode temp = pNode;
            pNode = pNode->right;
            delete temp;
            return true;
        } else if (pNode->right == nullptr) {
            pLBiTreeNode temp = pNode;
            pNode = pNode->left;
            delete temp;
            return true;
        } else {
            // 选择左子树最大元素替换
            T maxElem;
            if (!getMax(pNode->left, maxElem)) return false;    // 找不到最大元素
            pNode->data = maxElem;                              // 替换
            return remove(pNode->left, maxElem);                // 删除左子树的该最大元素
        }
    } else if (pNode->data > elem){
        return remove(pNode->left, elem);
    } else {
        return remove(pNode->right, elem);
    }
}

// template <class T>
// string LBSTree<T>::preOrder() {
//     string out = "";
//     LStack<pLBiTreeNode> S;
//     pLBiTreeNode temp = root;
//     while (temp || !S.isEmpty()) {
//         if (temp != nullptr) {
//             S.push(temp);
//             out += temp->data;
//             temp = temp->left;
//         } else {
//             S.pop(temp);
//             temp = temp->right;
//         }
//     }
//     return out;
// }

template <class T>
string LBSTree<T>::midOrder() {
    string out = "";
    LStack<pLBiTreeNode> S;
    pLBiTreeNode temp = root;
    while (temp || !S.isEmpty()) {
        if (temp != nullptr) {
            S.push(temp);
            temp = temp->left;
        } else {
            S.pop(temp);
            out += temp->data;
            temp = temp->right;
        }
    }
    return out;
}

template <class T>
string LBSTree<T>::layerOrder() {
    string out = "";
    if (root == nullptr) return out;
    LQueue<pLBiTreeNode> Q;
    Q.push(root);
    while (!Q.isEmpty()) {
        pLBiTreeNode temp;
        Q.pop(temp);
        out += temp->data;
        if (temp->left != nullptr) Q.push(temp->left);
        if (temp->right != nullptr) Q.push(temp->right);
    }
    return out;
    
}

template <class T>
bool LBSTree<T>::clear(pLBiTreeNode pNode) {
    if (pNode == nullptr) return false;
    // 实际上利用是递归的后序遍历
    clear(pNode->left);
    clear(pNode->right);
    delete pNode;

    return true;
}

template <class T>
int LBSTree<T>::getDeep(pLBiTreeNode pNode) {
    if (pNode == nullptr) return 0;
    return max(getDeep(pNode->left), getDeep(pNode->right)) + 1;
}

template <class T>
bool LBSTree<T>::getMax(pLBiTreeNode pNode, T &elem) {
    if (pNode == nullptr) return false;

    pLBiTreeNode temp = pNode;
    while (temp->right != nullptr) {
        temp = temp->right;
    }
    elem = temp->data;
    return true;
}

template <class T>
bool LBSTree<T>::makeBalance() {
    if (root == nullptr) return false;  // 空树无法平衡
    pLBiTreeNode *temp = &root;
    // 定位最小不平衡子树
    while (*temp != nullptr) {
        if (!checkBalanceR(*temp) && checkBalanceR((*temp)->left) && checkBalanceR((*temp)->right)) break;
        else if (!checkBalanceR((*temp)->left)) {
            temp = &((*temp)->left);
        } else if (!checkBalanceR((*temp)->right)) {
            temp = &((*temp)->right);
        }
    }
    if (*temp == nullptr) return false;    // 定位失败
    
    // 情况1(LL)：A的左孩子的左子树插入导致A不平衡，将A的左孩子右上旋。
    if (getDeep((*temp)->left) - getDeep((*temp)->right) == 2 && getDeep((*temp)->left->left) - getDeep((*temp)->left->right) <= 1 && getDeep((*temp)->left->left) - getDeep((*temp)->left->right) >=0) {
        pLBiTreeNode alc = (*temp)->left;
        pLBiTreeNode a = *temp;
        *temp = alc;
        a->left = alc->right;
        alc->right = a;
        return true;
    }
    // 情况2(RR)：A的右孩子的右子树插入导致A不平衡，将A的右孩子左上旋。
    if (getDeep((*temp)->right) - getDeep((*temp)->left) == 2 && getDeep((*temp)->right->right) - getDeep((*temp)->right->left) <= 1 && getDeep((*temp)->right->right) - getDeep((*temp)->right->left) >= 0) {
        pLBiTreeNode arc = (*temp)->right;
        pLBiTreeNode a = *temp;
        *temp = arc;
        a->right = arc->left;
        arc->left = a;
        return true;
    }
    // 情况3(LR)：A的左孩子的右子树插入导致A不平衡，将A的左孩子的右孩子 先左上旋再右上旋转。
    if (getDeep((*temp)->left) - getDeep((*temp)->right) == 2 && getDeep((*temp)->left->left) - getDeep((*temp)->left->right) == -1) {
        // 左上旋
        pLBiTreeNode brc = (*temp)->left->right;
        pLBiTreeNode b = (*temp)->left;
        (*temp)->left = brc;
        b->right = brc->left;
        brc->left = b;

        // 右上旋
        pLBiTreeNode alc = (*temp)->left;
        pLBiTreeNode a = *temp;
        *temp = alc;
        a->left = alc->right;
        alc->right = a;
        return true;
    }
    // 情况4(RL)：A的右孩子的左子树插入导致A不平衡，将A的右孩子的左孩子 先右上旋再左上旋转。
    if (getDeep((*temp)->right) - getDeep((*temp)->left) == 2 && getDeep((*temp)->right->right) - getDeep((*temp)->right->left) == -1) {
        // 右上旋
        pLBiTreeNode blc = (*temp)->right->left;
        pLBiTreeNode b = (*temp)->right;
        (*temp)->right = blc;
        b->left = blc->right;
        blc->right = b;

        // 左上旋
        pLBiTreeNode arc = (*temp)->right;
        pLBiTreeNode a = *temp;
        *temp = arc;
        a->right = arc->left;
        arc->left = a;
        return true;
    }
    return false;
}

template <class T>
int LBSTree<T>::getBalanceValue(pLBiTreeNode pNode) {
    if (pNode == nullptr) return 0;
    return abs(getDeep(pNode->left)-getDeep(pNode->right));
}

template <class T>
bool LBSTree<T>::checkBalance() {
    return getBalanceValue(root) <= 1;
}

template <class T>
bool LBSTree<T>::checkBalance(pLBiTreeNode pNode) {
    return getBalanceValue(pNode) <= 1;
}

template <class T>
bool LBSTree<T>::checkBalanceR(pLBiTreeNode pNode) {
    return pNode == nullptr || (checkBalance(pNode) && checkBalanceR(pNode->left) && checkBalanceR(pNode->right));
}