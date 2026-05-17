#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCases;
    cin >> testCases;

    while (testCases--) {

        int n;
        cin >> n;

        string s, t;
        cin >> s >> t;

        string firstBracket = "";
        string secondBracket = "";

        bool turn = true;

        // Create two bracket strings
        for (int i = 0; i < n; i++) {

            // If both characters are same
            if (s[i] == t[i]) {
                firstBracket += s[i];
                secondBracket += t[i];
            }

            // If characters are different
            else {

                if (turn) {
                    firstBracket += '(';
                    secondBracket += ')';
                }
                else {
                    firstBracket += ')';
                    secondBracket += '(';
                }

                // Change turn
                turn = !turn;
            }
        }

        int balance1 = 0;
        int balance2 = 0;

        bool possible = true;

        // Check whether both bracket sequences are valid
        for (int i = 0; i < n; i++) {

            // For first string
            if (firstBracket[i] == '(')
                balance1++;
            else
                balance1--;

            // For second string
            if (secondBracket[i] == '(')
                balance2++;
            else
                balance2--;

            // Invalid if balance becomes negative
            if (balance1 < 0 || balance2 < 0) {
                possible = false;
            }
        }

        // At the end balance must be 0
        if (balance1 != 0 || balance2 != 0) {
            possible = false;
        }

        if (possible)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
