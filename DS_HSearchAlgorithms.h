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

// 二分查找
int binarySearch(const std::vector<int> & table, int key) {
    int low = 0;
    int high = table.size() - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (table[mid] == key) return mid;
        else if (key > table[mid]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}