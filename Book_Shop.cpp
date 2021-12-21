
#include "bits/stdc++.h"
using namespace std;
#define int long long

int n, x;
vector<pair<int, int>> a(1005);
vector<vector<int>> dp(1005, vector<int>(100005, -1));
// price, pages

int solve2(int index, int sum) {
    if(index == n) return 0;
    if(dp[index][sum] != -1) return dp[index][sum];

    int ans; 
    if(sum + a[index].first <= x) {
        ans = max(solve2(index + 1, sum + a[index].first) + a[index].second, solve2(index + 1, sum));
    } else {
        ans = solve2(index + 1, sum);
    }
    return dp[index][sum] = ans;
}

signed main() {
    cin >> n >> x;
    for (int i = 0; i < n; ++i) cin >> a[i].first;
    for (int i = 0; i < n; ++i) cin >> a[i].second;
    
    cout << solve2(0, 0);
}
