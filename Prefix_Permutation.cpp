#include "bits/stdc++.h"
using namespace std;
#define int long long
// #include "debug.hpp"

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        iota(a.begin(), a.end(), 1); 
        while(true) {
            int check = 1;
            vector<int> pref(n, 0);
            pref[0] = a[0];
            for(int i = 1; i < n; ++i) {
                pref[i] = a[i] + pref[i - 1];
                if(pref[i] % (i + 1) == 0) {
                    check = 0; 
                    break;
                }
            }
            if(!check) next_permutation(a.begin(), a.end());
            else {
                for(auto& i : a) {cout << i << " ";} cout << "\n";
                break;
            }
        }
    }
}

