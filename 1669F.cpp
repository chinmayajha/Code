#include "bits/stdc++.h"
using namespace std;

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) { cin >> a[i]; }\
        auto b = a;
        for(int i = 1; i < n; ++i) a[i] += a[i - 1];
        for(int i = n - 2; i >= 0; --i) b[i] += b[i + 1];
        
        int ans = 0;
        int i = 0, j = n - 1;
        while(i < j && i < n && j >= 0) {
            if(a[i] == b[j]) {
                ans = (i + 1) + (n - j);
                i++; j--;
            }
            if(i < n && j >= 0) if(a[i] < b[j]) i++; 
            if(i < n && j >= 0) if(b[j] < a[i]) j--;
        }
        cout << ans << "\n";
    }
}
