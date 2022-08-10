#include <vector>
#include <cmath>

using namespace std;

// 设置一个数组primeTag标记从1到n所有值是否为质数，默认设置为全部为质数(bool值为1)
// 从质数2（下标为2）开始遍历primeTag数组直至sqrt(n)，对每个质数的倍数标记false
void eratosthenesSieve(vector<int>* prime, int n) {
    vector<bool> primeTag(n+1, true);
    primeTag[0] = primeTag[1] = false;
    primeTag[2] = true;
    for (int i = 2; i <= sqrt(n); i ++) {
        if (primeTag[i]) {
            for (int j = i; j <= n / i; j ++) {
                primeTag[i * j] = false;
            }
            // for (int j = i * i; j <= n; j += i) {
            //     primeTag[j] = false;
            // }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (primeTag[i]) {
            prime->push_back(i);
        }
    }
}
