#include <vector>
#include <iostream>

int solution(const std::vector<std::vector<int>>& board, const std::vector<int>& moves) {
    int n = board.size(); // board의 크기
    std::vector<int> basket; // 바구니를 담을 벡터
    int removed = 0; // 제거된 인형의 개수

    // 각 열에서 가장 위에 있는 인형을 찾기 위한 변수
    std::vector<int> top(n, -1);

    // 열별로 가장 위에 있는 인형의 인덱스를 찾기
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < n; ++i) {
            if (board[i][j] != 0) {
                top[j] = i;
                break;
            }
        }
    }

    // moves 배열을 처리하여 인형을 바구니에 추가
    for (int move : moves) {
        int col = move - 1; // 1-based index를 0-based index로 변환

        // 인형이 없는 열에 대해 무시
        if (col < 0 || col >= n || top[col] == -1) {
            continue;
        }

        // 가장 위의 인형을 찾는다
        int row = top[col];
        int doll = board[row][col];

        // 바구니에 추가하거나 제거
        if (basket.empty() || basket.back() != doll) {
            basket.push_back(doll);
        } else {
            basket.pop_back(); // 연속된 인형을 제거한다
            removed += 2;
        }

        // 다음으로 가장 위의 인형을 찾기 위해 top을 업데이트
        bool found = false;
        for (int i = row + 1; i < n; ++i) {
            if (board[i][col] != 0) {
                top[col] = i;
                found = true;
                break;
            }
        }
        if (!found) {
            top[col] = -1; // 더 이상 인형이 없는 열을 표시
        }
    }

    return removed;
}

int main() {
    std::vector<std::vector<int>> board = {
        {0,0,0,0,0},
        {0,0,1,0,3},
        {0,2,5,0,1},
        {4,2,4,4,2},
        {3,5,1,3,1}
    };
    std::vector<int> moves = {1,5,3,5,1,2,1,4};

    std::cout << solution(board, moves) << std::endl;

    return 0;
}