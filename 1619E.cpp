
#include "bits/stdc++.h"
using namespace std;
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define int long long

#ifdef chinmayajha
#include "debug.hpp"
#else
#define print(...)
#define dbg(...)
#endif


void solve() {
    int n; cin >> n;
    vector<int> a(n), ans(n, -1);
    for (int i = 0; i < n; ++i) { cin >> a[i]; }
    sort(all(a));
    map<int, int? mp;
    for(auto& i : a) mp[i]++;
    // till max_ele answer is its frequency (where max ele belongs to contiguopus array) (1 2 3 and not 1 2 4)
    // max ele + 1 ans is 0
    // 


}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int testt = 1;
    // cin >> testt;
    for (int i = 1; i <= testt; ++i) {
        // cout << "Case #" << i << ": ";
        solve();
    }
}
