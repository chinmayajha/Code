#include "bits/stdc++.h"
using namespace std;
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); // for shuffle(..., ..., rng)
int rnd(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int T = 1;
    // cin >> T;
    while (T--) {
        // int n, m; cin >> n >> m;
        // cout << max(n, m) << "\n";

        map<char, char> mp; 
        set<int> s;

        for(int i = 0; i < 26; ++i) {
            int choice = rnd(0, 25);

            while(s.find(choice) != s.end()) choice = rnd(0, 25);
            s.insert(choice);
            mp[char(i + 'a')] = char(choice + 'a');
        }

        for(auto& i : mp) {
            cout << i.first << ", " << i.second << endl;
        }
    }
}