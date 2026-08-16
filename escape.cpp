#include<bits/stdc++.h>
// #include "citymapping.h"
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,bmi,bmi2,popcnt,lzcnt")
#define all(a) a.begin(),a.end()
#define int long long
using namespace std;
void gogo() {
    int n, k;
    cin >> n >> k;
    if (k == n * n - 1) {
        cout << "NO\n";
    } else if (k == n * n) {
        cout << "YES\n";
        for (int i = 1; i <= n; i++) {
            cout << string(n, 'U') << endl;
        }
    } else {
        cout << "YES\n";
        int f = k / n;
        int r = k % n;
        for (int i = 1; i <= n; i++) {
            if (i <= f) {
                cout << string(n, 'U') << endl;
            } else if (i == f + 1 && r) {
                cout << string(r, 'U');
                if (i < n) {
                    cout << string(n - r, 'D');
                } else {
                    cout << 'R' << string(n - r - 1, 'L');
                }
                cout << endl;
            } else {
                cout << 'R' << string(n - 1, 'L') << endl;
            }
        }
    }
}
main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        gogo();
    }
}
