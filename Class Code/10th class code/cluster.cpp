#include <bits/stdc++.h>

using namespace std;

const int N = 20;
const int INF = 1e8 + 69;

int n, adj[N][N], f[1 << N], cost[1 << N];

/// bitmask --> subset
/// mask --> 00110 | 10000 = 2^5 - 1
int call (int mask) {
    if (mask == 0) return 0;
    if (f[mask] != -1) return f[mask];
    int ret = -INF;
    for (int sub = mask; sub > 0; sub = (sub - 1) & mask) {
        ret = max(ret, cost[sub] + call(mask ^ sub));
    }
    return f[u][mask] = ret;
}

int main() {
    for (int mask = 0; mask < 1 << n; ++mask) {
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if ((mask & 1 << i) and (mask & 1 << j)) {
                    cost[mask] += adj[i][j];
                }
            }
        }
    }
    memset(f, -1, sizeof f);
    int ret = call((1 << n) - 1);
    cout << ret << '\n';
    return 0;
}

