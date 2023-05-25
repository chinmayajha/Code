#include "bits/stdc++.h"
using namespace std;
#define int long long
// #include "debug.hpp"

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        if(n == 1) cout << "1\n";
        else if(n % 2 != 0) cout << "-1\n";
        else {
            // Print N first
            // then all odd numbers decreasing order, and even increasing order, alternate
            vector<int> ans;
            ans.push_back(n);
            for(int i = 1; i <= n - 1; ++i) {
                if(i % 2) ans.push_back(n - i);
                else ans.push_back(i);
            }
            for(auto& i : ans) cout << i << " "; 
            cout << "\n";
        }
    }
}

// n = 5 didn't work
// 
// n = 4
// 4 3 2 1 works

// n = 8
// 8 7 2 5 4 3 6 1
// 8 15 17 22 26 29 35 36
// 0 7 1 6 2 5 3 4

// n = 6
// 6 5 2 3 4 1