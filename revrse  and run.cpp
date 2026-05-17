#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
const int N = 1e6+6;
const int B = 61;
 
ll a[N], a2[N];
 
ll calcor(ll* arr, int n) {
    ll curor = 0;
    for (int i = 0; i < n; ++i) curor |= arr[i];
    return curor;
}
 
signed main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ///
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        for (int i = 0; i < n; ++i) cin >> a[i];
        vector<pair<ll, int>> prec;
        int curbits = __builtin_popcountll(calcor(a, n));
        prec.push_back({0, curbits});
        for (int k = 0; k < B; ++k) if (!((calcor(a, n) >> k)&1ll)) {
            ll curops = 0;
            for (int j = 0; j < n; ++j) a2[j] = a[j];
            for (int b = k; b >= 0; --b) if (!((calcor(a2, n) >> b)&1ll)) {
                int pos = 0;
                ll bt = 1ll << b;
                for (int i = 0; i < n; ++i) {
                    if ((a2[i]&(bt-1)) > (a2[pos]&(bt-1))) pos = i;
                }
                ll ops = bt-(a2[pos]&(bt-1));
                a2[pos] += ops;
                curops += ops;
            }
            ++curbits;
            prec.push_back({curops, curbits});
        }
        while (q--) {
            ll bi;
            cin >> bi;
            cout << prev(lower_bound(prec.begin(), prec.end(), pair<ll, int>({bi+1, -1})))->second << '\n';
        }
    }
}
