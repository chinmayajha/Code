
#include "bits/stdc++.h"
using namespace std;
#define int long long

int n, w, dp[105][100010];
vector<pair<int, int>> a(105);
// weight, value

int solve2(int index, int sum) {
    if(index == n) return 0;
    if(dp[index][sum] != -1) return dp[index][sum];
    int ans;
    if(sum + a[index].first <= w) {
        ans = max(solve2(index + 1, sum + a[index].first) + a[index].second, solve2(index + 1, sum));
    } else {
        ans = solve2(index + 1, sum);
    }
    return dp[index][sum] = ans;
}

signed main() {
    cin >> n >> w;
    for(int i = 0; i < n; ++i) cin >> a[i].first >> a[i].second;
    memset(dp, -1, sizeof(dp));
    cout << solve2(0, 0);
}
