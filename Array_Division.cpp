
#include "bits/stdc++.h"
#pragma GCC optimize "trapv"
using i64 = long long int;
using namespace std;
int nxt(){int x; cin >> x; return x;}
#define sz(x) ((int)(x).size()) 
#define all(x) (x).begin(), (x).end()
#define inarr(a,n) for(int i = 0; i < n; ++i) cin >> a[i];
//
i64 n,m,a[2000010];
bool check(i64 mid){
    i64 sum = 0, cnt = 1;   
    for(i64 i=0;i<n;++i){
        if(a[i] > mid) return 0;
        if(sum + a[i] > mid){
            cnt++;
            sum = a[i];
        } else sum += a[i];
    }
    return (cnt <= m);
}
void solve(){
    cin >> n >> m; 
    i64 l = 1,r = 0;
    for(i64 i=0;i<n;++i){
        cin >> a[i];
        r += a[i];
        l = max(l,a[i]);
    }
    while(l <= r) {
        i64 mid = l + (r - l) / 2;
        if(check(mid)) {
            r = mid - 1;
        } else l = mid + 1;
    }
    cout << l;
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


