#include <iostream>
#include <vector>
#include "quick_sort.h"
#include "bubble_sort.h"
#include "select_sort.h"
#include "insert_sort.h"
#include "shell_sort.h"
#include "merge_sort.h"

using namespace std;

int main()
{
    vector<int> array = {8, 5, 3, 9, 0, 55, 5, 8, 12, 0, 3, 5};
    int len = array.size();
    // quick_sort(&array, 0, len-1);
    // bubble_sort(&array);
    // select_sort(&array);
    // insert_sort(&array);
    // shell_sort(&array);
    merge_sort(&array, 0, len - 1);
    for (int i=0; i< len; i++)
    {
        cout << array[i] << endl;
    }
    cout << endl;
    return 0;
}
