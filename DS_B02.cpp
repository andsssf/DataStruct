/*
*  递归应用：汉诺塔
*/
#include <iostream>
#include <string>

using namespace std;

void Hanoi(int num, char from, char target, char helper) {
    if (num == 1) {
        cout << from << " -> " << target << endl;
    } else {
        Hanoi(num-1, from, helper, target);
        cout << from << " -> " << target << endl;
        Hanoi(num-1, helper, target, from);
    }
}

int main() {
    Hanoi(4, 'A', 'C', 'B');
    return 0;
}