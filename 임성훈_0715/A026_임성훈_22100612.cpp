#include <iostream>
using namespace std;

bool solution(int x) {
    int original = x;
    int sumOfDigits = 0;

    while (x > 0) {
        sumOfDigits += x % 10;
        x /= 10;
    }

    return (original % sumOfDigits == 0);
}

int main() {
    // 테스트 케이스
    int testCases[] = {10, 12, 11, 13};
    bool expectedResults[] = {true, true, false, false};

    for (int i = 0; i < 4; ++i) {
        int x = testCases[i];
        bool result = solution(x);
        cout << "x = " << x << ", expected = " << (expectedResults[i] ? "true" : "false") << ", result = " << (result ? "true" : "false") << endl;
    }

    return 0;
}
