#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void dfs(int v, vector<vector<int>>& graph, vector<bool>& visited, vector<int>& result) {
    visited[v] = true;
    result.push_back(v);
    for (int next : graph[v]) {
        if (!visited[next]) {
            dfs(next, graph, visited, result);
        }
    }
}

void bfs(int v, vector<vector<int>>& graph, vector<bool>& visited, vector<int>& result) {
    queue<int> q;
    q.push(v);
    visited[v] = true;
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        result.push_back(current);
        for (int next : graph[current]) {
            if (!visited[next]) {
                q.push(next);
                visited[next] = true;
            }
        }
    }
}

int main() {
    int N, M, V;
    cin >> N >> M >> V;

    vector<vector<int>> graph(N + 1);
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // 각 인접 리스트를 정렬하여 작은 번호의 정점부터 방문하도록 설정
    for (int i = 1; i <= N; ++i) {
        sort(graph[i].begin(), graph[i].end());
    }

    // DFS 결과
    vector<int> dfs_result;
    vector<bool> visited(N + 1, false);
    dfs(V, graph, visited, dfs_result);

    // BFS 결과
    vector<int> bfs_result;
    fill(visited.begin(), visited.end(), false);  // visited 배열 초기화
    bfs(V, graph, visited, bfs_result);

    // DFS 결과 출력
    for (int v : dfs_result) {
        cout << v << " ";
    }
    cout << endl;

    // BFS 결과 출력
    for (int v : bfs_result) {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}
