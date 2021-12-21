
#include "bits/stdc++.h"
using namespace std;

int64_t dp[200010], n, x, cnt;
int64_t a[200010];
map<int64_t, int64_t> mp;

int main() {
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) { cin >> a[i]; }
    dp[1] = a[1];
    for (int i = 2; i <= n; ++i) { dp[i] = a[i] + dp[i - 1]; }

    mp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        if (mp[dp[i] - x]) { cnt += mp[dp[i] - x]; }
        mp[dp[i]]++;
    }
    cout << cnt;
}