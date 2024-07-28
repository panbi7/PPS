#include <iostream>
#include <vector>
using namespace std;

int N;
vector<string> grid;
vector<vector<bool>> visited;

// Directions for moving in the grid: right, down, left, up
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

// DFS function to mark the visited cells
void dfs(int x, int y, char color) {
    visited[x][y] = true;
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[nx][ny] && grid[nx][ny] == color) {
            dfs(nx, ny, color);
        }
    }
}

int countRegions(bool isColorblind) {
    visited.assign(N, vector<bool>(N, false));
    int regions = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (!visited[i][j]) {
                regions++;
                if (isColorblind && (grid[i][j] == 'R' || grid[i][j] == 'G')) {
                    dfs(i, j, 'R');
                } else {
                    dfs(i, j, grid[i][j]);
                }
            }
        }
    }

    return regions;
}

int main() {
    cin >> N;
    grid.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> grid[i];
    }

    // Count regions for normal vision
    int normalCount = countRegions(false);

    // Modify the grid for colorblind scenario
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (grid[i][j] == 'G') {
                grid[i][j] = 'R';
            }
        }
    }

    // Count regions for colorblind vision
    int colorblindCount = countRegions(true);

    cout << normalCount << " " << colorblindCount << endl;

    return 0;
}
