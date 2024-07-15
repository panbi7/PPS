#include <iostream>
#include <iomanip> // 소수점 출력을 위해 필요
using namespace std;

double calculate_result(string expression) {
    double number;
    char op1, op2, op3;
    sscanf(expression.c_str(), "%lf %c %c %c", &number, &op1, &op2, &op3);
    
    if (op1 == '@') {
        number *= 3;
    } else if (op1 == '%') {
        number += 5;
    } else if (op1 == '#') {
        number -= 7;
    }
    
    if (op2 == '@') {
        number *= 3;
    } else if (op2 == '%') {
        number += 5;
    } else if (op2 == '#') {
        number -= 7;
    }
    
    if (op3 == '@') {
        number *= 3;
    } else if (op3 == '%') {
        number += 5;
    } else if (op3 == '#') {
        number -= 7;
    }
    
    return number;
}

int main() {
    int T;
    cin >> T;
    cin.ignore(); // 버퍼 비우기
    
    while (T--) {
        string expression;
        getline(cin, expression);
        
        double result = calculate_result(expression);
        
        // 소수점 둘째 자리까지 출력
        cout << fixed << setprecision(2) << result << endl;
    }
    
    return 0;
}