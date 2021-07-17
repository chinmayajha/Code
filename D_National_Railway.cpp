
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
    i64 h,w,c;cin >> h >> w >> c;
    int a[h][w];
    for(int k=0;k<h;++k)inarr(a[k],w);
    i64 cnt = INT_MAX;
    for(int i=0;i<h;++i)for(int j=0;j<w;++j){ //first block
        for(int x=i;x<h;++x)for(int y=0;y<w;++y){
            if(i==x && j==y)continue;
            i64 temp = c*(abs(x-i)+abs(y-j));
            temp += (a[i][j]+a[x][y]);
            cnt = min(temp,cnt);
        }
    }
    cout << cnt;
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
