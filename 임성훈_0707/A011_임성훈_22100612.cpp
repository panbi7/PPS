#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct Stage {
    int number;
    double failure_rate;
};

bool compare(Stage a, Stage b) {
    if (a.failure_rate == b.failure_rate) {
        return a.number < b.number;
    } else {
        return a.failure_rate > b.failure_rate;
    }
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<Stage> failure_rates;

    // 각 스테이지 별 실패율 계산
    for (int i = 1; i <= N; ++i) {
        int total_players = 0;
        int not_cleared_players = 0;
        
        // 현재 스테이지에 도달한 플레이어 수와 아직 클리어하지 못한 플레이어 수 계산
        for (int j = 0; j < stages.size(); ++j) {
            if (stages[j] >= i) {
                total_players++;
                if (stages[j] == i) {
                    not_cleared_players++;
                }
            }
        }
        
        // 실패율 계산
        double failure_rate = (total_players == 0) ? 0 : (double)not_cleared_players / total_players;
        
        // 스테이지와 실패율을 저장
        failure_rates.push_back({i, failure_rate});
    }

    // 실패율을 기준으로 내림차순 정렬
    sort(failure_rates.begin(), failure_rates.end(), compare);

    // 정렬된 결과를 answer에 담기
    for (auto stage : failure_rates) {
        answer.push_back(stage.number);
    }

    return answer;
}