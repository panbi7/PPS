#include <iostream>
#include <string>

class Solution {
public:
    bool checkRecord(string s) {
        int absentCount = 0;
        int lateStreak = 0;

        for (size_t i = 0; i < s.length(); ++i) {
            char c = s[i];

            if (c == 'A') {
                absentCount++;
                if (absentCount >= 2) {
                    return false;
                }
            }
        
            if (c == 'L') {
                lateStreak++;
                if (lateStreak >= 3) {
                    return false;
                }
            } else {
                lateStreak = 0;
            }
        }
        return true;
    }
};

int main() {
    std::string s1 = "PPALLP";
    std::string s2 = "PPALLL";

    std::cout << (checkRecord(s1) ? "true" : "false") << std::endl; // true
    std::cout << (checkRecord(s2) ? "true" : "false") << std::endl; // false

    return 0;
}   