#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    if (n < 2) {
        cout << "Love is open door\n";
        return 0;
    }

    int first_method;
    cin >> first_method;

    cout << 1 - first_method << '\n'; // 두 번째 문의 방법 출력

    int current_method = first_method;

    for (int i = 2; i < n; ++i) {
        if (i % 2 == 0) {
            cout << current_method << '\n'; // 2의 배수 번째 문
        } else if (i % 3 == 0) {
            cout << current_method << '\n'; // 3의 배수 번째 문
        } else {
            current_method = 1 - current_method;
            cout << current_method << '\n'; // 그 외의 경우
        }
    }

    return 0;
}
