
#include "bits/stdc++.h"
#pragma GCC optimize "trapv"
using i64 = long long int;
using namespace std;
int nxt(){int x; cin >> x; return x;}
#define sz(x) ((int)(x).size()) 
#define all(x) (x).begin(), (x).end()
#define inarr(a,n) for(int i = 0; i < n; ++i) cin >> a[i];
//

void usaco(string name) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

int n,k,a[50010];

bool check(int mid){
    int cnt = 0, cur = a[0], end = a[0] + 2*mid;
    for(int i=0;i<n;++i){
        if(end >= a[i]) continue;
        cur = a[i];
        end = cur + 2*mid;
        cnt++;
    }
    return (cnt < k);
}
void solve(){
    cin >> n >> k;
    inarr(a,n);
    sort(a,a+n);
    i64 ans = 1000*10000ll;
    int l = 0, r = ans;
    while(l <= r){
        int mid = (l + r)/2;
        if(check(mid)) {
            r = mid - 1;
            ans = min(ans, mid*1ll);
        } else l = mid + 1;
    }
    cout << ans;
}

int main(){
    cin.tie(nullptr);cout.tie(nullptr);ios::sync_with_stdio(false);
    int testt = 1;
    // cin >> testt;
    usaco("angry");
    for (int i = 0; i < testt; ++i) {
        // cout << "Case #" << i << ": ";
        solve();
    }
}
