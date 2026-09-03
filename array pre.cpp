// File F.cpp created on 26.07.2026 at 19:55:30
#include <bits/stdc++.h>

using i64 = long long;

#ifdef DEBUG
    #include "/home/ahmetalp/Desktop/Workplace/debug.h"
#else
    #define debug(...) void(23)
#endif

void solve() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> adj(N);
    for (int i = 0; i < M; ++i) {
        int U, V;
        std::cin >> U >> V;
        --U, --V;
        adj[U].emplace_back(V);
        adj[V].emplace_back(U);
    }

    auto sp = [&](int s) -> std::pair<std::vector<std::array<int, 2>>, std::vector<std::array<int, 2>>> {
        std::queue<std::pair<int, int>> que;
        std::vector<std::array<int, 2>> d(N, std::array<int, 2>{-1, -1});
        std::vector<std::array<int, 2>> p(N, std::array<int, 2>{-1, -1});
        d[s][0] = 0;
        que.emplace(s, 0);
        while (!que.empty()) {
            auto[v, t] = que.front();
            que.pop();
            for (auto u : adj[v]) {
                if (d[u][!t] == -1) {
                    d[u][!t] = d[v][t] + 1;
                    p[u][!t] = v;
                    que.emplace(u, !t);
                }
            }
        }
        return std::pair<std::vector<std::array<int, 2>>, std::vector<std::array<int, 2>>>{d, p};
    };

    auto[d0, p0] = sp(0);
    auto[dN, pN] = sp(N - 1);

    debug(d0, p0);
    debug(dN, pN);

    int ans = 2 * N + 10;
    for (int i = 0; i < N; ++i) {
        if (d0[i][0] != -1 && dN[i][0] != -1) {
            ans = std::min(ans, d0[i][0] + dN[i][0]);
        }
        if (d0[i][1] != -1 && dN[i][1] != -1) {
            ans = std::min(ans, d0[i][1] + dN[i][1]);
        }
    }
    if (ans == 2 * N + 10) {
        std::cout << "-1\n";
        return;
    }
    debug(ans);
    for (int i = 0; i < N; ++i) {
        if (d0[i][0] != -1 && dN[i][0] != -1) {
            if (ans == d0[i][0] + dN[i][0]) {
                debug(i, 0);
                std::vector<int> p;
                int u = i, t = 0;
                while (u != -1) {
                    p.emplace_back(u);
                    u = p0[u][t];
                    t = 1 - t;
                }
                std::reverse(p.begin(), p.end());
                p.pop_back();
                u = i, t = 0;
                while (u != -1) {
                    p.emplace_back(u);
                    u = pN[u][t];
                    t = 1 - t;
                }
                debug(p);
                std::cout << p.size() - 1 << '\n';
                for (auto v : p) {
                    std::cout << v + 1 << ' ';
                }
                std::cout << '\n';
                return;
            }
        }
        if (d0[i][1] != -1 && dN[i][1] != -1) {
            if (ans == d0[i][1] + dN[i][1]) {
                debug(i, 1);
                std::vector<int> p;
                int u = i, t = 1;
                while (u != -1) {
                    p.emplace_back(u);
                    u = p0[u][t];
                    t = 1 - t;
                }
                std::reverse(p.begin(), p.end());
                p.pop_back();
                u = i, t = 1;
                while (u != -1) {
                    p.emplace_back(u);
                    u = pN[u][t];
                    t = 1 - t;
                }
                std::cout << p.size() - 1 << '\n';
                for (auto v : p) {
                    std::cout << v + 1 << ' ';
                }
                std::cout << '\n';
                return;
            }
        }
    }
    
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int TT = 1; std::cin >> TT;
    for (int i = 1; i <= TT; ++i) {
        solve();
        debug();
    }

    return 0;
}
