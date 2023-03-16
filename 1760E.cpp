#include "bits/stdc++.h"
using namespace std;
#define int long long

int f(vector<int>& a) {
    vector<int> arr((int) a.size(), 0); // number of ones on the left for each index
    for(int i = 0; i < a.size(); ++i) {
        if(i) arr[i] = arr[i - 1];
        if(a[i] == 1) arr[i] += 1;
    }
    int ans = 0;
    for(int i = 0; i < a.size(); ++i) if(a[i] == 0) ans += arr[i];
    return ans;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        // leftmost 0 to be flipped
        // rightmost 1 to be flipped 
        // don't flip -> output max
        int ans = f(a);
        for(int i = 0; i < n; ++i) {
            if(a[i] == 0) {
                a[i] = 1;
                ans = max(ans, f(a));
                a[i] = 0;
                break;
            }
        }
        for(int i = n - 1; i >= 0; --i) {
            if(a[i] == 1) {
                a[i] = 0;
                ans = max(ans, f(a));
                a[i] = 1;
                break;
            }
        }
        cout << ans << "\n";
    }
}
