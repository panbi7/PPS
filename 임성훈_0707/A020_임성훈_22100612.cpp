#include <iostream>

using namespace std;

int main() {
    int max_people = 0; // 최대 사람 수
    int current_people = 0; // 현재 기차에 있는 사람 수

    // 4개의 역에 대해 입력 받고 처리
    for (int i = 0; i < 4; ++i) {
        int out, in;
        cin >> out >> in;

        // 기차에서 내린 사람 수를 빼고, 탄 사람 수를 더함
        current_people = current_people - out + in;

        // 최대 사람 수 업데이트
        if (current_people > max_people) {
            max_people = current_people;
        }
    }

    // 결과 출력
    cout << max_people << endl;

    return 0;
}