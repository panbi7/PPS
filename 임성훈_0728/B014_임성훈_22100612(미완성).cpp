#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y, int w, int h) {
    // 8방향으로 이동할 좌표 (상, 하, 좌, 우, 대각선)
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, 
                                         {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    
    while (!q.empty()) {
        auto [cx, cy] = q.front();
        q.pop();
        
        for (auto [dx, dy] : directions) {
            int nx = cx + dx;
            int ny = cy + dy;
            
            if (nx >= 0 && nx < h && ny >= 0 && ny < w && !visited[nx][ny] && grid[nx][ny] == 1) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

int count_islands(vector<vector<int>>& grid, int w, int h) {
    vector<vector<bool>> visited(h, vector<bool>(w, false));
    int island_count = 0;
    
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (grid[i][j] == 1 && !visited[i][j]) {
                bfs(grid, visited, i, j, w, h);
                island_count++;
            }
        }
    }
    
    return island_count;
}

int main() {
    while (true) {
        int w, h;
        cin >> w >> h;
        if (w == 0 && h == 0) break;
        
        vector<vector<int>> grid(h, vector<int>(w));
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                cin >> grid[i][j];
            }
        }
        
        cout << count_islands(grid, w, h) << endl;
    }
    
    return 0;
}
