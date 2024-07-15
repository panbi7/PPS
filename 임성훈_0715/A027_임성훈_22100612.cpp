#include <iostream>
#include <string>
#include <stack>

using namespace std;

string solution(string number, int k) {
    string result = "";
    int n = number.size();
    int keep = n - k; // 최종적으로 남길 숫자의 개수

    for (char c : number) {
        // 현재 문자가 스택의 top보다 크고 제거할 수 있는 문자가 남아있다면 스택에서 pop
        while (!result.empty() && result.back() < c && k > 0) {
            result.pop_back();
            k--;
        }
        result.push_back(c);
    }

    // 필요한 만큼의 문자를 남긴다.
    result = result.substr(0, keep);
    return result;
}

int main() {
    string number1 = "1924";
    int k1 = 2;
    cout << "Result 1: " << solution(number1, k1) << endl; // "94"

    string number2 = "1231234";
    int k2 = 3;
    cout << "Result 2: " << solution(number2, k2) << endl; // "3234"

    string number3 = "4177252841";
    int k3 = 4;
    cout << "Result 3: " << solution(number3, k3) << endl; // "775841"

    return 0;
}
