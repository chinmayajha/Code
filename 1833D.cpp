#include "bits/stdc++.h"
using namespace std;
#define int long long

void operate(vector<vector<int>>& b, vector<int>& a, int n, int l, int r) {
    vector<int> ret;
    for(int i = r + 1; i < n; ++i) ret.push_back(a[i]);
    for(int i = r; i >= l; --i) ret.push_back(a[i]);
    for(int i = 0; i < l; ++i) ret.push_back(a[i]);
    b.push_back(ret);
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        vector<vector<int>> b;
        for(int i = 0; i < n; ++i) 
            for(int j = i; j < n; ++j) 
                operate(b, a, n, i, j);
        
        sort(b.begin(), b.end());
        for(auto& i : b.back()) {cout << i << " ";} cout << "\n";
    }
}
