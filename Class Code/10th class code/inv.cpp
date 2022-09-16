#include <bits/stdc++.h>

using namespace std;

const int N = 105;
const int K = 505;
const int MOD = 1e9 + 7;

int n, k, f[N][K], pref[K];

///  k --> 0 1 2
/// n   0
///i-1  1  12
///  i  2       f[i][j]

int main() {
    cin >> n >> k;
    for (int i = 0; i <= n; ++i) {
        if (i > 0) {
            pref[0] = f[i - 1][0];
            for (int j = 1; j <= k; ++j) {
                pref[j] = (pref[j - 1] + f[i - 1][j]);
                pref[j] %= MOD;
            }
        }
        for (int j = 0; j <= k; ++j) {
            if (i == 0) {
                /// empty permutation
                if (j == 0) f[i][j] = 1;
                else f[i][j] = 0;
                continue;
            }
            /// f[i][j] = 1..i boshano hoy nai
            ///           i+1...n done
            ///           i ke i possible gap e boshano jay
            /// f[i-1][j-l] --> l=0...min(i-1,j)
            /// j-l = j,   j-l = j-min(i-1,j)
            /// f[i - 1][j-min(i-1,j).....j]
            int lo = j - min(i - 1, j), hi = j;
            /// f[i - 1][lo...hi]
            f[i][j] = pref[hi];
            if (lo > 0) f[i][j] -= pref[lo - 1];
            f[i][j] %= MOD;
            /// l < i --> l <= i-1
            /// l <= j ---> 0 <= l <= min(i-1, j)
            /// l=0 --> j-l = j
            /// l=min(i-1, j) --> j-l = j-min(i-1, j)
////            for (int l = 0; l < i and l <= j; ++l) {
////                f[i][j] += f[i - 1][j - l];
////                f[i][j] %= MOD;
////            }
        }
    }
    int sum = 0;
    for (int i = 0; i <= n * (n - 1) / 2; ++i) sum += f[n][i];
    cout << sum << '\n';
    cout << f[n][k] << '\n';
    return 0;
}

