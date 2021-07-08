
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
    int n,h,temp;string s;
    cin >> n >> h;
    cin >> s;
    int cnt = 0;
    for(int i=0;i<n;++i){
        cnt += (s[i]=='0');
        if(s[i]!='0'){
            temp = 2*(h-cnt);
            h = min(h,temp);
            cnt = 0;
        }
    }
    temp = 2*(h-cnt);
    cnt = 0;
    h = min(h,temp);
    
    cout << (h<=0 ? "YES\n" : "NO\n");
    
    
}
int main(){
    cin.tie(nullptr);cout.tie(nullptr);ios::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}