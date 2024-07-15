#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    vector<int> B(N);

    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    for (int i = 0; i < N; ++i) {
        cin >> B[i];
    }

    // A를 오름차순으로 정렬
    sort(A.begin(), A.end());

    // B를 내림차순으로 정렬 (A를 오름차순으로 정렬했기 때문에 B도 맞춰서 정렬)
    sort(B.rbegin(), B.rend());

    // A를 정렬한 상태에서 B의 원소와 순서대로 곱하여 S를 계산
    int S = 0;
    for (int i = 0; i < N; ++i) {
        S += A[i] * B[i];
    }

    cout << S << endl;

    return 0;
}
