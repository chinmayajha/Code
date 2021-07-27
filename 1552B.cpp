
#include "bits/stdc++.h"
using i64 = long long int;
using namespace std;
int nxt(){int x; cin >> x; return x;}
#define sz(x) ((int)(x).size()) 
#define all(x) (x).begin(), (x).end()
#define inarr(a,n) for(int i = 0; i < n; ++i) cin >> a[i];
//

bool check(i64 a[],i64 b[]){
    int cnt = 0;
    for(int i=0;i<5;++i)cnt += (a[i] < b[i]);
    return (cnt >= 3);
}

void solve(){
    int n;cin >> n;
    i64 a[n][5];
    i64 cnt = 0;
    for(int i=0;i<n;++i){
        for(int j=0;j<5;++j)cin >> a[i][j];
        if(i)if(check(a[i],a[cnt])) cnt = i;
    }
    if(n == 1){
        cout << "1\n";
        return;
    }
    for(int i=0;i<n;++i){
        if(cnt == i)continue;
        if(check(a[cnt],a[i])) continue;
        cout << "-1\n";
        return;
    }
    cout << cnt+1 << "\n";
    
}

int main(){
    cin.tie(nullptr);cout.tie(nullptr);ios::sync_with_stdio(false);
    int testt = 1;
    cin >> testt;
    for (int i = 0; i < testt; ++i) {
        // cout << "Case #" << i << ": ";
        solve();
    }
}
