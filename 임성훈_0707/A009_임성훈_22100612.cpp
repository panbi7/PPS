#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    // 문자열 s의 길이가 4 또는 6인지 확인
    if (s.length() != 4 && s.length() != 6)
        return false;
    
    // 모든 문자가 숫자인지 확인
    for (char c : s) {
        if (c < '0' || c > '9')
            return false;
    }
    
    return true;
}