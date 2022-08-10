#include <iostream>
#include <vector>
#include "regular.h"
#include "eratosthenes_sieve.h"
#include "euler_sieve.h"

using namespace std;

// 筛选所有小于等于n的质数
int main() {
    int n = 0;
    vector<int> prime;
    if (n > 1) {
        regularSieve(&prime, n);
        // eratosthenesSieve(&primeNumber, n);
        // eulerSieve(&primeNumber, n);
    }
    cout << "Total primes less than or equal n :" << prime.size() << endl;
    for (vector<int>::iterator it = prime.begin(); it != prime.end(); it ++) {
        cout << *it << endl;
    }
    return 0;
}
