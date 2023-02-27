#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        if(n == 1) cout << "Alice\n";
        else if(n == 2) cout << "Bob\n";
        else if(n == 3) cout << "Alice\n";
        else cout << (n % 2 ? "Bob\n" : "Alice\n");
    }
}
