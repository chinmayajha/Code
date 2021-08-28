
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
    int n; string s;
    cin >> n;cin >> s;
    int k = -1;
    for(int i = 0; i < n; ++i) k = (s[i] == '0' ? i : k); //checks for the last 0
    // cout << s << endl;
    if(k == -1) {
        cout << "1 " << n-1 << " 2 " << n << "\n";
        return;
    }
    k++;
    if(k > n/2) {
        cout << "1 " << k << " 1 " << k-1 << "\n";
        return;
    } else {
        cout << k << " " << n << " " << k + 1 << " " << n << "\n";
        return;
    }
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


