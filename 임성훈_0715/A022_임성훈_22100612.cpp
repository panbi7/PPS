#include <iostream>
#include <vector>
using namespace std;

// 통화 시간을 받아서 영식 요금제를 계산하는 함수
int calculateYongsikCost(const vector<int>& callTimes) {
    int cost = 0;
    for (int time : callTimes) {
        cost += ((time / 30) + 1) * 10;
    }
    return cost;
}

// 통화 시간을 받아서 민식 요금제를 계산하는 함수
int calculateMinsikCost(const vector<int>& callTimes) {
    int cost = 0;
    for (int time : callTimes) {
        cost += ((time / 60) + 1) * 15;
    }
    return cost;
}

int main() {
    int N;
    cin >> N;
    vector<int> callTimes(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> callTimes[i];
    }

    int yongsikCost = calculateYongsikCost(callTimes);
    int minsikCost = calculateMinsikCost(callTimes);

    if (yongsikCost < minsikCost) {
        cout << "Y " << yongsikCost << endl;
    } else if (minsikCost < yongsikCost) {
        cout << "M " << minsikCost << endl;
    } else {
        cout << "Y M " << yongsikCost << endl;
    }

    return 0;
}
