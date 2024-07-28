#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
    
    Employee(int id, int importance, vector<int> subordinates)
        : id(id), importance(importance), subordinates(subordinates) {}
};

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> employeeMap;
        for (auto e : employees) {
            employeeMap[e->id] = e;
        }
        return dfs(employeeMap, id);
    }
    
private:
    int dfs(unordered_map<int, Employee*> &employeeMap, int id) {
        Employee* employee = employeeMap[id];
        int totalImportance = employee->importance;
        for (int subId : employee->subordinates) {
            totalImportance += dfs(employeeMap, subId);
        }
        return totalImportance;
    }
};

int main() {
    vector<Employee*> employees = {
        new Employee(1, 5, {2, 3}),
        new Employee(2, 3, {}),
        new Employee(3, 3, {})
    };
    int id = 1;

    Solution solution;
    int totalImportance = solution.getImportance(employees, id);

    cout << "Total Importance: " << totalImportance << endl;

    // Clean up dynamically allocated memory
    for (auto e : employees) {
        delete e;
    }

    return 0;
}
