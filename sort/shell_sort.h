#include <vector>

using namespace std;

void shell_sort(vector<int> * a) {
    int len = a->size();
    int dist = int(len / 2);
    while (dist >= 1) {
        for (int i = dist, temp, j; i < len; i += dist) {
            temp = a->at(i);
            j = i - dist;
            for (; j >=0 && a->at(j) > temp; j -= dist) {
                a->at(j + dist) = a->at(j);
            }
            a->at(j + dist) = temp;
        }
        dist = int(dist / 2);
    }
}
