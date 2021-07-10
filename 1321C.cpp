
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
    int n;cin >> n;
    string s,t;cin >> s;t=s;
    while(true){
        int mx = -1, mi = -1;
        for(int i=0;i<sz(s);++i){
            if(i>0 && s[i]-s[i-1]==1 && (s[i]-'a') > mx){mx = s[i]-'a'; mi = i;}
            else if(i<sz(s) && s[i]-s[i+1]==1 && (s[i]-'a') > mx){mx = s[i]-'a'; mi = i;}
        }
        if(mx == -1)break;
        s.erase(s.begin() + mi);
    }
    cout << n - sz(s);

}
int main(){
    cin.tie(nullptr);cout.tie(nullptr);ios::sync_with_stdio(false);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}