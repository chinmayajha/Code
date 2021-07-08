
#include "bits/stdc++.h"
using lli = long long int;
using namespace std;
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define inarr(a,n) for(int i = 0; i < n; ++i) cin >> a[i];

//

void solve(){
    
    lli n; cin >> n;
    lli cnt = 0, cur = 0;
    vector<lli> a(n);
    inarr(a,n);
    sort(all(a));
    for(int i = 0; i < n - 2; ++i){
        cur -= (a[i+2]*(i+1));
        cnt += a[i];
        cur += cnt;
    }
    cout << cur << "\n";
}
int main(){
    cin.tie(nullptr);cout.tie(nullptr);ios::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}