
#include "bits/stdc++.h"
using lli = long long int;
using namespace std;
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define inarr(a,n) for(int i = 0; i < n; ++i) cin >> a[i];

#ifndef ONLINE_JUDGE
    #define db(x) cerr << #x <<" = " << n << "\n";
#else
    #define db(...)
#endif
//

void solve(){
    int n; 
    cin >> n;
    vector<lli> a(int(5e5+10),0);
    vector<lli> index(int(5e5+10),0);
    for(int i = 1;i<n+1;++i){
        cin >> a[i];
        index[a[i]] = i;
    }
    lli cnt = 0;
    for(int i = 1 ;i<=4*n;++i)for(int j=1;j<=(4*n)/i;++j){
        if(index[i]&&index[j]){
            cnt += (i!=j && i*j == index[i]+index[j]);
        }
    }
    cout << cnt/2 << "\n";
}
int main(){
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}
