#include <string>
#include <vector>

using namespace std;

int solution(vector<int> cookie) {
    int n = cookie.size();
    int maxSum = 0;

    // m을 중심으로 두 구간의 합을 비교
    for (int m = 0; m < n - 1; ++m) {
        int leftSum = cookie[m];
        int rightSum = cookie[m + 1];

        int l = m;
        int r = m + 1;

        // 두 구간의 합이 같을 때 maxSum 갱신
        while (true) {
            if (leftSum == rightSum) {
                maxSum = max(maxSum, leftSum);
            }

            // 오른쪽 구간을 확장
            if (r < n - 1 && (l == 0 || leftSum >= rightSum)) {
                ++r;
                rightSum += cookie[r];
            }
            // 왼쪽 구간을 확장
            else if (l > 0 && (r == n - 1 || leftSum < rightSum)) {
                --l;
                leftSum += cookie[l];
            }
            // 더 이상 확장할 수 없는 경우
            else {
                break;
            }
        }
    }
    return maxSum;
}