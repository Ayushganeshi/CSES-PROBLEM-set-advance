#include <bits/stdc++.h>
using namespace std;

//Author:Ayush kumar Gupta
//CHESS $$$ CODEE

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &i : a) {
        cin >> i;
    }

    int cnt = 0;
    for(int i = 0; i < n; i++) {
        cnt += (a[i] % 2 != (i + 1) % 2);
    }

    cout << (cnt == 0 || cnt == n? "YES" : "NO") << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int ttt = 1;
    cin >> ttt;
    while(ttt--) {
        solve();
    }
}
