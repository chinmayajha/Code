#include "bits/stdc++.h"
using namespace std;

signed main() {
    int T = 1; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        
        // find minimum -> at i. if i+1...n is sorted, yes else -1
        int mini = (min_element(a.begin(), a.end()) - a.begin());
        cout << (is_sorted(a.begin() + mini + 1, a.end()) ? mini : -1) << "\n";
    }
}
