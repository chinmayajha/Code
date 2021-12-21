#include "bits/stdc++.h"
using namespace std;
int main(){
    // freopen("div7.in", "r", stdin);
	// freopen("div7.out", "w", stdout);
    int64_t n; cin >> n;
    vector<int64_t> a(n), b(7, -1);
    for(auto& i : a) cin >> i;
    int64_t ans = 0;
    for(int64_t i = 0; i < n; ++i) {
        if(i) a[i] += a[i - 1];
        if(b[a[i] % 7] == -1) b[a[i] % 7] = i;
        else ans = max(ans, i - b[a[i] % 7]);
    }
    cout << ans;
}
