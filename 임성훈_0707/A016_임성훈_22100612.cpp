#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    sort(people.begin(), people.end()); // 사람들의 몸무게 오름차순 정렬
    int left = 0;
    int right = people.size() - 1;
    int boats = 0;
    
    while (left <= right) {
        // 가장 가벼운 사람과 가장 무거운 사람을 보트에 태우기
        if (people[left] + people[right] <= limit) {
            left++; // 가장 가벼운 사람 한 명 태웠으므로 left 이동
        }
        right--; // 가장 무거운 사람 한 명 태웠으므로 right 이동
        boats++; // 보트 개수 증가
    }
    
    return boats;
}