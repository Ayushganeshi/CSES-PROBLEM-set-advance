#include <bits/stdc++.h>
using namespace std;

// Helper function to convert integer to binary string
string toBinary(long long x) {
    string s;
    while (x > 0) {
        s += (x % 2) + '0';
        x /= 2;
    }
    reverse(s.begin(), s.end());
    return s.empty() ? "0" : s;
}

// Helper function to check if a string is palindrome
bool isPalindrome(const string &s) {
    int n = s.size();
    for (int i = 0; i < n / 2; i++)
        if (s[i] != s[n - 1 - i])
            return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        long long x;
        cin >> x;
        string n = toBinary(x);
        string ans = "NO";

        for (int i = 1; i < 64; i++) {
            if ((int)n.size() <= i) {
                string w = n;
                // pad with zeros at the beginning
                w = string(i - n.size(), '0') + w;

                bool B = isPalindrome(w);
                if (i % 2 == 1)
                    B = B && (w[i / 2] == '0');

                if (B) {
                    ans = "YES";
                    break; // same as Python’s final result; no need to continue
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}

