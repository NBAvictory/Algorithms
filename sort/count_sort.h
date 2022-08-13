#include <vector>

using namespace std;

void count_sort(vector<int> * a) {
    int min = a->at(0);
    int max = min;
    for (int i = 1; i < a->size(); i ++) {
        min = a->at(i) > min ? min : a->at(i);
        max = max > a->at(i) ? max : a->at(i);
    }
    vector<int> temp(max - min + 1, 0);
    for (int i = 0; i < a->size(); i ++) {
        temp[a->at(i) - min] += 1;
    }
    for (int i = 0, j = 0; i < max - min + 1; i ++) {
        while (temp[i] != 0) {
            a->at(j) = i + min;
            temp[i] -= 1;
            j += 1;
        }
    }
}
