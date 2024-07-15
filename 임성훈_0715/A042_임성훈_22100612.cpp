#include <iostream>
#include <string>
using namespace std;

bool backspaceCompare(string s, string t) {
    int i = s.size() - 1, j = t.size() - 1;
    int skipS = 0, skipT = 0;

    while (i >= 0 || j >= 0) {
        // Find position of next valid character in s
        while (i >= 0) {
            if (s[i] == '#') {
                skipS++;
                i--;
            } else if (skipS > 0) {
                skipS--;
                i--;
            } else {
                break;
            }
        }
        
        // Find position of next valid character in t
        while (j >= 0) {
            if (t[j] == '#') {
                skipT++;
                j--;
            } else if (skipT > 0) {
                skipT--;
                j--;
            } else {
                break;
            }
        }
        
        // Compare characters at current positions
        if (i >= 0 && j >= 0 && s[i] != t[j]) {
            return false;
        }
        
        // If one string is ended and the other still has characters, not equal
        if ((i >= 0) != (j >= 0)) {
            return false;
        }
        
        i--;
        j--;
    }
    
    return true;
}

int main() {
    // Example usage:
    cout << boolalpha; // to print 'true' or 'false' instead of '1' or '0'
    cout << backspaceCompare("ab#c", "ad#c") << endl; // Output: true
    cout << backspaceCompare("ab##", "c#d#") << endl; // Output: true
    cout << backspaceCompare("a#c", "b") << endl;    // Output: false
    
    return 0;
}