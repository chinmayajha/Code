#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); // for shuffle(..., ..., rng)
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int T = 1;
    cin >> T;
    while (T--) {
        int n, target; cin >> n >> target;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        
        int l = 0, r = n, mid;
        while(r - l > 1) {
            mid = (l + r) / 2;
            if(a[mid] <= target) l = mid;
            else r = mid;
        }

        if(a[l] == target) cout << "0\n";
        else {
            for(int i = 0; i < n; ++i) 
                if(a[i] == target)
                    cout << "1\n" << i + 1 << " " << l + 1 << "\n";
        }
    }
}

