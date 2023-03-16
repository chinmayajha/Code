#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int t; cin >> t;
    while(t--) {
        int n, zeros = 0, ones = 0; cin >> n;
        for(int i = 0, x; i < n; ++i) {
            cin >> x;
            zeros += (1 - x);
            ones += x;
        }
        // cout << zeros << " " << 
        if(n % 2 != 0 || zeros == 0 || ones == 0) {
            cout << "-1\n";
            continue;
        }
        
        // first convert len(ones) <= len(zeros)
        // then increase ones 1 by 1
        
        cout << ones << " " << zeros << " -> ";
        int diff = max(0ll, ones - zeros);
        int ans = (diff + 3) / 4;
        
        if(ones >= zeros) cout << ans + (diff % 4 != 0) << "\n";
        else cout << (zeros - ones) / 2 << "\n";
        
    }
	return 0;
}

// 0 1 -> zeros -= 1, ones += 1
// 1 1 -> zeroes += 2, ones -= 2