#include "bits/stdc++.h"
using namespace std;

signed main() {
    int t = 1; cin >> t;
    while (t--) {
        int n; cin >> n;
        if(n % 2) {
            for(int i = 0; i < n; ++i) cout << 2 << " ";
        } else {
            cout << 1 << " " << 3 << " "; 
            for(int i = 0; i < n - 2; ++i) cout << 2 << " ";
        }
        cout << "\n";
    }
}
