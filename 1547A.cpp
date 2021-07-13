
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
    int x1,x2,y1,y2,f1,f2;cin >> x1 >> y1 >> x2 >> y2 >> f1 >> f2;
    int cnt = abs(x1-x2)+abs(y1-y2);
    if(x1 == x2 && x2 == f1){
        if(((y1 < f2  && f2 < y2) || (y2 < f2 && f2 < y1))){
            cnt += 2;
        }
    } else if(y1 == y2 && y2 == f2){
        if((x1 < f1  && f1 < x2) || (x2 < f1 && f1 < x1)){
            cnt += 2;
        }
    }
    cout << cnt << "\n";
}
int main(){
    cin.tie(nullptr);cout.tie(nullptr);ios::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}