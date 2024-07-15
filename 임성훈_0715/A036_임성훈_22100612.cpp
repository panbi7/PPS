#include <iostream>
#include <vector>
using namespace std;

bool isSelfDividing(int num) {
    int original = num;
    while (num > 0) {
        int digit = num % 10;
        if (digit == 0 || original % digit != 0) {
            return false;
        }
        num /= 10;
    }
    return true;
}

vector<int> selfDividingNumbers(int left, int right) {
    vector<int> result;
    for (int i = left; i <= right; ++i) {
        if (isSelfDividing(i)) {
            result.push_back(i);
        }
    }
    return result;
}

int main() {
    // Example usage:
    int left1 = 1, right1 = 22;
    vector<int> res1 = selfDividingNumbers(left1, right1);
    cout << "Self-dividing numbers between " << left1 << " and " << right1 << ": ";
    for (int num : res1) {
        cout << num << " ";
    }
    cout << endl;
    
    int left2 = 47, right2 = 85;
    vector<int> res2 = selfDividingNumbers(left2, right2);
    cout << "Self-dividing numbers between " << left2 << " and " << right2 << ": ";
    for (int num : res2) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
