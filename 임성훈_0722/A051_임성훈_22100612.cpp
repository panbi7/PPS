#include <iostream>
#include <string>
#include <unordered_map>

int main() {
    std::string word;
    std::cin >> word;

    // 각 문자에 대해 다이얼링 시간에 대한 매핑
    std::unordered_map<char, int> dialTime = {
        {'A', 3}, {'B', 3}, {'C', 3}, // 2
        {'D', 4}, {'E', 4}, {'F', 4}, // 3
        {'G', 5}, {'H', 5}, {'I', 5}, // 4
        {'J', 6}, {'K', 6}, {'L', 6}, // 5
        {'M', 7}, {'N', 7}, {'O', 7}, // 6
        {'P', 8}, {'Q', 8}, {'R', 8}, {'S', 8}, // 7
        {'T', 9}, {'U', 9}, {'V', 9}, // 8
        {'W', 10}, {'X', 10}, {'Y', 10}, {'Z', 10} // 9
    };

    int totalTime = 0;

    // 각 문자에 대해 다이얼링 시간을 합산
    for (char ch : word) {
        totalTime += dialTime[ch];
    }

    // 총 시간을 출력
    std::cout << totalTime << std::endl;

    return 0;
}