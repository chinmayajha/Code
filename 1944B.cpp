#include "bits/stdc++.h"
using namespace std;
// #define int long long

signed main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); // for shuffle(..., ..., rng)
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int T = 1;
    cin >> T;
    while (T--) {
        int n, k; cin >> n >> k; 
        vector<int> a(n), b(n), freq(n + 1, 0);
        for(int i = 0; i < n; ++i) cin >> a[i], freq[a[i]]++;;
        for(int i = 0; i < n; ++i) cin >> b[i];
        
        vector<int> x, y;

        // Adding all elements to x/y with freq = 2 (in either A or B)
        for(int i = 1; i <= n; ++i) {
            if(freq[i] == 0 && y.size() < 2 * k) {
                // i is not in A, but in B
                y.push_back(i);
                y.push_back(i);
            } else if(freq[i] == 2 && x.size() < 2 * k) {
                // i is in A, not in B
                x.push_back(i);
                x.push_back(i);
            }
        }
        assert(x.size() == y.size());

        // Adding remaining elements, freq = 1
        int req = 2 * k - (int) x.size();
        for(int i = 1; i <= n && req > 0; ++i) {
            if(freq[i] == 1) {
                x.push_back(i);
                y.push_back(i);
                req--;
            }
        }

        for(auto& i : x) cout << i << " ";
        cout << "\n";
        for(auto& i : y) cout << i << " ";
        cout << "\n";
    }
}

