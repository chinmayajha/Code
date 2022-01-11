#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    int t; cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        if(n == 1 && m == 1) cout << "R\n";
        else if(m > (n + 1) / 2) cout << "-1\n";
        else {
            vector<string> a(n, string(n, '.'));
            int k = 0;
            for(int i = 0; i < n; i += 2) {
                a[k][i] = 'R';
                k += 2;
                k %= n;
                m--;
                if(m == 0) break;
            }
            for(int i = 0; i < n; ++i) cout << a[i] << "\n";
        }
    }
}
