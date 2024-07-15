#include <iostream>
#include <vector>
using namespace std;

int maxComputers(vector<int> multiTabs) {
    int totalComputers = 0;
    for (int plugs : multiTabs) {
        totalComputers += (plugs - 1);
    }
    totalComputers += 1;  // 첫 번째 멀티탭의 한 플러그는 벽 콘센트에 직접 연결
    return totalComputers;
}

int main() {
    int N;
    cin >> N;
    vector<int> multiTabs(N);
    for (int i = 0; i < N; ++i) {
        cin >> multiTabs[i];
    }
    int result = maxComputers(multiTabs);
    cout << result << endl;
    return 0;
}
