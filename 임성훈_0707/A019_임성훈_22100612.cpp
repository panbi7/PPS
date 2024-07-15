#include <iostream>
#include <string>

using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;

    int result = A * B * C;
    string result_str = to_string(result);

    int count[10] = {0}; // 각 숫자(0~9)의 개수를 저장할 배열

    for (char ch : result_str) {
        int digit = ch - '0'; // char를 int로 변환하여 숫자를 구함
        count[digit]++;
    }

    for (int i = 0; i < 10; ++i) {
        cout << count[i] << endl;
    }

    return 0;
}
