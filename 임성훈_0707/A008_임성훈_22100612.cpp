#include <iostream>
#include <vector>
#include <iomanip> // for setprecision

using namespace std;

int main() {
    int C;
    cin >> C;

    for (int i = 0; i < C; ++i) {
        int N;
        cin >> N;

        vector<int> scores(N);
        double sum = 0;

        // 학생 점수 입력 및 총합 계산
        for (int j = 0; j < N; ++j) {
            cin >> scores[j];
            sum += scores[j];
        }

        // 평균 계산
        double average = sum / N;

        // 평균을 넘는 학생 비율 계산
        int count = 0;
        for (int j = 0; j < N; ++j) {
            if (scores[j] > average) {
                count++;
            }
        }

        double percentage = (static_cast<double>(count) / N) * 100;

        // 소수점 셋째 자리까지 출력
        cout << fixed << setprecision(3) << percentage << "%" << endl;
    }

    return 0;
}
