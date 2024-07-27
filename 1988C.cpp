// #include "debug.h"
#include "bits/stdc++.h"
using namespace std;
#define int unsigned long long

signed main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); // random seed for shuffle(..., ..., rng)
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int T = 1;
    cin >> T;
    while (T--) {
        int n; cin >> n;
        
        vector<int> a;
        a.push_back(n);

        for(int i = 0, t; i < 64; ++i) {
            if((1LL << i) & n) {
                t = (~(1LL << i)) & n;
                if(t != 0) a.push_back(t);
            }
        }

        reverse(a.begin(), a.end());
        cout << a.size() << "\n";
        for(auto &i : a) cout << i << " ";
        cout << "\n";
    }
}

