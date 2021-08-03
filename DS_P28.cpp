/* 数据结构
*  栈的应用：中缀转后缀
*/

#include <iostream>
#include <string>
#include "DS_HLinkStack.h"

using namespace std;

class Helper {
    public:
    bool push(char elem, string &out) {

        string temp = "";
        if (elem == '(') {
            S.push(elem);
            out = temp;
            return true;
        }
        while (true) {
            char op;
            if (!S.pop(op)) break;
            if (op == '(') {
                if (elem != ')') S.push(op);
                break;
            } else if (elem != ')') {
                if (getLevel(elem) <= getLevel(op)) temp += op;
                else {
                    S.push(op);
                    break;
                }
            } else if (elem == ')'){
                temp += op;
            }
            
        }
        if (elem != ')') S.push(elem);
        out = temp;
        return true;
    }

    bool popAll(string & out) {
        char temp;
        string result = "";
        while (S.pop(temp)) {
            result += temp;
        }
        out = temp;
        return true;
    }

    int getLevel(char c) {
        if (c == '+' || c == '-') return 0;
        else if (c == '*' || c == '/') return 1;
        else if (c == '(' || c == ')') return 2;
        return -1;
    }
    private:
    LStack<char> S;
    
};

string compute(const string & str) {
    Helper H;
    string out = "";
    for (string::size_type i=0; i < str.size(); i++) {
        if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '(' || str[i] == ')') {
            string temp;
            H.push(str[i], temp);
            out += temp;
        } else {
            out += str[i];
        }
    }
    string temp;
    H.popAll(temp);
    out += temp;

    return out;
}

int main() {
    cout << compute("a+b-c*d/e+f") << endl;
    return 0;
}
