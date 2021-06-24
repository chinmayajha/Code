
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
    int n,m; cin >> n >> m;
    vector<string> a(n);
    inarr(a,n);
    int cnt = 0;
    int x = 1000;
    while(x--){
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(a[i][j] == '>'){
                    if(j < m-1 && a[i][j+1] == '<'){
                        cnt++;
                        swap(a[i][j],a[i][j+1]);
                    }
                }
                if(a[i][j] == '<'){
                    if(j > 0 && a[i][j-1] == '>'){
                        cnt++;
                        swap(a[i][j],a[i][j-1]);
                    }
                }
                if(a[i][j] == 'v'){
                    if(i < n-1 && a[i+1][j] == '^'){
                        cnt++;
                        swap(a[i][j],a[i+1][j]);
                    }
                }
                if(a[i][j] == '^'){
                    if(i > 0 && a[i-1][j] == 'v'){
                        cnt++;
                        swap(a[i][j],a[i-1][j]);
                    }
                }
            }
        }
    }
    cout << cnt << "\n";
}
int main(){
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}