
#include "bits/stdc++.h"
#pragma GCC optimize "trapv"
using i64 = long long int;
using namespace std;
int nxt(){int x; cin >> x; return x;}
#define sz(x) ((int)(x).size()) 
#define all(x) (x).begin(), (x).end()
#define inarr(a,n) for(int i = 0; i < n; ++i) cin >> a[i];
//
i64 n, cnt;
string s,t;
map<pair<string,string>, int> a;
void solve(){
    cin >> n;
    for(int i = 0;i < n; ++i){
        cin >> s >> t;
        s = s.substr(0, 2);
        if(s != t) a[make_pair(s, t)]++;
    }
    for(auto& i : a) {
        cnt += a[make_pair(i.first.second, i.first.first)]*i.second;
    }
    cout << cnt/2;
}

int main(){
    cin.tie(nullptr);cout.tie(nullptr);ios::sync_with_stdio(false);
    int testt = 1;
    freopen("citystate.in", "r", stdin);
    freopen("citystate.out", "w", stdout);
    // cin >> testt;
    for (int i = 1; i <= testt; ++i){
        // cout << "Case #" << i << ": ";
        solve();
    }
}


