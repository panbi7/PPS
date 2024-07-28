#include <iostream>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

vector<int> possibleAmounts(int A, int B, int C) {
    set<tuple<int, int, int>> visited;
    set<int> results;
    queue<tuple<int, int, int>> q;
    
    q.push({0, 0, C});
    visited.insert({0, 0, C});
    
    while (!q.empty()) {
        auto [a, b, c] = q.front();
        q.pop();
        
        if (a == 0) {
            results.insert(c);
        }
        
        // Possible moves
        vector<tuple<int, int, int>> next_states = {
            {max(0, a - (B - b)), min(B, a + b), c}, // A -> B
            {max(0, a - (C - c)), b, min(C, a + c)}, // A -> C
            {min(A, b + a), max(0, b - (A - a)), c}, // B -> A
            {a, max(0, b - (C - c)), min(C, b + c)}, // B -> C
            {min(A, c + a), b, max(0, c - (A - a))}, // C -> A
            {a, min(B, c + b), max(0, c - (B - b))}  // C -> B
        };
        
        for (const auto& state : next_states) {
            if (visited.find(state) == visited.end()) {
                visited.insert(state);
                q.push(state);
            }
        }
    }
    
    return vector<int>(results.begin(), results.end());
}

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    
    vector<int> results = possibleAmounts(A, B, C);
    for (int amount : results) {
        cout << amount << " ";
    }
    cout << endl;
    
    return 0;
}
