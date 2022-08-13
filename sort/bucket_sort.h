#include <vector>

using namespace std;

// 二分查找（可以保证排序稳定性），找到桶内需要插入数据的位置
void add_into_bucket(int x, vector<int> * bucket) {
    if (bucket->empty()) {
        bucket->push_back(x);
    }
    else {
        int begin = 0;
        int end = bucket->size() - 1;
        if (x >= bucket->at(end)) {
            bucket->push_back(x);
        }
        else if (x < bucket->at(begin)) {
            bucket->insert(bucket->begin(), x);
        }
        else {
            while (begin <= end) {
                if (x >= bucket->at(int((begin + end)/ 2))) {
                    begin = int((begin + end)/ 2) + 1;
                }
                else {
                    end = int((begin + end)/ 2) - 1;
                }
            }
            bucket->insert(bucket->begin() + begin, x);
        }
    }
}

void bucket_sort(vector<int> * a) {
    int min = a->at(0);
    int max = min;
    for (int i = 1; i < a->size(); i ++) {
        min = min > a->at(i) ? a->at(i) : min;
        max = max < a->at(i) ? a->at(i) : max;
    }
    int nums = int((max - min + 1)/ 5) + 1;
    vector<vector<int> > buckets(nums);
    // 负数需要处理。这里采用减最小值方式
    if (min < 0) {
        for (int i = 0; i < a->size(); i ++) {
            a->at(i) -= min;
        }
    }
    for (int i = 0; i < a->size(); i ++) {
        add_into_bucket(a->at(i), &buckets[int(a->at(i) / nums)]);
    }
    for (int n = 0, i = 0; n < nums; n ++) {
        for (int j = 0; j < buckets[n].size(); j ++) {
            a->at(i) = buckets[n][j];
            i += 1;
        }
    }
    if (min < 0) {
        for (int i = 0; i < a->size(); i ++) {
            a->at(i) += min;
        }
    }
}
