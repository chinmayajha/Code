#include "bits/stdc++.h"
using namespace std;
#define int long long

bool check(int k, vector<pair<int, int>> a) {
    int l = 0, r = 0;
    for(auto& [lb, rb] : a) {
        l = max(l - k, lb);
        r = min(r + k, rb);
        if(l > r) return false;
    }
    return true;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int T = 1;
    cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i].first >> a[i].second;
        
        int l = 0, r = INT_MAX, cnt = 40;
        while(cnt--) {
            int mid = (l + r) / 2;
            if(check(mid, a)) r = mid;
            else l = mid + 1;
        }
        cout << r << "\n";
    }
}
