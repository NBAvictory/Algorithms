#include <vector>

using namespace std;

void radix_sort(vector<int> * a) {
    vector<vector<int> > temp(10);
    int min = a->at(0);
    int max = min;
    for (int i = 1; i < a->size(); i ++) {
        max = max < a->at(i) ? a->at(i) : max;
        min = min > a->at(i) ? a->at(i) : min;
    }
    // 处理负数
    if (min < 0) {
        for (int i = 0; i < a->size(); i ++) {
            a->at(i) -= min;
        }
        max -= min;
    }
    for (int digit = 1; max != 0; digit *= 10, max /= 10) {
        for (int i = 0; i < a->size(); i ++) {
            temp[int(a->at(i) / digit) % 10].push_back(a->at(i));
        }
        for (int i = 0, j = 0; i < 10; i ++) {
            for (int k = 0; k < temp[i].size(); k ++) {
                a->at(j) = temp[i][k];
                j += 1;
            }
            temp[i].clear();
        }
    }
    if (min < 0) {
        for (int i = 0; i < a->size(); i ++) {
            a->at(i) += min;
        }
    }
}
