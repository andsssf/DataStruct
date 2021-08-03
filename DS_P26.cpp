/* 数据结构
*  栈的应用：括号匹配
*/

#include <iostream>
#include "DS_HLinkStack.h"

using namespace std;

bool bracketCheck(const char *str, int len) {
    LStack<char> S;
    for (int i=0; i < len; i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') S.push(str[i]);
        else {
            char popElem;
            if (!S.pop(popElem)) return false;
            if (popElem == '(' && str[i] != ')') return false;
            else if (popElem == '[' && str[i] != ']') return false;
            else if (popElem == '{' && str[i] != '}') return false;
        }
    }
    return S.isEmpty();
}

int main() {
    cout << bracketCheck("(){}[[(){()([])}]]", 18) << endl;
    return 0;
}