#include <vector>

using namespace std;

// 设置一个数组primeTag标记从1到n所有值是否为质数，默认设置为全部为质数(bool值为1)
// 设置一个数组prime记录已筛选出来的质数（增序排列）。遍历primeTag，让当前数一一乘以已经筛选出的质数，标记结果数为false
// 为了实现每个合数都由它的最小质因数标记，当前正在遍历的数如果发现是合数且被质因数（显然这个质因数是它的最小质因数）整除，则不再对当前数乘以质数
void eulerSieve(vector<int>* prime, int n) {
    vector<bool> primeTag(n+1, true);
    // 遍历所有数，发现当前为质数，加入prime数组
    for (int i = 2; i <= n; i++) {
        if (primeTag[i]) {
            prime->push_back(i);
        }
        //  对当前数，乘以每一个质数，去标记primeTag中的合数
        for (vector<int>::iterator it = prime->begin(); (i * (*it) <= n) && (it != prime->end()); it ++) {
            primeTag[i * (*it)] = false;
            // 如果当前遍历到的数，它的最小质因数为i，则不再让它继续乘以其它质数。以保证每个合数都是由它的最小质因数标记为false
            if (i % *it == 0) {
                break;
            }
        }
    }
}
