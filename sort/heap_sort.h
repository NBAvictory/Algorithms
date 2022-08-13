#include <vector>

using namespace std;

void swap(vector<int> * h, int x, int y) {
    int temp = h->at(x);
    h->at(x) = h->at(y);
    h->at(y) = temp;
}

// 对于数组h，从层序遍历序号为parent的元素开始，从上至下将它的子树重新调整为大根堆
void adjust_subheap(vector<int> * h, int parent, int len) {
    int temp = h->at(parent);
    int right, max;
    for (int left = 2 * (parent + 1) - 1; left < len; left = 2 * (parent + 1) - 1) {
        max = left;
        right = left + 1;
        if (right < len && h->at(right) > h->at(left)) {
            max = right;
        }
        if (h->at(max) > temp) {
            h->at(parent) = h->at(max);
            parent = max;
        }
        else {
            break;
        }
    }
    h->at(parent) = temp;
}

// 完全二叉树特性：父结点层序遍历序号（从1开始）为i时，左子结点层序遍历序号为2*i，右子结点层序遍历序号为2*(i+1)
// 此处的len是堆的结点数量，也是堆元素的最大层序遍历序号（从1开始）
// 从层序遍历序号最大的非叶子结点（序号为int(len/2) - 1）开始，从下至上调整子树为大根堆
void adjust_heap(vector<int> * h, int len) {
    int left, right, max;
    for (int i = int(len/2) - 1; i >= 0; i --) {
        left = 2 * (i + 1) - 1;
        right = 2 * (i + 1);
        max = left;
        if (right < len) {
            max = (h->at(left) > h->at(right)) ? left : right;
        }
        if (h->at(max) > h->at(i)) {
            swap(h, i, max);
            adjust_subheap(h, max, len);
        }
    }
}

void heap_sort(vector<int> * a) {
    for(int len = a->size(); len > 1; len --) {
        adjust_heap(a, len);
        swap(a, 0, len - 1);
    }
}
