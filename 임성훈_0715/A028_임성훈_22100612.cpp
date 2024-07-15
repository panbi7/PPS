#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string addLargeNumbers(string A, string B) {
    // 두 문자열의 길이를 맞추기 위해 앞쪽에 0을 채운다
    if (A.length() < B.length()) {
        swap(A, B);
    }
    while (B.length() < A.length()) {
        B = '0' + B;
    }

    string result = "";
    int carry = 0;

    // 각 자리수의 합을 계산
    for (int i = A.length() - 1; i >= 0; --i) {
        int sum = (A[i] - '0') + (B[i] - '0') + carry;
        carry = sum / 10;
        sum = sum % 10;
        result = to_string(sum) + result;
    }

    // 마지막으로 carry가 남아 있다면 추가
    if (carry > 0) {
        result = to_string(carry) + result;
    }

    return result;
}

int main() {
    string A, B;
    cin >> A >> B;
    cout << addLargeNumbers(A, B) << endl;
    return 0;
}