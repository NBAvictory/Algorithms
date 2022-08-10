#include <vector>

using namespace std;

// 稳定排序
void bubble_sort(vector<int> * a) {
    int temp;
    for (int i = a->size() - 1; i >= 1; i --) {
        for (int j = 0; j < i; j ++) {
            if (a->at(j) > a->at(j + 1)) {
                temp = a->at(j);
                a->at(j) = a->at(j + 1);
                a->at(j + 1) = temp;
            }
        }
    }
}
