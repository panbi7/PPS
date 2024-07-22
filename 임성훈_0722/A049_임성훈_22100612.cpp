#include <iostream>
#include <string>

bool containsVowel(const std::string &password) {
    for (char ch : password) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            return true;
        }
    }
    return false;
}

bool hasThreeConsecutive(const std::string &password) {
    int vowelCount = 0, consonantCount = 0;

    for (size_t i = 0; i < password.length(); ++i) {
        char ch = password[i];

        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            vowelCount++;
            consonantCount = 0;
        } else {
            consonantCount++;
            vowelCount = 0;
        }

        if (vowelCount >= 3 || consonantCount >= 3) {
            return true;
        }
    }
    return false;
}

bool hasInvalidRepeat(const std::string &password) {
    for (size_t i = 0; i < password.length(); ++i) {
        if (i > 0 && password[i] == password[i-1] && !(password[i] == 'e' && password[i-1] == 'e') && !(password[i] == 'o' && password[i-1] == 'o')) {
            return true;
        }
    }
    return false;
}

bool isAcceptable(const std::string &password) {
    return containsVowel(password) && !hasThreeConsecutive(password) && !hasInvalidRepeat(password);
}

int main() {
    std::string password;

    while (std::cin >> password && password != "end") {
        if (isAcceptable(password)) {
            std::cout << "<" << password << "> is acceptable." << std::endl;
        } else {
            std::cout << "<" << password << "> is not acceptable." << std::endl;
        }
    }

    return 0;
}