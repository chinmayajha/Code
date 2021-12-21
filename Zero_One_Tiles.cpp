
#include "bits/stdc++.h"
using namespace std;
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

int64_t n, dp[1000020];

int64_t solve2(int64_t k) {
    if (dp[k] != -1) { return dp[k]; }
    if (k == n) { return 1; }
    if (k > n) { return 0; }
    int64_t ans = (solve2(k + 1) % 15746) + (solve2(k + 2) % 15746);
    return dp[k] = (ans % 15746);
}

void solve() {
    cin >> n;
    cout << solve2(0);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    freopen("input.txt", "r", stdin);
    for (int i = 0; i < 1000021; ++i) { dp[i] = -1; }
    solve();
}
