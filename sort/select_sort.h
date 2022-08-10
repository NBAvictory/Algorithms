#include <vector>

using namespace std;

void select_sort(vector<int> * a) {
    int min;
    int temp;
    for (int i = 0; i < a->size() - 1; i ++) {
        min = i;
        for (int j = i + 1; j < a->size(); j ++ ) {
            min = (a->at(j)) < a->at(min) ? j : min; 
        }
        temp = a->at(i);
        a->at(i) = a->at(min);
        a->at(min) = temp;
    }
}
