#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); // for shuffle(..., ..., rng)
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int T = 1;
    cin >> T;
    while (T--) {
        // till s and t have only 'a', do basic comparison
        // if s has non-a, always NO - check1
        // as soon as t has non-a, always YES - check2

        int q, st, k, check1 = 0, check2 = 0, cntas = 1, cntat = 1; cin >> q;
        while(q--) {
            cin >> st >> k;
            string s; cin >> s;

            for(auto& i : s) {
                if(i != 'a') {
                    if(st == 1) check1 = 1; 
                    else check2 = 1;
                } else {
                    if(st == 1) cntas += k;
                    else cntat += k;
                }
            }

            if(check2) {
                // checking if any non-a element is in t, then answer is always YES afterwards
                cout << "YES\n";
            } else if(check1) {
                // checking if any non-a element is in s, then answer is NO for some time till check2  
                cout << "NO\n";
            } else {
                // only a in both, basic comparison
                if(cntas < cntat) cout << "YES\n";
                else cout << "NO\n";
            }
        }
    }
}
