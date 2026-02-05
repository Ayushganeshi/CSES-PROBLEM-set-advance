#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n+1), b(n+1);
    for (int i = 1; i <= n; ++i) std::cin >> a[i];
    for (int i = 1; i <= n; ++i) std::cin >> b[i];
    std::vector<int> mp(n+1), c(n+1), R(n+1);
    for (int i = 1; i <= n; ++i) mp[b[i]] = i;
    for (int i = 1; i <= n; ++i) c[i] = mp[a[i]];
    for (int i = 1; i <= n; ++i) mp[c[i]] = i;
    std::vector<int> min(n + 1), max(n + 1);
    std::vector<std::vector<std::pair<int, int>>> rmax(2 * n + 1);
    std::vector<int> p(2 * n + 1);

    auto work = [&](auto &&self, int l, int r) -> void {
        if (l >= r) return;
        int mid = l + (r - l) / 2;
        self(self, l, mid);
        self(self, mid + 1, r);
        min[mid] = max[mid] = c[mid];
        for (int i = mid - 1; i >= l; --i) {
            min[i] = std::min(min[i + 1], c[i]);
            max[i] = std::max(max[i + 1], c[i]);
        }
        min[mid + 1] = max[mid + 1] = c[mid + 1];
        rmax[c[mid + 1] - mid - 1 + n].emplace_back(c[mid + 1], mid + 1);
        for (int i = mid + 2; i <= r; ++i) {
            min[i] = std::min(min[i - 1], c[i]);
            max[i] = std::max(max[i - 1], c[i]);
            rmax[max[i] - i + n].emplace_back(min[i], i);
        }
        for (int i = mid; i >= l; --i) {
            if (min[i] != min[i + 1]) {
                int j = i + max[i] - min[i];
                if (j > mid && j <= r && min[j] > min[i] && max[j] < max[i]) {
                    R[i] = std::max(R[i], j);
                }
                j = min[i] - i + n;
                while (p[j] < std::ssize(rmax[j]) && rmax[j][p[j]].first > min[i]) {
                    ++p[j];
                }
                if (p[j]) {
                    int k = rmax[j][p[j] - 1].second;
                    if (max[k] > max[i]) R[i] = std::max(R[i], k);
                }
            }
        }
        for (int i = mid + 1; i <= r; ++i) {
            rmax[max[i] - i + n].clear();
            p[max[i] - i + n] = 0;
        }
    };
    work(work, 1, n);

    std::stack<int> st;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        while (!st.empty() && st.top() <= i) st.pop();
        if (R[i]) {
            st.push(R[i]);
            ans = std::max(ans, int(st.size()));
        }
    }
    std::cout << (ans + 1) << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    std::cin >> T;
    while (T--) solve();
    return 0;
}
