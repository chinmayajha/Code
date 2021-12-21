
#include "bits/stdc++.h"
using namespace std;

set<int> a;
void solve() {
    int n; cin >> n;
    cout << distance(a.begin(), a.upper_bound(n)) << "\n";
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int testt = 1;
    cin >> testt;
    for(int i = 1; i*i <= int(1e9 + 7); ++i) {
        a.insert(i*i);
    } 
    for(int i = 1; i*i*i <= int(1e9 + 7); ++i) {
        a.insert(i*i*i);
    }
    
    for (int i = 1; i <= testt; ++i) {
        solve();
    }
}
