#include "bits/stdc++.h"
using namespace std;
#define int long long

int n, m, l, r; 
vector<int> a, seg;
 
int build(int ind, int l, int r) {
    if(l == r) return seg[ind] = a[l] % m;
    
    int left = build(2 * ind + 1, l, (l + r) / 2) % m,
    right = build(2 * ind + 2, (l + r) / 2 + 1, r) % m;

    return seg[ind] = (left * right) % m;
}
 
int query(int ind, int low, int high, int l, int r) {
    if(low >= l && high <= r) return seg[ind];
    if(low > r || high < l) return 1;
 
    int left = query(2 * ind + 1, low, (low + high) / 2, l, r) % m,
    right = query(2 * ind + 2, (low + high) / 2 + 1, high, l, r) % m;

    return (left * right) % m;
}

signed main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); // for shuffle(..., ..., rng)
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int T = 1;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        a.resize(n + 1);
        seg.resize(4 * n + 4);

        for (int i = 0; i < n; ++i) cin >> a[i];
        build(0, 0, n - 1);

        string s; cin >> s;
        int l = 0, r = n - 1;
        for(int k = 0; k < n; ++k) {
            cout << query(0, 0, n - 1, l, r) << " ";
            if(s[k] == 'L') l++;
            else r--;
        }

        cout << "\n";
    }
}

