#include <iostream>
#include <cmath>

using namespace std;

// 判断一个正整数是不是质数。也可以用于对合数进行因式分解
int main() {
    int n = 119;
    bool isPrime = false;
    if (n <= 3) {
        isPrime = (n > 1);
    }
    else {
        if ((n % 6 == 1) || (n % 6 == 5)) {
            isPrime = true;
            // 通过上面的判断且不能进入以下循环的数：5、7、11、13、17、19、23都是质数
            for (int i = 5; i <= int(sqrt(n)); i += 6) {
                if (n % i == 0 || n % (i + 2) == 0) {
                    isPrime = false;
                    break;
                }
            }
        }
    }
    if (isPrime) {
        cout << n << " is a prime." << endl;
    }
    else {
        cout << n << " is not a prime" << endl;
    }
}
