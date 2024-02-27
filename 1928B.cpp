#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); // for shuffle(..., ..., rng)
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int T = 1;
    cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        int mn = *min_element(a.begin(), a.end());
        for(auto& i : a) i -= (mn - 1);
        
        shuffle(a.begin(), a.end(), rng); sort(a.begin(), a.end()); a.erase(unique(a.begin(), a.end()), a.end());
        
        int mx = 1; int i = 0, j = 1;

        while(j < a.size() && i < a.size()) {
            if(a[j] - a[i] <= n - 1) {
                mx = max(mx, j - i + 1);
                j++;
            } else {
                mx = max(mx, j - i);
                i++;
            }
        }
        cout << mx << "\n";
    }
}
