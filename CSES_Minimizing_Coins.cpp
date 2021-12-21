// https://cses.fi/problemset/task/1634
#include "bits/stdc++.h"
using namespace std;

int n, x, dp[10000019], a[10000019];

int main() {
    cin >> n >> x;
    for (int i = 0; i < n; ++i) { cin >> a[i]; }
    for (int i = 0; i < int(1e6 + 7); ++i) { dp[i] = int(1e9 + 7); }
    dp[0] = 0;
    for (int i = 1; i <= x; ++i) {
        int ans = int(1e9 + 7);
        for (int j = 0; j < n; ++j) {
            if (a[j] > i) { continue; }
            ans = min(ans, 1 + dp[i - a[j]]);
        }
        dp[i] = ans;
    }

    cout << (dp[x] == int(1e9 + 7) ? -1 : dp[x]);
}