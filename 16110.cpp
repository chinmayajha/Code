
#include "bits/stdc++.h"
using namespace std;
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#ifndef ONLINE_JUDGE
#include "debug.hpp"
#else
#define print(...)
#define dbg(...)
#endif

void solve(){
    string s; cin >> s;
    int n = sz(s);
    int check = 0; //checking any num is even or not
    for(int i = 0;i < n; ++i) {
        if(s[i] == '0' || s[i] == '2' || s[i] == '4' || s[i] == '6' || s[i] == '8') {
            check = 1;
            break;
        }
    }
    if(!check) {
        cout << -1;
    } else {
        if(s[n - 1] == '0' || s[n - 1] == '2' || s[n - 1] == '4' || s[n - 1] == '6' || s[n - 1] == '8') {
            cout << 0;
        } else if(s[0] == '0' || s[0] == '2' || s[0] == '4' || s[0] == '6' || s[0] == '8') {
            cout << 1;
        } else cout << 2;
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
