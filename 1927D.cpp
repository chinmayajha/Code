#include "bits/stdc++.h"
using namespace std;

int n, q, x, y; 
vector<int> a, seg_min, seg_max;
 
int build_min(int ind, int l, int r) {
    if(l == r) return seg_min[ind] = l;

    int g = build_min(2 * ind + 1, l, (l + r) / 2);
    int h = build_min(2 * ind + 2, (l + r) / 2 + 1, r);

    return seg_min[ind] = (a[g] < a[h] ? g : h);
}
 
int query_min(int ind, int low, int high, int l, int r) {
    if(low >= l && high <= r) return seg_min[ind];
    if(low > r || high < l) return INT_MAX;
 
    int g = query_min(2 * ind + 1, low, (low + high) / 2, l, r);
    int h = query_min(2 * ind + 2, (low + high) / 2 + 1, high, l, r);

    if(g == INT_MAX) return h;
    if(h == INT_MAX) return g;

    return (a[g] < a[h] ? g : h);
}

int build_max(int ind, int l, int r) {
    if(l == r) return seg_max[ind] = l;

    int g = build_max(2 * ind + 1, l, (l + r) / 2);
    int h = build_max(2 * ind + 2, (l + r) / 2 + 1, r);

    return seg_max[ind] = (a[g] > a[h] ? g : h);
}
 
int query_max(int ind, int low, int high, int l, int r) {
    if(low >= l && high <= r) return seg_max[ind];
    if(low > r || high < l) return INT_MIN;
 
    int g = query_max(2 * ind + 1, low, (low + high) / 2, l, r);
    int h = query_max(2 * ind + 2, (low + high) / 2 + 1, high, l, r);
    
    if(g == INT_MIN) return h;
    if(h == INT_MIN) return g;
    
    return (a[g] > a[h] ? g : h);
}

signed main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); // for shuffle(..., ..., rng)
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int T = 1;
    cin >> T;
    while (T--) {
        // Maintain two segment trees, one for RANGE_MINIMUM and other for RANGE_MAXIMUM
        // find min max for each query, if min = max, no unique elements. else print accordingly
        // typical segtree involves using values, we need indices here so modify

        int n; cin >> n;    
        a.resize(n + 1);
        seg_min.resize(4 * n + 4); seg_max.resize(4 * n + 4);
        for (int i = 0; i < n; ++i) cin >> a[i];
        
        build_min(0, 0, n - 1);
        build_max(0, 0, n - 1);

        cin >> q;
        while(q--) {
            cin >> x >> y; x--; y--;
            int l = query_min(0, 0, n - 1, x, y), r = query_max(0, 0, n - 1, x, y);
            
            if(l == r) cout << "-1 -1\n";
            else cout << l + 1 << " " << r + 1 << "\n";
        }
        cout << "\n";
    }
}