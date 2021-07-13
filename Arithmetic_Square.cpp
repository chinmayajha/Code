
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
i64 a[3][3];
void solve(){
    a[1][1] = -1;
    cin >> a[0][0] >> a[0][1] >> a[0][2];
    cin >> a[1][0] >> a[1][2];
    cin >> a[2][0] >> a[2][1] >> a[2][2];
    map<i64,i64> mp;
    //columns
    i64 cnt = (a[0][0] + a[0][2] == 2*a[0][1]);
    cnt += (a[2][0] + a[2][2] == 2*a[2][1]);
    cnt += (a[0][0] + a[2][0] == 2*a[1][0]);
    cnt += (a[0][2] + a[2][2] == 2*a[1][2]);
    ////////////////////////////////    

    //diagonals
    if((a[0][0]+a[2][2])%2==0) mp[(a[0][0]+a[2][2])/2]++;
    if((a[0][2]+a[2][0])%2==0) mp[(a[0][2]+a[2][0])/2]++;
    //horizontal
    if((a[1][0]+a[1][2])%2==0) mp[(a[1][0]+a[1][2])/2]++;
    //vertical
    if((a[0][1]+a[2][1])%2==0) mp[(a[0][1]+a[2][1])/2]++;
    //////////////////////////
    i64 mx = 0;
    for(auto i : mp)mx = max(mx, i.second);
    cout << mx + cnt<< "\n";
}
int main(){
    cin.tie(nullptr);cout.tie(nullptr);ios::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    for(int i=0;i<t;++i){
        cout << "Case #" << i+1 << ": ";
        solve();
    }
}