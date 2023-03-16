#include "bits/stdc++.h"
using namespace std;
// #define int long long

signed main() {
    int l, w, n, r; cin >> l >> w >> n >> r;
    vector<pair<int, int>> ranges(n);
    for(int i = 0; i < n; ++i) cin >> ranges[i].first >> ranges[i].second;

    for(int i = 0, y; i < n; ++i) {
        y = ranges[i].second;
        ranges[i].first = max(0, y - r), ranges[i].second = min(w, y + r);
    }
    sort(ranges.begin(), ranges.end());
    for(auto& i : ranges) {cout << i << " ";} cout << "\n";
    
    int count = 
}
