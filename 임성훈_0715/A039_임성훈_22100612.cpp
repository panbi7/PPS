#include <iostream>
using namespace std;

bool isPerfectSquare(int num) {
    if (num == 1) return true; // Special case for num = 1
    
    int left = 1, right = num;
    while (left <= right) {
        long long mid = left + (right - left) / 2; // Use long long to avoid overflow
        long long square = mid * mid;
        
        if (square == num) {
            return true;
        } else if (square < num) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return false;
}

int main() {
    // Example usage:
    cout << "Is 16 a perfect square? " << (isPerfectSquare(16) ? "Yes" : "No") << endl; // Output: Yes
    cout << "Is 14 a perfect square? " << (isPerfectSquare(14) ? "Yes" : "No") << endl; // Output: No
    
    return 0;
}
