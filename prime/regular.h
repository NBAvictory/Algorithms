#include <vector>
#include <cmath>

using namespace std;

// 设置一个数组记录已有质数
// 对从3到n的每个数i进行遍历
// 如果i能被小于等于sqrt(i)的质数整除，则它不是质数。否则，它是质数，将它添加到质数数组中
void regularSieve(vector<int>* prime, int n) {
    bool isPrime = true;
    prime->push_back(2);
    for (int i = 3; i <= n; i ++) {
        isPrime = true;
        for (vector<int>::iterator it = prime->begin(); (it != prime->end() && (*it <= sqrt(i))); it ++) {
            if (i % *it == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            prime->push_back(i);
        }
    }
}
