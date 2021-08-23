
#include "bits/stdc++.h"
#pragma GCC optimize "trapv"
using i64 = long long int;
using namespace std;
int nxt(){int x; cin >> x; return x;}
#define sz(x) ((int)(x).size()) 
#define all(x) (x).begin(), (x).end()
#define inarr(a,n) for(int i = 0; i < n; ++i) cin >> a[i];
//
void solve(){
    int n; cin >> n;
    string s,t; cin >> s >> t;
    int onezero = 0, zerozero = 0, oneone = 0, zeroone = 0;
    for(int i=0;i<n;++i){
        oneone += (s[i] == '1' && t[i] == '1');
        zerozero += (s[i] == '0' && t[i] == '0');
        onezero += (s[i] == '1' && t[i] == '0');
        zeroone += (s[i] == '0' && t[i] == '1');
    }
    int x = min(zeroone, onezero);
    int y = min(oneone, zerozero);
    int cnt = x + y;
    zeroone -= x; onezero -= x;
    oneone -= y; zerozero -= y;
    int temp = zeroone + onezero;
    int z = min(oneone, temp);
    cnt += z;
    oneone -= z; temp -= z;
    cnt += (oneone/2);
       
    cout << cnt << '\n';
}

int main(){
    cin.tie(nullptr);cout.tie(nullptr);ios::sync_with_stdio(false);
    int testt = 1;
    cin >> testt;
    for (int i = 1; i <= testt; ++i){
        solve();
    }
}


