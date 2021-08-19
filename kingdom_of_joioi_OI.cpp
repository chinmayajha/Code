
#include "bits/stdc++.h"
#pragma GCC optimize "trapv"
using i64 = long long int;
using namespace std;
int nxt(){int x; cin >> x; return x;}
#define sz(x) ((int)(x).size()) 
#define all(x) (x).begin(), (x).end()
#define inarr(a,n) for(int i = 0; i < n; ++i) cin >> a[i];
#define int long long

int n,m,a[2005][2005],mx = 0, mn = INT_MAX;
    
void fliprow() {
    for(int i = 1; i <= n / 2; i++) {
        for(int j = 1; j <= m; j++) {
            swap(a[i][j], a[n - i + 1][j]);
        }
    }
}
    
void flipcol() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m / 2; j++) {
            swap(a[i][j], a[i][m - j + 1]);
        }
    }
}

bool check(int mid){
    int mxrow = n;
    for(int j = 1; j <= m; ++j) {
        for(int i = 1; i <= mxrow; ++i) {
            if(mx - a[i][j] > mid) {
                mxrow = i - 1;
                break;
            }
        }
        for(int i = mxrow + 1; i<= n; ++i) {
            if(a[i][j] - mn > mid) {
                return 0;
            }
        }
    }
    return 1;
}

int find(){
    int l = 0, r = mx - mn, ans = r;
    while(l <= r){
        int mid = (l + r)/2;
        if(check(mid)){
            r = mid - 1;
            ans = min(ans, mid);
        } else l = mid + 1;
    }
    return ans;
}

void solve(){
    cin >> n >> m;
    for(int i=1;i<n+1;++i) for(int j=1;j<m+1;++j) {
        cin >> a[i][j];
        mn = min(mn, a[i][j]);
        mx = max(mx ,a[i][j]);
    }
    int ans = find();
    flipcol();
    ans = min(ans, find());
    fliprow();
    ans = min(ans, find());
    flipcol();
    ans = min(ans, find());
    cout << ans;
}



signed main(){
    cin.tie(nullptr);cout.tie(nullptr);ios::sync_with_stdio(false);
    int testt = 1;
    // cin >> testt;
    for (int i = 0; i < testt; ++i) {
        // cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
