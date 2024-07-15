#include <iostream>
using namespace std;

bool isPowerOfFour(int n) {
    if (n <= 0) return false;
    while (n % 4 == 0) {
        n /= 4;
    }
    return n == 1;
}

int main() {
    int n1 = 16;
    int n2 = 5;
    int n3 = 1;

    cout << "Example 1: " << (isPowerOfFour(n1) ? "true" : "false") << endl; // true
    cout << "Example 2: " << (isPowerOfFour(n2) ? "true" : "false") << endl; // false
    cout << "Example 3: " << (isPowerOfFour(n3) ? "true" : "false") << endl; // true

    return 0;
}
