
#include "bits/stdc++.h"
#pragma GCC optimize "trapv"
using i64 = long long int;
using namespace std;
int nxt(){int x; cin >> x; return x;}
#define sz(x) ((int)(x).size()) 
#define all(x) (x).begin(), (x).end()
#define inarr(a,n) for(int i = 0; i < n; ++i) cin >> a[i];
//
void solve(){
    int n;
    cin >> n;
    n -= (n%2);
    int res = 0;
    vector<int> a(n);
    generate_n(a.begin(), n, nxt);
    int ans = 0, ans2 = 0;
    for(int i = 0; i < n; i += 2) {
        ans = 0, ans2 = 0;
        for(int j = i + 1; j < n; j += 2) {
            if(a[i] + ans2 < 0) break;
            int l = max(0, ans - ans2);
            int r = min(a[j], ans + a[i]);

            res += max(0, r - l + 1);
            ans2 = min(ans2, ans - a[j]);
            ans += a[j+1] - a[j];
        }
    }
    cout << res - n/2;

}

int main(){
    cin.tie(nullptr);cout.tie(nullptr);ios::sync_with_stdio(false);
    int testt = 1;
    // cin >> testt;
    for (int i = 1; i <= testt; ++i){
        // cout << "Case #" << i << ": ";
        solve();
    }
}

