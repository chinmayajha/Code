
#include "bits/stdc++.h"
#pragma GCC optimize "trapv"
using i64 = long long int;
using namespace std;
int nxt(){int x; cin >> x; return x;}
#define sz(x) ((int)(x).size()) 
#define all(x) (x).begin(), (x).end()
#define inarr(a,n) for(int i = 0; i < n; ++i) cin >> a[i];
//
bool check(string str1, string str2, int m, int n)
{
    int j = 0;
    for (int i = 0; i < n && j < m; i++)
        if (str1[j] == str2[i]) j++;
    return (j == m);
}
void solve(){
    int n;cin >> n;
    vector<string> a(n);
    inarr(a,n);
    string s(7,'a');
    inarr(s,7);
    sort(all(s));
    i64 mx = 0;
    for(auto& i : a){
        sort(all(i));
        if(sz(i) > sz(s)) continue;
        if(check(i,s,sz(i),sz(s))) mx = max(mx,(sz(i) > 3 ? 2*sz(i)*1ll : sz(i)*1ll));
    }
    cout << mx;

}
// AAN
// AAIMR
// EGILMU
// ACMOR
// s = AAEIMMR
int main(){
    cin.tie(nullptr);cout.tie(nullptr);ios::sync_with_stdio(false);
    int testt = 1;
    // cin >> testt;
    for (int i = 0; i < testt; ++i) {
        // cout << "Case #" << i << ": ";
        solve();
    }
}
