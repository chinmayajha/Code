#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tt = 1;
    cin >> tt;
    while (tt--) {
        string s; bool check = 0;
        cin >> s;
        for(int i = 0; i < (int) s.size(); ++i) {
            if(s[i] == 'M') {
                for(int j = i + 1; j < s.size(); ++j) {
                    if(s[j] == 'U') {
                        check = 1;
                        break;
                    }
                }
                if(check) break;
            }
        }
        cout << (check ? "Yes" : "No") << "\n";
    }
}
