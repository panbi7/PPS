#include <iostream>
#include <vector>
using namespace std;

bool lemonadeChange(vector<int>& bills) {
    int five = 0, ten = 0;
    for (int bill : bills) {
        if (bill == 5) {
            five++;
        } else if (bill == 10) {
            if (five == 0) {
                return false;
            }
            five--;
            ten++;
        } else { // bill == 20
            if (ten > 0 && five > 0) {
                ten--;
                five--;
            } else if (five >= 3) {
                five -= 3;
            } else {
                return false;
            }
        }
    }
    return true;
}

int main() {
    vector<int> bills1 = {5, 5, 5, 10, 20};
    vector<int> bills2 = {5, 5, 10, 10, 20};

    cout << "Test case 1: " << (lemonadeChange(bills1) ? "true" : "false") << endl;
    cout << "Test case 2: " << (lemonadeChange(bills2) ? "true" : "false") << endl;

    return 0;
}
