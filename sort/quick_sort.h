#include <vector>

using namespace std;

// 非稳定排序
void quick_sort(vector<int> * a, int begin, int end)
{
    if (begin >= end)
    {
        return;
    }
    else
    {
        int left=begin, right=end;
        int key=a->at(right);
        while (left < right)
        {
            while (key > a->at(left) && left < right)
            {
                left++;
            }
            if (left<right)
            {
                a->at(right) = a->at(left);
                right--;
            }
            while (key < a->at(right) && left < right)
            {
                right--;
            }
            if (left<right)
            {
                a->at(left) = a->at(right);
                left++;
            }
        }
        a->at(left) = key;
        quick_sort(a, begin, left - 1);
        quick_sort(a, left + 1, end);
    }
}
