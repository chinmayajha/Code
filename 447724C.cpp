#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    cin >> t;
    while (t--) {
        cout << fixed;
        cout << setprecision(7);
        int n, k; cin >> n >> k;
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i].first;
        for (int i = 0; i < n; ++i) cin >> a[i].second;
        sort(a.begin(), a.end(), [](pair<int, int>& x, pair<int, int>& y){
            return (x.second / (x.first * 1.0)) > ((y.second / (y.first * 1.0)));
        });

        long double cost = 0;
        for(int i = 0; i < n; ++i) {
            if(k <= 0) break;
            if(k >= a[i].first) {
                cost += a[i].second;
            } else cost += (k * (a[i].second / (a[i].first * 1.0)));
            k -= a[i].first;
        }
        cout << cost << "\n";
    }
}
