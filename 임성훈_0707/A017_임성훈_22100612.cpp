#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    string N;
    cin >> N;
    
    int count[10] = {0}; // 각 숫자의 필요한 개수를 저장할 배열
    
    // 각 숫자의 등장 횟수 계산
    for (char c : N) {
        int num = c - '0';
        count[num]++;
    }
    
    // 6과 9는 서로 대체 가능하므로 더한 후 2로 나누어 올림 처리
    int sixNineSum = count[6] + count[9];
    count[6] = 0;
    count[9] = 0;
    int sets = ceil(sixNineSum / 2.0);
    
    // 나머지 숫자들 중 최대 개수가 필요한 세트의 개수
    for (int i = 0; i <= 9; ++i) {
        sets = max(sets, count[i]);
    }
    
    cout << sets << endl;
    
    return 0;
}
