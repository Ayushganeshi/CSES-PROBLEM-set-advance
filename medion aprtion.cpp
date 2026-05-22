#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

void solve() {
    int n;
    cin >> n;

    vi a(n);
    for (int &x : a) cin >> x;

    set<int> vals(a.begin(), a.end());

    int ans = 0;

    for (int v : vals) {

        vector<array<int, 2>> bounds(1, {0, 0});

        for (int x : a) {
            bounds.push_back({
                bounds.back()[0] + (x <= v ? -1 : 1),
                bounds.back()[1] + (x < v ? -1 : 1)
            });
        }

        vi dp(n + 1, -1);
        dp[0] = 0;

        for (int i = 0; i <= n; i++) {

            if (dp[i] == -1) continue;

            for (int j = i + 1; j <= n; j++) {

                if ((j - i) % 2 == 1 &&
                    bounds[i][0] > bounds[j][0] &&
                    bounds[i][1] < bounds[j][1]) {

                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
        }

        ans = max(ans, dp[n]);
    }

    cout << ans << '\n';
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
