#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T; // 테스트 케이스의 수
    
    while (T--) {
        int k, n;
        cin >> k >> n; // 입력: k층, n호
        
        // 각 층별 호실의 사람 수 배열 생성 및 초기화
        int residents[15][15] = {0}; // 최대 14층, 14호
        
        // 0층 초기화
        for (int i = 1; i <= 14; ++i) {
            residents[0][i] = i; // 0층 i호에는 i명이 산다
        }
        
        // k층까지 채우기
        for (int i = 1; i <= k; ++i) { // 각 층
            for (int j = 1; j <= n; ++j) { // 각 호
                residents[i][j] = residents[i-1][j] + residents[i][j-1];
            }
        }
        
        // k층의 n호 거주민 수 출력
        cout << residents[k][n] << endl;
    }
    
    return 0;
}
