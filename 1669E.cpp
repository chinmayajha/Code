#include "bits/stdc++.h"
using namespace std;
#define int long long 
signed main() {
    int t = 1; cin >> t;
    while (t--) {
        int n, cnt = 0; cin >> n;
        vector<string> a(n);
        map<char, int> start, end;
        map<string, int> freq;
        for (int i = 0; i < n; ++i) cin >> a[i];
        
        for(auto& i : a) {
            start[i[0]] += 1; end[i[1]] += 1;
            freq[i] += 1;
            cnt += (start[i[0]] - freq[i]) + (end[i[1]] - freq[i]);
        }
        cout << cnt << "\n";
    }
}
