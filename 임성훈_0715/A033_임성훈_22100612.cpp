#include <iostream>
using namespace std;

int main() {
    const int NUM_PARTICIPANTS = 5;
    const int NUM_SCORES = 4;
    
    int scores[NUM_PARTICIPANTS][NUM_SCORES];
    
    // 입력 받기
    for (int i = 0; i < NUM_PARTICIPANTS; ++i) {
        for (int j = 0; j < NUM_SCORES; ++j) {
            cin >> scores[i][j];
        }
    }
    
    int maxScore = 0;
    int winner = -1;
    
    // 각 참가자의 점수 계산
    for (int i = 0; i < NUM_PARTICIPANTS; ++i) {
        int totalScore = 0;
        for (int j = 0; j < NUM_SCORES; ++j) {
            totalScore += scores[i][j];
        }
        // 최고 점수인지 확인
        if (totalScore > maxScore) {
            maxScore = totalScore;
            winner = i + 1; // 참가자 번호는 1부터 시작하므로 i+1
        }
    }
    
    // 우승자 번호와 그의 점수 출력
    cout << winner << " " << maxScore << endl;
    
    return 0;
}
