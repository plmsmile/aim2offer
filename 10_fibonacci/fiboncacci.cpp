#include <iostream>

using namespace std;

long long fibonacci_recursion(unsigned int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    return fibonacci_recursion(n-1) + fibonacci_recursion(n-2);
}



long long fibonacci_loop(unsigned int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    long long f1 = 0;
    long long f2 = 1;
    long long fn = 0;
    for (unsigned int i = 2; i <= n; i++) {
        fn = f1 + f2;
        f1 = f2;
        f2 = fn;
    }
    return fn;
}

int main() {
    
    cout << fibonacci_recursion(10) << endl;
    cout << fibonacci_loop(10) << endl;
    return 0;
}
