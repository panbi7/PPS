#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

bool solution(string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);

    int p_count = count(s.begin(), s.end(), 'p');
    int y_count = count(s.begin(), s.end(), 'y');

    return p_count == y_count;
}