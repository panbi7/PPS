#include <iostream>
using namespace std;

int main() {
    int notes[8];
    bool ascending = true, descending = true;

    // 입력 받기
    for (int i = 0; i < 8; ++i) {
        cin >> notes[i];
    }

    // ascending 체크
    for (int i = 0; i < 7; ++i) {
        if (notes[i] >= notes[i + 1]) {
            ascending = false;
            break;
        }
    }

    // descending 체크
    for (int i = 0; i < 7; ++i) {
        if (notes[i] <= notes[i + 1]) {
            descending = false;
            break;
        }
    }

    // 결과 출력
    if (ascending) {
        cout << "ascending\n";
    } else if (descending) {
        cout << "descending\n";
    } else {
        cout << "mixed\n";
    }

    return 0;
}
