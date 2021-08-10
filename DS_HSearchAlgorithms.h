#include <vector>

// 顺序查找
int seqSearch(const std::vector<int> & table, int key) {
    for (std::vector<int>::size_type i = 0; i < table.size(); i++) {
        if (table[i] == key) {
            return i;
        }
    }
    return -1;
}