#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); // for shuffle(..., ..., rng)
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int T = 1;
    cin >> T;
    while (T--) {
        int n, mx = 0; cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];

        int start = a[0], end = a.back();
        int i = 0, j = 0; 
        while(i < n && a[i] == start) i++;

        reverse(a.begin(), a.end());
        while(j < n && a[j] == end) j++;

        if(n == 2) {
            if(start == end) cout << "0";
            else cout << "1";
        } else if(i == n || j == n) {
            cout << "0";
        } else {
            if(start == end) {
                cout << n - i - j;
            } else cout << n - max(i, j);
        }
        cout << "\n";
    }
}