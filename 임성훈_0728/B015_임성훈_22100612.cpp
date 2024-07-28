#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    
    int s;
    cin >> s;
    s--; // 0-based indexing
    
    vector<bool> visited(n, false);
    queue<int> q;
    
    q.push(s);
    visited[s] = true;
    int count = 0;
    
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        count++;
        
        // Try to move to the left
        int left = current - A[current];
        if (left >= 0 && !visited[left]) {
            visited[left] = true;
            q.push(left);
        }
        
        // Try to move to the right
        int right = current + A[current];
        if (right < n && !visited[right]) {
            visited[right] = true;
            q.push(right);
        }
    }
    
    cout << count << endl;
    
    return 0;
}
