#include <bits/stdc++.h>

using namespace std;

const int N = 20;
const int INF = 1e8 + 69;

/// left i --> right j cost = adj[i][j]
int n, adj[N][N], f[N][1 << N];

/// bitmask --> subset
/// mask --> 00110 | 10000 = 2^5 - 1
int call (int u, int mask) {
    if (mask == (1 << n) - 1) return 0;
    if (f[u][mask] != -1) return f[u][mask];
    int ret = INF;
    for (int v = 0; v < n; ++v) {
        if (adj[u][v] == 0) continue;
        if (mask & 1 << v) continue;
        /// v valid --> adjacent to u, not in mask
        ret = min(ret, adj[u][v] + call(u + 1, mask | 1 << v));
    }
    return f[u][mask] = ret;
}

int main() {
    memset(f, -1, sizeof f);
    int ret = call(0, 0);
    cout << ret << '\n';
    return 0;
}

