#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs(int start, vector<vector<int>>& adj, vector<bool>& visited) {
    stack<int> s;
    s.push(start);
    visited[start] = true;

    while (!s.empty()) {
        int node = s.top();
        s.pop();

        for (int i = 0; i < adj[node].size(); ++i) {
            int next = adj[node][i];
            if (!visited[next]) {
                s.push(next);
                visited[next] = true;
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<bool> visited(n + 1, false);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, adj, visited);

    int count = 0;
    for (int i = 2; i <= n; ++i) {
        if (visited[i]) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}