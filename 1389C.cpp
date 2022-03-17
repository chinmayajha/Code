#include "bits/stdc++.h"
using namespace std;

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1; cin >> t; while (t--) {
        string s; cin >> s;
        int n = (int) s.size();
        if(n <= 2) {cout << "0\n"; continue;}

        int ans = 0;
        for(char c = '0'; c <= '9'; ++c) for(char d = '0'; d <= '9'; ++d) {
            int temp = 0, check = 0;
            for(auto& i : s) if((check && (i == c)) || (!check && (i == d))) {
                temp++;
                check = 1 - check;
            }
            temp -= bool(temp % 2 && c != d);
            ans = max(ans, temp);
        }
        
        cout << n - ans << "\n";
    }
}
