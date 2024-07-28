#include <iostream>
#include <vector>
#include <set>
using namespace std;

const int N = 5;
int grid[N][N];
set<string> unique_numbers;

int dx[4] = {1, -1, 0, 0}; // Directions for row movement
int dy[4] = {0, 0, 1, -1}; // Directions for column movement

void dfs(int x, int y, string current_number) {
    // If the length of the current number is 6, add to the set and return
    if (current_number.length() == 6) {
        unique_numbers.insert(current_number);
        return;
    }
    
    // Try all 4 possible movements
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        // Check boundaries
        if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
            dfs(nx, ny, current_number + to_string(grid[nx][ny]));
        }
    }
}

int main() {
    // Input the grid
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> grid[i][j];
        }
    }
    
    // Perform DFS from each cell
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            dfs(i, j, to_string(grid[i][j]));
        }
    }
    
    // Output the number of unique 6-digit numbers
    cout << unique_numbers.size() << endl;
    
    return 0;
}
