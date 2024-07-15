#include <iostream>
#include <set>
using namespace std;

int main() {
    const int SIZE = 10;
    const int MOD = 42;
    
    // 입력 받기
    int numbers[SIZE];
    for (int i = 0; i < SIZE; ++i) {
        cin >> numbers[i];
    }
    
    // 각 숫자를 42로 나눈 나머지 구하기
    set<int> remainderSet; // 중복을 허용하지 않는 자료구조인 set 사용
    for (int i = 0; i < SIZE; ++i) {
        int remainder = numbers[i] % MOD;
        remainderSet.insert(remainder); // set에 나머지 값 추가
    }
    
    // 서로 다른 나머지의 개수 출력
    cout << remainderSet.size() << endl;
    
    return 0;
}
