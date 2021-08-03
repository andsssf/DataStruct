/*
*  递归应用：数制转换
*/
#include <iostream>
#include <string>

using namespace std;

char NUMS[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

//num: 要转换的十进制数，type：数制
void transform(int num, int type=2) {
    if (num != 0) {
        transform(num/type, type);
        cout << NUMS[num % type];
    }
}

int main() {
    transform(38, 16);
    cout << endl;
    return 0;
}