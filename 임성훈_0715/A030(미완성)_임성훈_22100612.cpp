#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int N, initial_mood;
    double p00, p01, p10, p11;
    cin >> N >> initial_mood;
    cin >> p00 >> p01 >> p10 >> p11;

    // DP 배열 선언
    double dp[N + 1][2];
    
    // 초기 상태 설정
    dp[0][0] = (initial_mood == 0) ? 1.0 : 0.0;
    dp[0][1] = (initial_mood == 1) ? 1.0 : 0.0;

    // DP 계산
    for (int i = 1; i <= N; ++i) {
        dp[i][0] = dp[i-1][0] * p00 + dp[i-1][1] * p01;
        dp[i][1] = dp[i-1][0] * p10 + dp[i-1][1] * p11;
    }

    // 출력
    cout << round(dp[N][0] * 1000) << endl;
    cout << round(dp[N][1] * 1000) << endl;

    return 0;
}
