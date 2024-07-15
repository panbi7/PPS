#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = s.length(); // 최악의 경우는 문자열을 그대로 사용할 때의 길이

    // 단위(unit_size)를 1부터 s.length()/2까지 시도
    for (int unit_size = 1; unit_size <= s.length() / 2; ++unit_size) {
        string compressed = "";
        string prev = s.substr(0, unit_size); // 초기 비교 문자열 설정
        int count = 1; // 현재까지 반복된 개수

        // 단위(unit_size)로 자른 문자열을 순회
        for (int j = unit_size; j <= s.length(); j += unit_size) {
            string curr = s.substr(j, unit_size); // 비교할 현재 문자열

            // 이전 문자열과 현재 문자열이 같으면 반복 개수 증가
            if (prev == curr) {
                count++;
            } else {
                // 이전 문자열과 현재 문자열이 다르면 압축 결과에 추가
                if (count > 1) {
                    compressed += to_string(count);
                }
                compressed += prev;
                prev = curr; // 다음 비교 문자열로 이동
                count = 1; // 반복 개수 초기화
            }
        }

        // 마지막 부분 처리
        if (count > 1) {
            compressed += to_string(count);
        }
        compressed += prev;

        // 가장 짧은 압축 결과를 선택
        answer = min(answer, (int)compressed.length());
    }

    return answer;
}