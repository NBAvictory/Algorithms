#include <vector>

using namespace std;

void merge_sort(vector<int> * a, int begin, int end) {
    if (begin >= end) {
        return;
    }
    merge_sort(a, begin, int((begin + end)/2));
    merge_sort(a, int((begin + end)/2) + 1, end);
    vector<int> temp;
    int i = begin;
    int j = int((begin + end)/2) + 1; 
    while (i <= int((begin + end)/2) && j <= end) {
        if (a->at(i) <= a->at(j)) {
            temp.push_back(a->at(i));
            i ++;
        }
        else {
            temp.push_back(a->at(j));
            j ++;
        }
    }
    if (i > int((begin + end)/2)) {
        while (j <= end) {
            temp.push_back(a->at(j));
            j ++;
        }
    }
    else {
        while (i <= int((begin + end)/2)) {
            temp.push_back(a->at(i));
            i ++;
        }
    }
    for (int k = begin; k <= end; k ++) {
        a->at(k) = temp[k - begin];
    }
}
