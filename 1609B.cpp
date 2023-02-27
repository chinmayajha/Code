#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    string s; int n, q, pos; char c; set<int> abc;
    cin >> n >> q; cin >> s;
    abc.insert(-1);
    for(int i = 0; i < (int) s.size() - 3; ++i) {
        if(s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c') abc.insert(i);
    }
    while(q--) {
        cin >> pos; cin >> c; pos -= 1;
        if(s[pos] != c) {
            s[pos] = c;
            auto left = (abc.upper_bound(pos)); left--;
            int pos2 = *left;
            if(pos2 != -1 && (pos - pos2) < 3) s.erase(pos2);
            if(pos2 >= 0 && pos2 + 2 < (int) s.size()) {
                if(s[pos2] == 'a' && s[pos2 + 1] == 'b' && s[pos2 + 2] == 'c') abc.insert(pos2);
            }
        }
        cout << -1 + (int) s.size() << "\n";
        // break;
    }
}
