#include "bits/stdc++.h"
using namespace std;

vector<string> split(string s, char c) {
    vector<string> a;
    string t = "";
    int n = s.size();
    for(int i = 0; i < n; ++i) {
        if(s[i] == c) {
            a.emplace_back(t);
            t = "";
        } else t.push_back(s[i]);
    }
    a.emplace_back(t);
    return a;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        string s, ans = "YES\n"; cin >> s;
        vector<string> a = split(s, 'W');
        for(auto& i : a) {
            bool rcheck = 0, bcheck = 0;
            for(auto& j : i) {
                if(j == 'R') rcheck = 1;
                if(j == 'B') bcheck = 1;
            }
            if((rcheck == 0 && bcheck != 0) || (bcheck == 0 && rcheck != 0)) {ans = "NO\n"; break;}
        }
        cout << ans;
    }
}
