
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
    bool chk = 1;
    string s; cin >> s;
    for(int i = 0;i < n - 1; ++i) {
        if(s[i] == '1' && s[i+1] == '0') {
            chk = 0;
            break;
        }
    }
    if(chk || n == 1) {
        cout << s << "\n";
        return;
    }
    //
    int i = 0, j = n - 1;
    cout << "0";
    while(i < n) {
        if(s[i] == '0') cout << '0';
        else break;
        i++;
    }
    while(j >= 0) {
        if(s[j] == '1') cout << '1';
        else break;
        j--;
    }
    cout << "\n";
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

