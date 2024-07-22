#include <iostream>
#include <string>
#include <unordered_map>
#include <cctype>

using namespace std;

class Solution {
public:
    char findMostA(const string& s) {
        unordered_map<char, int> charCount;
        char mostFrequentChar = '\0';
        int maxCount = 0;
        bool isTie = false;

        for (size_t i = 0; i < s.length(); ++i) {
            charCount[s[i]]++;
        }

        unordered_map<char, int>::iterator it;
        for (it = charCount.begin(); it != charCount.end(); ++it) {
            if (it->second > maxCount) {
                maxCount = it->second;
                mostFrequentChar = it->first;
                isTie = false;
            } else if (it->second == maxCount) {
                isTie = true; // 등장 횟수가 같은 문자가 발견된 경우
            }
        }

        if (isTie) {
            return '?';
        }

        return mostFrequentChar;
    }
};

string toUpperCase(const string& s) {
    string result = s;
    for (size_t i = 0; i < result.length(); ++i) {
        result[i] = static_cast<char>(toupper(result[i]));
    }
    return result;
}

int main() {
    Solution sol;
    string s;
    cin >> s;

    string upperS = toUpperCase(s);

    char result = sol.findMostA(upperS);
    cout << result << endl;

    return 0;
}
