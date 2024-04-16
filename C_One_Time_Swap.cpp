#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    string s; cin >> s;
    map<char, int> mp;

    int cnt = 0;
    for(int i = 0; i < s.size(); ++i) {
        mp[s[i]]++;
        cnt += (i + 1) - mp[s[i]];
    }

    cnt += (mp.size() != s.size());
    cout << cnt;
}

