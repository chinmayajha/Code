
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
    int c,d;
    cin >> c >> d;
    if(c == 0 && d == 0) {
        cout << "0\n";
        return;
    }
    if(abs(c - d) % 2 == 1) {
        cout << "-1\n";
        return;
    }
    if(c == d) {
        cout << "1\n";
        return;
    }
    if((c == 0 && d != 0) || (d == 0 && c != 0)) {
        cout << "2\n";
        return;
    }
    cout << "2\n";
}

int main(){
    cin.tie(nullptr);cout.tie(nullptr);ios::sync_with_stdio(false);
    int testt = 1;
    cin >> testt;
    for (int i = 1; i <= testt; ++i){
        // cout << "Case #" << i << ": ";
        solve();
    }
}


