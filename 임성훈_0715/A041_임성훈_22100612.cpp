#include <iostream>
#include <string>
#include <cctype> // for toupper and tolower
using namespace std;

string solution(string s) {
    int n = s.length();
    bool capitalizeNext = true;
    
    for (int i = 0; i < n; ++i) {
        if (isspace(s[i])) {
            capitalizeNext = true; // next character should be capitalized
        } else {
            if (capitalizeNext) {
                s[i] = toupper(s[i]);
                capitalizeNext = false; // reset for the next word
            } else {
                s[i] = tolower(s[i]);
            }
        }
    }
    
    return s;
}

int main() {
    // Example usage:
    cout << solution("3people unFollowed me") << endl; // Output: "3people Unfollowed Me"
    cout << solution("for the last week") << endl;    // Output: "For The Last Week"
    
    return 0;
}
