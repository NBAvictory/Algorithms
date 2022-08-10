#include <vector>
#include <iostream>

using namespace std;

void insert_sort(vector<int> * a) {
    int temp;
    for (int i = 1, j; i < a->size(); i ++) {
        j = i - 1;
        temp = a->at(i);
        // 找到合适位置，然后数据向后移动
        // while (j >= 0 && temp < a->at(j)) {
        //     j --;
        // }
        // for (int k = i - 1; k >= j + 1; k --) {
        //     a->at(k + 1) = a->at(k);
        // }
        // a->at(j + 1) = temp;

        // 找合适位置的同时，数据向后移动
        while (j >= 0 && a->at(j) > temp) {
            a->at(j + 1) = a->at(j);
            j --;
        }
        a->at(j + 1) = temp;
    }
}
