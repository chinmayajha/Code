#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(2 * n);
        for (int i = 0; i < 2 * n; ++i) cin >> a[i];
        sort(a.begin(), a.end());

        int average = accumulate(a.begin(), a.end(), 0LL);
        bool check = 1;
        for(auto& i : a) i *= n;
        for(auto& i : a) {
            if(!binary_search(a.begin(), a.end(), average - i)) {
                check = 0;
                break;
            }
        }
        
        cout << (check ? "PERFECT" : "IMBALANCED") << "\n";
    }
}
