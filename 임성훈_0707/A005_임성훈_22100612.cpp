#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;

    for (auto& tree : skill_trees) {
        bool possible = true;
        int idx = 0; // 선행 스킬 순서를 검사하기 위한 인덱스

        for (char s : tree) {
            if (skill.find(s) != string::npos) { // 스킬트리에 있는 스킬이 선행 스킬 순서에 있는 경우
                if (s != skill[idx]) { // 현재 배워야 할 스킬이 선행 스킬 순서와 다른 경우
                    possible = false;
                    break;
                } else { // 현재 배울 스킬이 올바른 경우 다음 선행 스킬을 검사하기 위해 인덱스 증가
                    idx++;
                }
            }
        }

        if (possible) {
            answer++;
        }
    }

    return answer;
}