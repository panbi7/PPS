#include <iostream>
#include <string>
using namespace std;

bool isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

int countVowels(string s) {
    int count = 0;
    for (char c : s) {
        if (isVowel(c)) {
            count++;
        }
    }
    return count;
}

bool halvesAreAlike(string s) {
    int n = s.length();
    string a = s.substr(0, n/2);
    string b = s.substr(n/2, n/2);
    
    int countA = countVowels(a);
    int countB = countVowels(b);
    
    return countA == countB;
}

int main() {
    // Example usage:
    cout << "Is 'book' alike? " << (halvesAreAlike("book") ? "Yes" : "No") << endl; // Output: true
    cout << "Is 'textbook' alike? " << (halvesAreAlike("textbook") ? "Yes" : "No") << endl; // Output: false
    
    return 0;
}
