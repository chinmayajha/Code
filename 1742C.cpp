#include "bits/stdc++.h"
using namespace std;

signed main() {
    int t; cin >> t;
    while(t--) {
        vector<string> a(8), b(8);
        char ans = 'R';
        for(int i = 0; i < 8; ++i) cin >> a[i];
        b = a;
        for(int i = 0; i < 8; ++i) for(int j = 0; j < 8; ++j) b[j][i] = a[i][j];

        for(int i = 0; i < 8; ++i) {
            if(b[i] == "BBBBBBBB") {
                ans = 'B';
                break;
            }
        }

        cout << ans << "\n";
    }
}
