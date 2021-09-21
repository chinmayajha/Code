
#include "bits/stdc++.h"
#pragma GCC optimize "trapv"
using i64 = long long int;
using namespace std;
int nxt(){int x; cin >> x; return x;}
#define sz(x) ((int)(x).size()) 
#define all(x) (x).begin(), (x).end()
#define inarr(a,n) for(int i = 0; i < n; ++i) cin >> a[i];
//
#ifndef ONLINE_JUDGE
    #include "debug.hpp"
#else
    #define print(...)
    #define debug(...)
#endif
void solve(){
	int n; cin >> n;
    string s; cin >> s;
    set<int> baaki;
    for(int i = 0;i < n; ++i) baaki.insert(i);
    char a[n][n];
    for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) a[i][j] = 'X';
    for(int i = 0; i < n; ++i) {
        if(s[i] == '1') {
            baaki.erase(i);
            for(int j = 0; j < n; ++j) {
                a[i][j] = '=';
                a[j][i] = '=';
            }
        }
    }
    if(sz(baaki) <= 2 && sz(baaki) != 0) {
        cout << "NO\n";
        return;
    } else cout << "YES\n";
    vector<int> baki(all(baaki));
    for(int i = 0; i < sz(baki); ++i) {
        a[baki[i]][baki[(i + 1) % sz(baki)]] = '+';
        a[baki[(i + 1) % sz(baki)]][baki[i]] = '-';
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) cout << (i == j ? 'X' : (a[i][j] == 'X' ? '=' : a[i][j]));
        cout << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int testt = 1;
    cin >> testt;
    for (int i = 1; i <= testt; ++i){
        // cout << "Case #" << i << ": ";
        solve();
    }
}
