#include "bits/stdc++.h"
using namespace std;
#define int long long

bool check(vector<int>& a, int c, int d, int mid) {
    // mid is k
    int sum = 0;
    for(int i = 0; i < d; ++i) {
        int ind = i % mid;
        if(ind < a.size()) sum += a[ind];
    }
    return sum >= c;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    cin >> t;
    while (t--) {
        int n, c, d; cin >> n >> c >> d;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        sort(a.rbegin(), a.rend());

        int left = 0, right = d + 2;
        while(left < right) {
            int mid = left + ((right - left + 1) >> 1);
            if(check(a, c, d, mid)) left = mid;
            else right = mid - 1;
        }
        
        if(left == d + 2) cout << "Infinity";
        else if(left == 0) cout << "Impossible";
        else cout << left - 1;

        cout << "\n";
    }
}
