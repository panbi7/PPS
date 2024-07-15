#include <iostream>
using namespace std;

int main() {
    int num1, num2, num3, num4, num5;
    cin >> num1 >> num2 >> num3 >> num4 >> num5;

    int sum = num1 * num1 + num2 * num2 + num3 * num3 + num4 * num4 + num5 * num5;
    int result = sum % 10;

    cout << result << endl;

    return 0;
}