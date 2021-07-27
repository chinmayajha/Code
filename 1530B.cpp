
#include "bits/stdc++.h"
using i64 = long long int;
using namespace std;
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define inarr(a,n) for(int i = 0; i < n; ++i) cin >> a[i];
#ifndef ONLINE_JUDGE
    #define db(x) cerr << #x <<" = " << x << "\n";
#else
    #define db(...)
#endif
//
void solve(){
    int n,m;cin >> n >> m;
    //first row
    for(int i=0;i<m;++i)cout << 1 - (i%2);
    cout << "\n";
    for(int i=1;i<n-1;++i){
        if(i%2==1)for(int k=0;k<m;++k)cout<<0;
        else {
            cout << 1;for(int k=0;k<m-2;++k)cout<<0;cout << 1;
        }
        cout << "\n";
    }
    if(n&1)for(int i=0;i<m;++i)cout << 1 - (i%2);
    else for(int i=0;i<m;++i) cout << ((i<=1 || i>=m-2) ? 0 : 1-(i%2));
    
    cout << "\n\n";

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
