#include <iostream>
#include <vector>
#include <string>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return ""; // If the array is empty, return empty string
    
    string prefix = "";
    int n = strs.size();
    int minLen = INT_MAX; // Initialize minimum length to a large number
    
    // Find the minimum length of strings in the array
    for (int i = 0; i < n; ++i) {
        if (strs[i].length() < minLen) {
            minLen = strs[i].length();
        }
    }
    
    // Compare characters up to the minimum length
    for (int i = 0; i < minLen; ++i) {
        char currentChar = strs[0][i]; // Character in the first string
        bool allMatch = true;
        
        // Check if current character matches in all strings
        for (int j = 1; j < n; ++j) {
            if (strs[j][i] != currentChar) {
                allMatch = false;
                break;
            }
        }
        
        if (allMatch) {
            prefix += currentChar; // Append to the prefix if all characters match
        } else {
            break; // Stop as soon as characters don't match
        }
    }
    
    return prefix;
}

int main() {
    vector<string> strs1 = {"flower","flow","flight"};
    cout << longestCommonPrefix(strs1) << endl; // Output: "fl"
    
    vector<string> strs2 = {"dog","racecar","car"};
    cout << longestCommonPrefix(strs2) << endl; // Output: ""
    
    return 0;
}