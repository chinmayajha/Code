#include "bits/stdc++.h"
using namespace std;
#define int long long

void solve() {
    int n; cin >> n;
    string s = ""; 
    
    for(char c = 'a'; c <= 'z'; ++c) 
        for(char d = 'a'; d <= 'z'; ++d) 
            for(char e = 'a'; e <= 'z'; ++e) {
                if((int) ((c - 'a') + (d - 'a') + (e - 'a')) + 3 == n) {
                    string temp = "";
                    temp.push_back(c);
                    temp.push_back(d);
                    temp.push_back(e);
                    sort(temp.begin(), temp.end());
                    cout << temp << "\n";
                    return;
                }
            }
    cout << "-1\n";

}

signed main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); // for shuffle(..., ..., rng)
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
}