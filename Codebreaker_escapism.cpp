#include "bits/stdc++.h"
using namespace std;
#define int long long
signed main() {    
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    int n; cin >> n;
    int ans = 0;
    for(int i = 0, x; i < n; ++i) {
        cin >> x;
        ans += (x * (x + 1)) / 2;
        ans %= 1000000007;
    }
    cout << ans;
}
