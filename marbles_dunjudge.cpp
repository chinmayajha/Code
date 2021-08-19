#include "bits/stdc++.h"
#pragma GCC optimize "trapv"
using i64 = long long int;
using namespace std;
int nxt(){int x; cin >> x; return x;}
#define sz(x) ((int)(x).size()) 
#define all(x) (x).begin(), (x).end()
#define inarr(a,n) for(int i = 0; i < n; ++i) cin >> a[i];
//
i64 n,m,a[1000005];

bool check(i64 mid){
    i64 cnt = 0, sum = 0;
    for(i64 i=0;i<n;++i){
        if(a[i] > mid) return 0;
        if(sum + a[i] > mid) {
            cnt++;
            sum = a[i];
        } else sum += a[i];
    }
    return (cnt < m);
}

void solve(){
    cin >> n >> m; inarr(a,n);
    i64 l = 0, r = 1000*1000*1000;
    i64 ans = r;
    while(l <= r){
        i64 mid = (l+r)/2;
        if(check(mid)){
            r = mid - 1;
            ans = min(ans,mid);
        } else l = mid + 1;
    }
    cout << ans;
}

int main(){
    cin.tie(nullptr);cout.tie(nullptr);ios::sync_with_stdio(false);
    int testt = 1;
    // cin >> testt;
    for (int i = 0; i < testt; ++i) {
        // cout << "Case #" << i << ": ";
        solve();
    }
}