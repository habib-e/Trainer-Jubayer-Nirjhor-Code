#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
const int MOD = 1e9 + 7;

/// a^e mod MOD
long long bigMod (long long a, long long e) {
    if (e == -1) e = MOD - 2;
    /// if (e < 0) e += MOD - 1;
    long long ret = 1;
    while (e) {
        if (e & 1) ret = ret * a % MOD;
        a = a * a % MOD, e >>= 1;
    }
    return ret;
}

int t, cases, n, b;
long long fac[N], inv[N];

/// power of p in x!
/// = floor(x/p) + floor(x/p^2) + floor(x/p^3) + ...
/// floor(x/p^2) = floor(floor(x/p)/p)
int getPower (int x, int p) {
    int ret = 0;
    while (x >= p) x /= p, ret += x;
    return ret;
}

/// C(x, y) = x!/[y! (x-y)!] = fac[x] * inv[y] * inv[x-y]
long long comb (int x, int y) {
    if (x < y or y < 0) return 0;
    return fac[x] * inv[y] % MOD * inv[x - y] % MOD;
}

int main() {
    /// i! = i * (i-1)! --> fac[i] = i * fac[i-1]
    fac[0] = 1;
    for (int i = 1; i < N; ++i) fac[i] = i * fac[i - 1] % MOD;
    /// inv[N-1] = 1/fac[N-1] = 1/(N-1)!
    /// 1/(i-1)! = i * 1/i! --> inv[i-1] = i * inv[i]
    inv[N - 1] = bigMod(fac[N - 1], -1);
    for (int i = N - 1; i; --i) inv[i - 1] = i * inv[i] % MOD;

    cin >> t;
    while (t--) {
        cin >> n >> b;
        /// product of (i+1)!^C(n-1, i)
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = (ans + getPower(i + 1, b) * comb(n - 1, i)) % MOD;
        }
        printf("Case %d: %lld\n", ++cases, ans);
    }
    return 0;
}
//https://algo.codemarshal.org/contests/ruet-2022/problems/E