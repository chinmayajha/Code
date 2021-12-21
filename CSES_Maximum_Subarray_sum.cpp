// https://cses.fi/problemset/task/1643
#include "bits/stdc++.h"
using namespace std;

long long int dp[200010], a[200010], n;
int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) { cin >> a[i]; }
    dp[1] = a[1];
    for (int i = 2; i <= n; ++i) {
        dp[i] = max(a[i], dp[i - 1] + a[i]);
    }
    cout << *max_element(dp + 1, dp + n + 1);
}