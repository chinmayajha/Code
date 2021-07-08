
#include "bits/stdc++.h"
using i64 = long long int;
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
map<i64,i64> x,y;
map<pair<i64,i64>,i64> temp;
i64 n,a,b,cnt;
void solve(){
    cin >> n;
    for(i64 i=0;i<n;++i){
        cin >> a >> b;
        x[a]++;
        y[b]++;
        cnt -= temp[make_pair(a,b)];
        temp[make_pair(a,b)]++;
    }
    for(auto& i : x){
        if(i.second % 2 == 0){
            cnt += (i.second/2) * (i.second-1);
        }
        else {
            cnt += (i.second) * ((i.second - 1)/2);
        }
    }
    for(auto& i : y){
        if(i.second % 2 == 0){
            cnt += (i.second/2) * (i.second-1);
        }
        else {
            cnt += (i.second) * ((i.second - 1)/2);
        }
    }
    cout << cnt;

}
int main(){
    cin.tie(nullptr);cout.tie(nullptr);ios::sync_with_stdio(false);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}