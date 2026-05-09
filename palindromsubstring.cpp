#include <iostream>
#include <string>
using namespace std;

bool checkPal(string &s, int low, int high) {
    while (low < high) {
        if (s[low] != s[high]) {
            return false;
        }
        low++;
        high--;
    }
    return true;
}
int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    int n = s.length();

    cout << "Palindromic substrings are:\n";

    // Generate all substrings
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {

            if (checkPal(s, i, j)) {
                // Print substring
                for (int k = i; k <= j; k++) {
                    cout << s[k];
                }
                cout << endl;
            }
        }
    }

    return 0;
}