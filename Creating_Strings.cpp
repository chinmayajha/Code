#include "bits/stdc++.h"
using namespace std;

signed main() {
    string s; cin >> s;
    vector<string> ans;
    
    sort(s.begin(), s.end());
    do {ans.push_back(s);}
    while (next_permutation(s.begin(), s.end()));

    cout << ans.size() << "\n";
    for(auto& i : ans) cout << i << "\n";
}
