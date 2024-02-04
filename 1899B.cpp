#include "bits/stdc++.h"
using namespace std;
#define int long long

vector<int> factorise(int n) {
    vector<int> factors;
    for(int i = 1; i <= n; ++i) if(n % i == 0) factors.push_back(i);
    return factors;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int T = 1;
    cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n + 1, 0);
        for (int i = 1; i <= n; ++i) cin >> a[i], a[i] += a[i - 1];
        
        int mx = 0;
        vector<int> factors = factorise(n);

        for(auto& k : factors) {
            int curmx = -1e18, curmn = 1e18;
            for(int i = k; i <= n; i += k) {
                curmn = min(curmn, a[i] - a[i - k]);
                curmx = max(curmx, a[i] - a[i - k]);
            }
            mx = max(curmx - curmn, mx);
        }
        cout << mx << "\n";
    }
}
