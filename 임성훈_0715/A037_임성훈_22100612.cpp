#include <iostream>
using namespace std;

int mySqrt(int x) {
    if (x == 0) return 0;
    
    int left = 1, right = x;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (mid == x / mid) {
            return mid; // Found the exact integer square root
        } else if (mid < x / mid) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return right; // Return the largest integer <= sqrt(x)
}

int main() {
    // Example usage:
    cout << "Square root of 4: " << mySqrt(4) << endl; // Output: 2
    cout << "Square root of 8: " << mySqrt(8) << endl; // Output: 2
    
    return 0;
}
